/**
 * @file leetcode_15.cpp
 * @author wangs7
 * @brief leetcode.15.三数之和
 * @version 0.1
 * @date 2022-09-08
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>

using namespace std;

vector<int> getInput(int N) {
    vector<int> res(N);
    for (int i=0; i<N; i++) {
        cin >> res[i];
    }
    return res;
}

vector<vector<int>> threeSum(vector<int>& nums) {
    int first, second, thired;
    int n = nums.size();
    // 排序
    sort(nums.begin(), nums.end());
    int target;
    vector<vector<int>> ans;

    for (first = 0; first < n-2; first++) { // 固定第一个数的指针
        // 排除相同元素
        if (first > 0 && nums[first] == nums[first-1]) {
            continue;
        }
        // 更新目标值 如果目标值小于0跳出循环
        if((target = -nums[first]) < 0) {
            break; //目标值小于0 表示first>0即second和thired比大于0
        }
        // 第三个数的指针 移动到数组尾部
        thired = n-1;
        // 左右移动 第二个和第三个数的指针 并校验两个数的和
        for (second = first+1; second < n-1; second++) {
            // 移动第二个数的指针 跳过相同元素
            if(second > first+1 && nums[second] == nums[second-1]) {
                continue;
            }
            // 移动第三个数的指针 直到加和不大于目标值 
            for(; thired > second && nums[thired] + nums[second] > target; thired--){
                ;
            }
            // 检查加和是否等于目标值
            if (second < thired && nums[thired] + nums[second] == target) {
                ans.push_back({nums[first], nums[second], nums[thired]});
            }

        }
    }
    return ans;

}

int main(int argc, char const *argv[])
{
    int N;
    cin >> N;
    vector<int> nums = getInput(N);

    vector<vector<int>> res = threeSum(nums);
    for (auto i : res) {
        for (int x : i) {
            cout << x << " ";
        }
        cout << endl;
    } 
    if (res.size() == 0)
        cout << "NULL" << endl;
    return 0;
}
