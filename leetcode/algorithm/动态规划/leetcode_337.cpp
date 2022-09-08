/**
 * @file leetcode_337.cpp
 * @author wangs7
 * @brief leetcode.337.打家劫舍III
 * @version 0.1
 * @date 2022-09-06
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

/** 存放返回信息 选和不选该节点的最大值 **/
struct SubtreeStatus {
    int selected;
    int notSelected;
};
//=====================================================================================================
vector<int> getInput(int N) {
    vector<int> res(N);
    for (int i=0; i<N; ++i) {
        cin >> res[i];
    }
    return res;
}

/** 构建树 **/
TreeNode* initTree(vector<int>& nums) {
    int n = nums.size();
    if (n == 0) {
        return nullptr;
    }
    if (n == 1) {
        return new TreeNode(nums[0]);
    }
    TreeNode* root = new TreeNode(nums[0]);
    queue<TreeNode *> q;
    q.push(root);
    TreeNode* cur = nullptr;
    int i = 1;
    while (i < n)
    {
        cur = q.front();
        q.pop();
        if (cur == nullptr) {
            i += 2;
            q.push(nullptr);
            q.push(nullptr);
            continue;
        }

        if (nums[i] == -1) {
            q.push(nullptr);
        }
        else {
            cur->left = new TreeNode(nums[i]);
            q.push(cur->left);
        }
        i++;
        if (i < n) {
            if (nums[i] == -1) {
                q.push(nullptr);
            }
            else {
                cur->right = new TreeNode(nums[i]);
                q.push(cur->right);
            }
        }
        i++;
    }
    

    return root;
}

//==================================================================


class Solution {
public:
    /** 深度搜索函数 返回该节点的信息 选和不选该节点的最大值 **/
    static SubtreeStatus dfs(TreeNode* node) {
        // 为空返回 0 0
        if (!node) {
            return {0, 0};
        }
        // 向左遍历 得到返回信息 l        
        auto l = dfs(node->left);
        // 向右遍历 得到返回信息 r 
        auto r = dfs(node->right);
        // 选该节点的最大值
        int selected = node->val + l.notSelected + r.notSelected;
        // 不选该节点的最大值
        int notSelected = max(l.selected, l.notSelected) + max(r.selected, r.notSelected);
        // 返回
        return {selected, notSelected};
    }

    static int rob(TreeNode* root) {
        // 深度优先遍历
        auto rootStatus = dfs(root);
        // 返回选或者不选根节点中较大的值
        return max(rootStatus.selected, rootStatus.notSelected);
    }
};


int main(int argc, const char** argv) {
    int N;
    cin >> N;
    vector<int> input = getInput(N);

    TreeNode* root = initTree(input);
    cout << Solution::rob(root) << endl;

    return 0;
}