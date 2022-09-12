/**
 * @file leetcode_572.cpp
 * @author wangs7
 * @brief leetcode.572.另一颗子树
 * @version 0.1
 * @date 2022-09-12
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


int main(int argc, char const *argv[])
{
    
    return 0;
}
