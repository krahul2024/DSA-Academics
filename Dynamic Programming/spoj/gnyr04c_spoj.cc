#include<bits/stdc++.h>
using namespace std;
#define int long long int
signed main() {
	int t,n,m,ans[11][2001]={0}; cin>>t;
  //here answers for testcases can be calculated once and answered for testcases in O(1) and this is true for most of problems in which we have to find no. of ways of doing something
	for(int i=1;i<=10;i++)
		for(int j=1<<(i-1);j<=2000;j++){
			if(i==1)ans[i][j]=j;
			else ans[i][j]=ans[i][j-1]+ans[i-1][j/2];
		}
  //answering for t testcases in O(1)
	for(int i=1;i<=t;i++){
		scanf("%lld%lld",&n,&m);
		printf("Data set %lld: %lld %lld %lld\n",i,n,m,ans[n][m]);
	}
}
