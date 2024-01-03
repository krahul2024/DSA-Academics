#include<bits/stdc++.h>
using namespace std;
int a[201],ans[201][201];
const int mod=1e9+7;
int f(int n,int sum){
	if(sum==0) return 1;
	if(n==0)return 0;
	if(ans[n][sum]!=-1)return ans[n][sum];
	int answer=0;
	for(int i=0;i<=min(sum,a[n-1]);i++)answer+=f(n-1,sum-i)%mod;
	return ans[n][sum]=answer%mod;
}
int main() {
	int t ; cin >> t;
	while (t--) {
		int n,m,x,y; cin>>n>>m;
		for(int i=0;i<n;i++){
			cin>>x>>y; 
			a[i]=y-x;
			m-=x;
		}
		if(m<0)cout<<0<<'\n';
		else if(m==0)cout<<1<<'\n';
		else {
			for(int i=0;i<=200;i++)
				for(int j=0;j<=200;j++)ans[i][j]=-1;
			cout<<f(n,m)%mod<<'\n';
		}
	}
}
