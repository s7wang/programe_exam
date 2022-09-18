/**
 * @file huawei_11.cpp
 * @author wangs7
 * @brief 
 * @version 0.1
 * @date 2022-05-13
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <iostream>
#include <algorithm>
#include <vector>
#include <set>

using namespace std;
/* 10 的 x 次方 */
int pow10(int x) {
    if (x==0) {
        return 1;
    }
    int res = 1;
    for (int i=0; i<x; i++) {
        res *= 10;
    }
    return res;
}

/* 不同位的数量 */
int deferent(string& num_str,int b) {
    string b_str = to_string(b);
    int res = 0;
    for (int i=0; i<num_str.size(); i++) {
        if (num_str[i] != b_str[i]) {
            res++;
        }
    }
    return res;
}

/* 改变不同位 */
vector<vector<int>> change(string& num_str, int n) {
    vector<vector<int>> res(n+1);
    for (int i=pow10(n-1); i < pow10(n)-1; i++){
        res[deferent(num_str, i)].push_back(i);
    }
    return res;
}

/* 检测两组数的乘积是否在第三组中 */
bool check(vector<int> &a, vector<int> &b, vector<int> &c) {
    for (int i=0; i<a.size(); i++) {
        for (int j=0; j<b.size(); j++) {
            if (find(c.begin(), c.end(), a[i]*b[j]) != c.end()) {
                return true;
            }
        }
    }
    return false;
}

/* 计算函数 */
int handle(int a, int b, int c) {
    // 不用改直接返回
    if (a*b == c) {
        return 0;
    }
    string a_str = to_string(a);
    string b_str = to_string(b);
    string c_str = to_string(c);
    int an = a_str.length();
    int bn = b_str.length();
    int cn = c_str.length();
    // 位数冲突 直接返回-1
    if (cn < an+bn-1 || cn > an+bn) {
        return -1;
    }
    // 生产各种数可能发生的改变
    vector<vector<int>> av = change(a_str, an);
    vector<vector<int>> bv = change(b_str, bn);
    vector<vector<int>> cv = change(c_str, cn);
    int res = 1;
    // 总变化不超过所有数的位总和
    for (res = 1; res < an+bn+cn; res++) {
        int i, j, k;
        for (i=0; i<=an; i++) {
            for (j=0; j<bn; j++) {
                for (k=0; k<cn; k++) {
                    // 在变化符合条件的情况下 check
                    if (i+j+k == res && check(av[i], bv[j], cv[k])) {
                        // check成功直接返回
                        return res;
                    }
                }
            }
        }
    }
    // res == an+bn+cn情况不用看必能成功直接返回
    return res;
    
}

int main(int argc, char const *argv[])
{
    int T;
    cin >> T;
    char c1, c2;
    vector<vector<int>> nums(T, vector<int>(3, 0));
    for (int i=0; i<T; i++) {
        cin >> nums[i][0] >> c1 >> nums[i][1] >> c2 >> nums[i][2];
    }

    for (int i=0; i<T; i++) {
        cout << handle(nums[i][0], nums[i][1], nums[i][2]) << " ";
    }
    cout << endl;


    return 0;
}
