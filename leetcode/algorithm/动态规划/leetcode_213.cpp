/**
 * @file leetcode_213.cpp
 * @author wangs7
 * @brief leetcode.213.打家劫舍II
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

/** 简单情况下的打家劫舍 **/
int rob_1(vector<int>& nums, int l, int r) {
    int n = r-l;
    if (n == 0) 
        return 0;
    if (n == 1) 
        return nums[l];
    vector<int> dp(n+1, 0);
    
    dp[1] = nums[l];
    for (int i=2; i<n+1; ++i) {
        dp[i] = max(dp[i-2] + nums[i-1+l], dp[i-1]);
    }
    return dp[n];
}

/** 首尾相接构成环路的情况 **/
int rob_2(vector<int>& nums) {
    if (nums.size() == 0)
        return 0;
    if (nums.size() == 1)
        return nums[0];

    //考虑不选第一个 和 不选最后一个 两种情况 取最大值 
    return max(rob_1(nums, 0, nums.size()-1), rob_1(nums, 1, nums.size()));
}


int main(int argc, const char** argv) {
    int N;
    cin >> N;
    vector<int> home = getInput(N);

    cout << rob_2(home) << endl;

    return 0;
}