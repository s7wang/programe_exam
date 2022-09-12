/**
 * @file offer_07.cpp
 * @author wangs7
 * @brief offer.07.重建二叉树
 * @version 0.1
 * @date 2022-09-12
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <unordered_map>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

vector<int> getInput(int m) {
    vector<int> res(m, 0);
    for (int i=0; i<m; i++) {
        cin >> res[i];
    }
    return res;
}
/** 层序遍历结果 **/
void printTree(TreeNode* root) {
    TreeNode* cur = nullptr;
    queue<TreeNode*> q;
    q.push(root);
    queue<TreeNode*> out;
    int size = 1, lay = 0;
    int c = 0;
    while (!q.empty()) {
        cur = q.front(); q.pop();
        size--;
        out.push(cur);
        if (cur == nullptr) {
            q.push(nullptr); q.push(nullptr);
        }
        else {
            c++;
            q.push(cur->left); q.push(cur->right);
        }
        if (size == 0) {
            if (c == 0)
                break;
            lay++;
            size = 1 << lay;
            while (!out.empty()) {
                cur = out.front(); out.pop();
                if (cur == nullptr) {
                    cout << "null" << " ";
                }
                else {
                    cout << cur->val << " ";
                }
            }
            c = 0;
        }
    }
    cout << endl;
}
// -----------------------------------------------------------------------------------------
/** 递归解 **/
class RecursionSolution {
private:
    static TreeNode* myBuildTree(const vector<int>& preorder, const vector<int>& inorder, 
                                 int preorder_left, int preorder_right, 
                                 int inorder_left, int inorder_right,
                                 unordered_map<int, int>& index) {
        
        if (preorder_left > preorder_right) {
            return nullptr;
        }
        
        // 前序遍历中的第一个节点就是根节点
        int preorder_root = preorder_left;
        // 在中序遍历中定位根节点
        int inorder_root = index[preorder[preorder_root]];
        
        // 先把根节点建立出来
        TreeNode* root = new TreeNode(preorder[preorder_root]);
        // 得到左子树中的节点数目
        int size_left_subtree = inorder_root - inorder_left;
        // 递归地构造左子树，并连接到根节点
        // 先序遍历中「从 左边界+1 开始的 size_left_subtree」个元素就对应了中序遍历中「从 左边界 开始到 根节点定位-1」的元素
        root->left = myBuildTree(preorder, inorder, 
                                 preorder_left + 1, preorder_left + size_left_subtree, 
                                 inorder_left, inorder_root - 1, 
                                 index);
        // 递归地构造右子树，并连接到根节点
        // 先序遍历中「从 左边界+1+左子树节点数目 开始到 右边界」的元素就对应了中序遍历中「从 根节点定位+1 到 右边界」的元素
        root->right = myBuildTree(preorder, inorder, 
                                  preorder_left + size_left_subtree + 1, preorder_right, 
                                  inorder_root + 1, inorder_right, 
                                  index);
        return root;
    }
public:
    static TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = preorder.size();
        unordered_map<int, int> index;
        // 构造哈希映射，帮助我们快速定位根节点
        for (int i = 0; i < n; ++i) {
            index[inorder[i]] = i;
        }
        return myBuildTree(preorder, inorder, 0, n - 1, 0, n - 1, index);
    }
};

/** 迭代解 **/
class IterationSolution {
public:
    static TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if (preorder.size() == 0)
            return nullptr;
        stack<TreeNode*> s;
        TreeNode* root = new TreeNode(preorder[0]);
        // 根节点入栈 初始化中序序列指针
        s.push(root);
        int index = 0;
        // 遍历前序序列
        for (int i=1; i<preorder.size(); i++) {
            // 记录当前节点
            int preValue = preorder[i];
            TreeNode* cur = s.top();

            if (cur->val != inorder[index]) {
                // 如果当前栈顶值与中序指针的值不同
                // 添加左节点 入栈
                cur->left = new TreeNode(preValue);
                s.push(cur->left);
            }
            else { // 如果值不同 需要找出当前值为那个节点的 右节点
                // 循环判断当前栈顶值与中序指针相同时
                while (!s.empty() && s.top()->val == inorder[index]) {
                    cur = s.top();
                    // 弹出栈顶 指针右移
                    s.pop();
                    index++;
                }
                // 遇到最后一个值相同的节点 当前值即为该节点的右节点
                cur->right = new TreeNode(preValue);
                // 新节点入栈
                s.push(cur->right);
            }
        }
        // 遍历结束返回根节点
        return root;
    }
};
// ----------------------------------------------------------------------------
int main(int argc, char const *argv[])
{
    int m;
    cin >> m;
    vector<int> preorder = getInput(m);
    vector<int> inorder = getInput(m);
    TreeNode* root1 = RecursionSolution::buildTree(preorder, inorder);
    TreeNode* root2 = IterationSolution::buildTree(preorder, inorder);
    cout << "递归解：" << endl;
    printTree(root1);
    cout << "迭代解：" << endl;
    printTree(root2);


    return 0;
}
