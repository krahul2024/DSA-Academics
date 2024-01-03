#include<bits/stdc++.h>
using namespace std;
#define int long long int
int n,r,ans[101][101],mod=10000007;
signed main() {
	cin>>n>>r;
	if(n<r){cout<<-1<<'\n'; return 0;}// in case number of muffins is less than number of friends
	for(int i=0;i<=100;i++)ans[i][1]=1,ans[0][i]=1;//ways of distributing 0 muffin to r friends is 1 and ways of distributing any number of muffins in only 1 friend is also 1
	for(int i=1;i<=100;i++)
		for(int j=2;j<=100;j++)
			ans[i][j]=(ans[i-1][j]+ans[i][j-1])%mod;
	cout<<ans[n-r][r]<<'\n';
	
}
