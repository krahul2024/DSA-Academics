#include<bits/stdc++.h>
using namespace std;
#define int long long int
const int mod=1e9+7;
void solve(){
	freopen("cownomics.in", "r", stdin);
	freopen("cownomics.out","w", stdout);
	int n,m,cnt=0;
	cin>>n>>m;
	char mat1[n][m],mat2[n][m];
	for(int i=0;i<n;i++)for(int j=0;j<m;j++)cin>>mat1[i][j];
	for(int i=0;i<n;i++)for(int j=0;j<m;j++)cin>>mat2[i][j];
	int i=0,j=0;
	map<char,bool>mark;
	for(j=0;j<m;j++){
	while(i<n){
		// cout<<mat1[i][j];
		if(mat1[i][j]==mat2[i][j] or mark[mat2[i][j]])break;
		mark[mat1[i][j]]=1;
		i++;
	}
	// cout<<"\n";
	if(i==n)cnt++;
	i=0;
	mark.clear();
	}
	cout<<cnt<<"\n";
}
signed main(){
solve();
}
