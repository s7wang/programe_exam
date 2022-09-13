#include <iostream>
#include <vector>
#include <queue>
#include <tuple>

using namespace std;


#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>
using namespace std;

vector<int> getInput(int N) {
    vector<int> res(N);
    for (int i=0; i<N; ++i) {
        cin >> res[i];
    }
    return res;
}

int maxScore(int n, int k, vector<int>& a, vector<int>& b,vector<int>& c) {
    // 整合a b c 三个数组
	vector<std::tuple<int, int, int>> num;
	int ans = 0;
	for (int i = 0; i < n; ++i) {
        ans += a[i]; // 默认不作弊
        // num的第二项 为“反悔”不作弊改作弊的得分增加量
		num.push_back({ a[i],b[i]-a[i],c[i] });
	}
    // 将num排序让增量大的排在前面
	sort(num.begin(), num.end(), [&](tuple<int,int,int>& a, tuple<int,int,int>& b) {
			return get<1>(a) > get<1>(b);
		}
	);
    // dp表
	vector<int> dp(k+1, 0);
	for (int i = 0; i < n; ++i) {
		for (int j = k; j >= get<2>(num[i]); --j) {
			/*问题转化为背包问题，即求(作弊-不作弊)的最大值，weight即为c[i]，价值为b[i]-a[i]*/
			dp[j] = max(dp[j], dp[j - get<2>(num[i])] + get<1>(num[i]));
		}
	}
	int res = dp[k] +1500+ans;/*最后直接加上不作弊的积分总和即可*/
	
	return res;
}

int main(int argc, char const *argv[])
{
    int n, k;
	cin >> n >> k;
    vector<int> a = getInput(n);
    vector<int> b = getInput(n);
    vector<int> c = getInput(n);
    cout << "----------------" << endl;
    cout << maxScore(n, k, a, b, c) << endl;
    return 0;
}
