#include<bits/stdc++.h>
using namespace std;
#define int long long int
const int inf = 1e18 + 7;
int a[100011][10],ans[100111][10];
int f(int i,int j,int n){
	if(i==n-1 and j==1) return a[i][j];
	if(i>=n or j<0 or j>2) return inf;
	if(ans[i][j]!=-inf) return ans[i][j];
	int value = f(i,j+1,n);
	for(int x=-1;x<=1;x++)value = min(value , f(i+1,j+x,n));
	return ans[i][j] = a[i][j] + value;
}

signed main() {
	int n,count=1;
	while(cin>>n and n>0){
		for(int i=0;i<n;i++)cin>>a[i][0]>>a[i][1]>>a[i][2];
		for(int i=0;i<=n;i++)for(int j=0;j<=4;j++)ans[i][j]=-inf;
		cout<<count++<<". "<<f(0,1,n)<<'\n';

	}
}
