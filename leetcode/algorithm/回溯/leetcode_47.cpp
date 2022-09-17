/**
 * @file leetcode_47.cpp
 * @author wangs7
 * @brief leetcode.47.全排列II
 * @version 0.1
 * @date 2022-09-17
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
vector<int> getInput(int N) {
    vector<int> res(N);
    for (int i=0; i<N; i++) {
        cin >> res[i];
    }
    return res;
}

void printRes(vector<vector<int>> &res) {
    for (int i=0; i<res.size(); i++) {
        if (res[i].size() == 0) 
            cout << "null";
        for (int j=0; j<res[i].size(); j++) {
            cout << res[i][j] << " ";
        }
        cout << endl;
    }
}
// ----------------------------------------
class Solution {
private:
    static void backtrack(vector<int>& nums, vector<vector<int>>& ans, int idx, vector<int>& perm, vector<int>& vis) {
        if (idx == nums.size()) {
            ans.emplace_back(perm);
            return;
        }
        for (int i = 0; i < (int)nums.size(); ++i) {
            if (vis[i] || (i > 0 && nums[i] == nums[i - 1] && !vis[i - 1])) {
                continue;
            }
            perm.emplace_back(nums[i]);
            vis[i] = 1;
            backtrack(nums, ans, idx + 1, perm, vis);
            vis[i] = 0;
            perm.pop_back();
        }
    }
public:
    static vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<int> vis;
        vector<vector<int>> ans;
        vector<int> perm;
        vis.resize(nums.size());
        sort(nums.begin(), nums.end());
        backtrack(nums, ans, 0, perm, vis);
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    vector<int> nums = getInput(n);
    vector<vector<int>> res = Solution::permuteUnique(nums);
    cout << "---- res ----" << endl;
    printRes(res);

    return 0;
}
