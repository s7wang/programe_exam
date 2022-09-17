/**
 * @file leetcode_46.cpp
 * @author wangs7
 * @brief leetcode.46.全排列
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
    static void backtrack(vector<vector<int>>& res, vector<int>& nums, int index, int n) {
        // 填完了加入集合
        if (index == n) {
            res.push_back(nums);
            return;
        }
        // 遍历交换
        for (int i = index; i<n; i++) {
            // 交换当前位置
            swap(nums[i], nums[index]);
            // 递归遍历
            backtrack(res, nums, index+1, n);
            // 回溯 再换回来
            swap(nums[i], nums[index]);
        }
        return;
    }
public:
    static vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        // 递归求解
        backtrack(res, nums, 0, nums.size());
        return res;
    }
};

int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    vector<int> nums = getInput(n);
    vector<vector<int>> res = Solution::permute(nums);
    cout << "---- res ----" << endl;
    printRes(res);

    return 0;
}
