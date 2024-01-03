#include<bits/stdc++.h>
using namespace std;
#define int long long int
int ans[105][105], sum[105][105], a[105];

int f(int i, int j) {
	if (i == j)return 0; //0 when both the indexes are same as we aren't really doing any operation with any element
	if (ans[i][j] != -1)return ans[i][j];//memoization condition
	int value = INT_MAX, s = 0;//value is for storing min smoke value for a particular range and s is for storing current smoke value for a range
	for (int k = i; k < j; k++) {
		s = f(i, k) + f(k + 1, j) + sum[i][k] * sum[k + 1][j];
		if (s < value)value = s, sum[i][j] = (sum[i][k] + sum[k + 1][j]) % 100;//if we find that smoke value for a range is less than current one then we take the sum of all elements mod 100
	}
	return ans[i][j] = value;//storing the best or minimum value of smoke
}
signed main() {
	int n;  while (cin >> n){//for inputs till end of file or inputs
    for (int i = 0; i < n; i++)cin >> a[i], sum[i][i] = a[i];//when both indexes are same then the sum%100 is a[i]
	memset(ans, -1, sizeof(ans)); cout << f(0, n - 1) << '\n';
  }
}
