#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include <queue>

using namespace std;

int main(int argc, const char** argv) {
    int n, k;
    cin >> n >> k;
    vector<int> nums(n, 0);
    int sum = 0;

    // lambda 表达式作为 Campare，当返回 true 时，left 先进入，后输出，即在优先级队列（堆）的下方
    auto cmp = [](pair<int, int> left, pair<int, int> right) -> bool { return left.first > right.first; };
    // 优先队列 小的值在前 后边统计有该值的序号
    priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> q(cmp);

    //获取输入顺便计算初始窗口
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
        
        if (i < k) {
            q.push({nums[i], i});
            sum += nums[i];
        }
    }
    //移动窗口 加k+1，越界出队，减最小值
    int res = 0;
    for (int i = k; i < n; i++) {
        sum += nums[i];
        q.push({nums[i], i});

        while (q.top().second < i-k) {
            q.pop();
        }
        res = max(res, sum - q.top().first);
        sum -= nums[i-k];
        
    }

    cout << res << endl;

    return 0;
}