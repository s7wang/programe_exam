/**
 * @file leetcode_986.cpp
 * @author wangs7
 * @brief leetcode.986.区间列表交集
 * @version 0.1
 * @date 2022-09-10
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) {
    int i = 0, j = 0;
    int fn = firstList.size(), sn = secondList.size();
    vector<vector<int>> res;
    // 遍历两个列表
    while (i < fn && j < sn) {
        // 区两个列表交集的开始b和结尾e
        int b = max(firstList[i][0], secondList[j][0]);
        int e = min(firstList[i][1], secondList[j][1]);
        // 如果 b<=e 表示交集合法 加入结果集合
        if (b <= e) {
            res.push_back({b, e});
        }
        // 如果耗尽了区间 移动指针
        if (firstList[i][1] == e) i++;
        if (secondList[j][1] == e) j++;
    }
    return res;
}


int main(int argc, char const *argv[])
{
    cout << "输入复杂, 请到leetcode测试或自行构建用例和输入接口" << endl;
    return 0;
}
