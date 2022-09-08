/**
 * @file leetcode_198.cpp
 * @author wangs7
 * @brief leetcode.198.打家劫舍I
 * @version 0.1
 * @date 2022-09-06
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <iostream>
#include <vector>

using namespace std;

vector<int> getInput(int N) {
    vector<int> res(N);
    for (int i=0; i<N; ++i) {
        cin >> res[i];
    }
    return res;
}

int rob(vector<int>& nums) {
    int n = nums.size();
    // 极端情况判断
    if (n == 0) 
        return 0;
    if (n == 1) 
        return nums[0];
    // 动态规划
    vector<int> dp(n+1, 0);
    dp[1] = nums[0];
    // 更新dp表
    for (int i=2; i<n+1; ++i) {
        dp[i] = max(dp[i-2] + nums[i-1], dp[i-1]);
    }
    return dp[n];
}


int main(int argc, const char** argv) {
    int N;
    cin >> N;
    vector<int> home = getInput(N);

    cout << rob(home) << endl;

    return 0;
}