/**
 * @file leetcode_1091.cpp
 * @author wangs7
 * @brief leetcode.1091.二进制中的最短路径
 * @version 0.1
 * @date 2022-09-10
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<vector<int>> getInput(int N) {
    vector<vector<int>> res(N, vector<int>(N, 0));
    for (int i=0; i<N; i++) {
        for (int j=0; j<N; j++) {
            cin >> res[i][j];
        }
    }
    return res;
}

int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
    int d[] = {-1, 0, 1}; // 移动增量
    // 入口进不去 返回-1
    if (grid[0][0] == 1)
        return -1;
    // 获取大小 1X1 的话直接返回1
    int N = grid.size();
    if(N==1) 
        return 1;
    // 存放遍历节点队列
    queue<pair<int, int>> q;
    q.push({0, 0}); // 起点入栈
    grid[0][0] = 2; // 入栈后标记已访问
    // 结果res 以及每层遍历节点数量
    int res = 1, size = 1;
    // 队列不空一直访问
    while (!q.empty()) {
        // 取出队头的坐标 size计数减一
        int x = q.front().first;
        int y = q.front().second;
        q.pop(); size--;
        // 以该点为中心遍历周围的节点
        for (int i=0; i<3; i++) {
            // x+d[i]越界 继续下次循环
            if (x+d[i]>=N || x+d[i]<0) continue;
            // 遍历y+d 
            for (int j=0; j<3; j++) {
                // 去除偏移量0 0和y+[j]越界的情况
                if ((i==1 && j==1) || y+d[j]>=N || y+d[j]<0) continue;
                // 如果到达终点且出口为0 返回总步数
                if(x+d[i] == N-1 && y+d[j] == N-1 && grid[x+d[i]][y+d[j]] == 0) 
                    return res+1;
                // 非终点且可访问 入队 且标记已访问
                if (grid[x+d[i]][y+d[j]] == 0) {
                    grid[x+d[i]][y+d[j]] = 2;
                    q.push({x+d[i],y+d[j]});
                }
            }
        }
        // 如果size为0 则完成一层遍历
        if (size == 0) {
            // 更新size大小 步数加1
            size = q.size();
            res++;
        }
    }
    // 完成遍历还是没到达终点
    return -1;
}

int main(int argc, char const *argv[])
{
    int N;
    cin >> N;
    vector<vector<int>> m = getInput(N);

    cout << shortestPathBinaryMatrix(m) << endl;
    return 0;
}
