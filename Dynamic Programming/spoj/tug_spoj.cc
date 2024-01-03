#include<bits/stdc++.h>
using namespace std;
int main() {
	int t,n,yes=0;  cin>>t;
	while(t--){
		cin>>n; yes=(n>=100?1:0); //if more than 100 elements then there will be atleast one element which repeats so automatically true
		int a[n+1];
		for(int i=0;i<n;i++)cin>>a[i];
		if(!yes){
		int ans[101][10001]={0};
		for(int i=0;i<=n;i++)ans[i][0]=1;//we can always make sum 0 so true
		for(int j=1;j<=10000;j++)
			for(int i=1;i<=n;i++){
				ans[i][j]=ans[i-1][j];
				if(j>=a[i-1])ans[i][j]+=ans[i-1][j-a[i-1]];
			}
		for(int i=1;i<=10000;i++)if(ans[n][i]>=2)yes=1;
		}
		cout<<(yes?"YES\n":"NO\n");
	}
}
