/**
 * @file huawei_13.cpp
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

int handle(int n, vector<int>& s, vector<int>& v, vector<vector<int>> &p) {
    int maxRes = 0;
    int mask;
    // mask 存储选择情况
    for (mask = 1; mask < (1 << n); mask++) {   
        int res = 0;
        bool flag = true; // 是否终止
        vector<int> sn(3, 0);
        // 遍历位置 i 是否被选
        for (int i=0; flag && i<n; i++) {   
            if ((mask & (1 << i)) != 0) {
                for (int j=0; flag && j<3; j++) {
                    sn[j] += p[i][j];
                    if (sn[j] > s[j]) {
                        flag = false; // 超出数量终止循环
                    }
                }
                if (flag) {
                    res += v[i]; 
                }
                
            }
        }
        maxRes = max(maxRes, res);
    }
    return maxRes;
}

int main(int argc, char const *argv[])
{
    int n;
    vector<int> s(3, 0);
    cin >> n;
    cin >> s[0] >> s[1] >> s[2];
    vector<int> v(n, 0);
    vector<vector<int>> p(n, vector<int>(3, 0));

    for (int i=0; i<n; i++) {
        cin >> v[i];
    }
    for (int i=0; i<n; i++) {
        cin >> p[i][0] >> p[i][1] >> p[i][2];
    }
    
    cout << handle(n, s, v, p) << endl;
    return 0;
}
