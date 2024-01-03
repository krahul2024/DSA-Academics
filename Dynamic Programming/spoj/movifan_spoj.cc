#include<bits/stdc++.h>
using namespace std;
int main() {
	int q; cin >> q;
	while (q--) {
		int n, l, ans = 0;
		scanf("%d%d",&n,&l);
		vector<int>a(n), dp(n, 1);
		for (int i = 0; i < n; i++)scanf("%d",&a[i]);
		for (int i = n - 2; i >= 0; i--) {
			int j = i + 1;
			while (j < n) {
				if (a[i] + l <= a[j])dp[i] += dp[j];
				j++;
			}
			ans += dp[i];
		}
		cout << ans+1<< '\n';
	}
}
