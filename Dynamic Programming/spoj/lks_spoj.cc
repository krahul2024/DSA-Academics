#include<bits/stdc++.h>
using namespace std;
int ans[2][2000005];
int main() {
	int k,n; scanf("%d%d",&k,&n);
	int w[n],v[n];//w is for weights and v is for values and ans is for max value or you can say it is the dp table
	for(int i=0;i<n;i++)scanf("%d%d",&v[i],&w[i]);

	ans[0][0]=ans[1][0]=0;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=k;j++){
			ans[(i&1)][j]=ans[!(i&1)][j];//updating it with previous best answer upto that weight
			if(j>=w[i-1])ans[(i&1)][j]=max(ans[(i&1)][j],v[i-1]+ans[!(i&1)][j-w[i-1]]); 
		}

	cout<<max(ans[0][k],ans[1][k])<<endl;
}
