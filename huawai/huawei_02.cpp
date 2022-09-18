/**
 * @file huawei_02.cpp
 * @author wangs7
 * @brief huawei02 类似leetcode.629
 * @version 0.1
 * @date 2022-05-13
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <iostream>
#include <vector>
#include <queue>

using namespace std;
class Solution {
public:
    static int kInversePairs(int n, int k) {
        int mod = 1e9+7;
        // dp表
        vector<vector<int>> dp(n+1, vector<int>(k+1));
        dp[0][0] = 1; //初始化
        for (int i=1; i<=n; i++) {
            dp[i][0] = 1;
            for (int j=1; j<=k; j++) {
                // f[i][j] = f[i][j-1] + f[i-1][j] - f[i-1][j-i]；(这里默认f[*][<0] = 0)
                dp[i][j] = dp[i][j-1] + dp[i-1][j];
                if (j>=i) dp[i][j] -= dp[i-1][j-i];
                if (dp[i][j] >= mod) dp[i][j] %= mod;
                if (dp[i][j] < 0) dp[i][j] += mod;
            }
        }
        int res = 0;
        for (int i=0; i<=k; i++) {
            res = (res + dp[n][i]) % mod;
            cout << dp[n][i] << endl;
        }
        return res;
    }
};
int main(int argc, char const *argv[])
{
    int n, k;
    cin >> n >> k;
    cout << Solution::kInversePairs(n, k) << endl;   
    return 0;
}
