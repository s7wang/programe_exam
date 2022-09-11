/**
 * @file leetcode_130.cpp
 * @author wangs7
 * @brief leetcode.130.被围绕的区域
 * @version 0.1
 * @date 2022-09-11
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<vector<char>> getInput(int m, int n) {
    vector<vector<char>> res(m, vector<char>(n, 'X'));
    for (int x=0; x<m; x++) {
        for (int y=0; y<n; y++) {
           cin >> res[x][y];
        }
    }
    return res;
}

void printOutput(vector<vector<char>>& board) {
    int m = board.size();
    int n = board[0].size();
    cout << "------ OUTPUT ------" <<endl;
    for (int x=0; x<m; x++) {
        for (int y=0; y<n; y++) {
           cout << board[x][y] << ' ';
        }
        cout << endl;
    }
}

class Solution {
private:
    /** 深度优先搜索函数 **/
    static int dfs(int x, int y, vector<vector<char>>& board) {
        int m = board.size();
        int n = board[0].size();
        // 越界停止
        if (x < 0 || x >= m || y < 0 || y >= n) {
            return 0;
        }
        // 符合条件用A替换O
        if (board[x][y] == 'O') {
            board[x][y] = 'A';
            // 继续深搜
            dfs(x-1, y, board);
            dfs(x, y-1, board);
            dfs(x+1, y, board);
            dfs(x, y+1, board);
            return 1;
        }

        return 0;
    }
public:
    /** 处理函数 **/
    static vector<vector<char>>& solve(vector<vector<char>>& board) {
        int m = board.size();
        int n = board[0].size();
        // 遍历上边界 左->右 深搜 并更新
        for(int x=0, y=0; y<n; y++) {
            if (board[x][y] == 'O') {
                dfs(x, y, board);
            }
        }
        // 遍历右边界 上->下
        for(int x=0, y=n-1; x<m; x++) {
            if (board[x][y] == 'O') {
                dfs(x, y, board);
            }
        }
        // 遍历下边界 左->右
        for(int x=m-1, y=0; y<n; y++) {
            if (board[x][y] == 'O') {
                dfs(x, y, board);
            }
        }
        // 遍历左边界 上->下
        for(int x=0, y=0; x<m; x++) {
            if (board[x][y] == 'O') {
                dfs(x, y, board);
            }
        }

        // 更新整个图 A->O  O->X   X->X
        for (int x=0; x<m; x++) {
            for (int y=0; y<n; y++) {
                if (board[x][y] == 'O') {
                    board[x][y] = 'X';
                }
                else if (board[x][y] == 'A') {
                    board[x][y] = 'O';
                }
            }
        }
        return board;
    }

    
};
int main(int argc, char const *argv[])
{
    int m, n;
    cin >> m >> n;
    vector<vector<char>> input = getInput(m, n);

    vector<vector<char>>& output = Solution::solve(input);
    
    printOutput(output);

    return 0;
}
