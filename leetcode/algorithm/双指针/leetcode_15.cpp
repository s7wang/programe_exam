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
    sort(nums.begin(), nums.end());
    int target;
    vector<vector<int>> ans;

    for (first = 0; first < n-2; first++) {
        if (first > 0 && nums[first] == nums[first-1]) {
            continue;
        }
        
        if((target = -nums[first]) < 0) {
            break;
        }
        thired = n-1;
        for (second = first+1; second < n-1; second++) {
            if(second > first+1 && nums[second] == nums[second-1]) {
                continue;
            }
            for(; thired > second && nums[thired] + nums[second] > target; thired--){
                ;
            }
            
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
