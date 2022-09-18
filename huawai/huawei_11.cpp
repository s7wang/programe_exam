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

vector<vector<int>> getInput(int m) {
    set<int> index;
    vector<vector<int>> res(m, vector<int>(3, 0));
    for (int i=0; i<m; i++) {
        cin >> res[i][0] >> res[i][1] >> res[i][2];
        index.insert(res[i][0]);
        index.insert(res[i][1]);
    }
    sort(res.begin(),res.end(), 
        [](const vector<int>& a,const vector<int>& b) {
            return a[2] < b[2];
            });

    return res;
}

int handle(vector<vector<int>>& p, int n) {
    int res = 0;
    // 扫描时间段
    for (int i=1; i<=n; i++) {
        for (int k=0; k<p.size(); k++) {
            if(i >= p[k][0] && i <= p[k][1]) {
                res += p[k][2];
                break;
            }
        }
    }
    return res;
}

int main(int argc, char const *argv[])
{
    int n, m;
    cin >> n >> m;

    return 0;
}
