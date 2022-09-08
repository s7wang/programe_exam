#include<iostream>
#include<algorithm>
#include<string>
#include<vector>

using namespace std;

int main(int argc, const char** argv) {
    // 输入
    int n;
    cin >> n;

    vector<int> nums(n+1, 0);
    for (int i = 1; i < n+1; i++) {
        cin >> nums[i];
    }
    // 找出以k为结尾的最大值
    vector<int> max_k(n+1, 0);
    max_k[0] = 0;
    for(int i = 1; i < n+1; i++) {
        max_k[i] = max(max_k[i-1], max_k[i-1] + nums[i]);
    }
    // 找出以K+1为开头的最大值
    vector<int> max_r(n+1, 0);
    max_r[n] = 0;
    for(int i = n-1; i >= 0; i--) {
        max_r[i] = max(max_r[i+1], max_r[i+1] + nums[i]);
    }

    //合并找最大值
    int res = 0;
    for (int i = 0; i < n+1; i++) {
        res = max(res, max_k[i] + max_r[i]);
    }
    cout << res << endl;

    return 0;
}