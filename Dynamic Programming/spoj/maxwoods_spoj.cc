#include<bits/stdc++.h>
using namespace std;
#define int long long int
int ans[201][201][2],a[201][201],t,n,m;
int f(int i,int j,int s){
		if(i>=n or j>=m or j<0) return 0;
		if(a[i][j]==-1) return 0; 
		if(ans[i][j][s]!=-1) return ans[i][j][s];
		int answer=f(i,j+(s?1:-1),s);
		return ans[i][j][s]=a[i][j] + max(answer,f(i+1,j,1-s));
}
signed main() {
	cin>>t;
	while(t--){
		cin>>n>>m;//dimensions of the matrix
		for(int i=0;i<n;i++)
			for(int j=0;j<m;j++){
				char c; cin>>c; 
				a[i][j]=(c=='T'?1:c=='#'?-1:0);
			}
		for(int i=0;i<=n;i++)
			for(int j=0;j<=m;j++)
				for(int s=0;s<=1;s++)ans[i][j][s]=-1;
		cout<<f(0,0,1)<<'\n';	
	}
}
