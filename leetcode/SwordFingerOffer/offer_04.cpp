/**
 * @file offer_04.cpp
 * @author wangs7
 * @brief 剑指offer.04.二维数组中的查找
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

vector<vector<int>> getInput(int m, int n) {
    vector<vector<int>> res(m, vector<int>(n, 0));
    for (int x=0; x<m; x++) {
        for (int y=0; y<n; y++) {
           cin >> res[x][y];
        }
    }
    return res;
}

class Solution {
public:
    static bool findNumberIn2DArray(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        if (m == 0) {
            return false;
        }
        int n = matrix[0].size();
        // 以右上角为起点遍历矩阵
        int i = 0, j = n-1;
        /**
         *   <--------- j = n-1
         * 1  4  7  11 15 i = 0
         * 2  5  8  12 19 |
         * 3  6  9  16 22 |
         * 10 13 14 17 24 v
         * 18 21 23 26 30
         */
        while (i < m && j >= 0) { // 越界退出
            if (target == matrix[i][j]) { 
                return true; // 匹配成功返回
            }
            else if (target > matrix[i][j]) {
                i++; // 目标值较大指针向下移动
            }
            else {
                j--; // 目标值较小指针向左移动
            }
        }
        // 越界仍未找到 返回失败
        return false;
    }
};

int main(int argc, char const *argv[])
{
    int m, n, target;
    cin >> m >> n;
    vector<vector<int>> input = getInput(m, n);
    cin >> target;
    
    cout.setf(ios_base::boolalpha);
    cout << Solution::findNumberIn2DArray(input, target) << endl;
    return 0;
}
