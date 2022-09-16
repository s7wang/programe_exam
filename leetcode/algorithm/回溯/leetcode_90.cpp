/**
 * @file leetcode_90.cpp
 * @author wangs7
 * @brief leetcode.90.子集II
 * @version 0.1
 * @date 2022-09-16
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
/** 迭代解 **/
class IterationSolution {
public:
    /**
     * 例如，n = 3，a = { 5, 2, 9 }时：mask对应0/1序列。
     * 0/1序列      子集        0/1 序列对应的二进制数
     * 000000	    {}	            0
     * 001001	    {9}	            1
     * 010010	    {2}	            2
     * 011011	    {2,9}	        3
     * 100100	    {5}	            4
     * 101101	    {5,9}	        5
     * 110110	    {5,2}	        6
     * 111111	    {5,2,9}	        7
     */
    static vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        // 排序
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;

        // 遍历位图 n位
        for (int mask=0; mask < (1 << n); mask++) {
            // 临时子集
            vector<int> a;
            // 是否加入子集
            bool flag = true;
            // 判断指定位上是否 为1
            for (int i=0; i < n; i++) {
                // 对应位为1插入对应数字
                if (mask & (1 << i)) {
                    // 如果出现重复子集 flag = false 跳出循环
                    if (i>0 && //非起始位置
                        (mask & 1 << (i-1))==0 && // 前一位没被选过
                        nums[i] == nums[i-1] /* 前一位和当前为一样 */) {
                        flag = false;
                        break;
                    }    
                    a.push_back(nums[i]);
                }
            }
            // 结束将子集加入解集合中
            if (flag) ans.push_back(a);
        }
        // 返回结果
        return ans;
    }
};

/** 回溯（递归）解 **/
class RecursionSolution {

private:
    /** 递归函数 深度搜索 **/
    static void dfs(bool choosePre, int index, vector<int>& nums, vector<vector<int>>& ans, vector<int>& t) {
        // 触碰边界添加结果 返回
        if (index == nums.size()) {
            ans.push_back(t);
            return;
        }
        // 不添加当前
        dfs(false, index+1, nums, ans, t);
        // 若发现没有选择上一个数，且当前数字与上一个数相同，则可以跳过当前生成的子集。
        if (!choosePre && index > 0 && nums[index - 1] == nums[index]) {
            return;
        }

        // 添加当前
        t.push_back(nums[index]);
        dfs(true, index+1, nums, ans, t);

        // 回溯推出
        t.pop_back();
        return;
    }
public:

    static vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> t;
        // 排序
        sort(nums.begin(), nums.end());
        // 回溯遍历
        dfs(false, 0, nums, ans, t);
        // 返回解
        return ans;
    }
};


int main(int argc, char const *argv[])
{
    
    int n;
    cin >> n;
    vector<int> nums = getInput(n);

    vector<vector<int>> res1 = RecursionSolution::subsets(nums);
    vector<vector<int>> res2 = IterationSolution::subsets(nums);

    cout << "递归解：" << endl;
    printRes(res1);
    cout << "迭代解：" << endl;
    printRes(res2);
    

    return 0;
}
