#include<bits/stdc++.h>
using namespace std;
#define int long long int
signed main() {
	int t; cin >> t;
	while (t--) {
		int sz=0,n,value=0; cin>>n; int a[n];
		for(int i=0;i<n;i++)cin>>a[i],sz+=a[i];
		bool ans[n+1][sz+1]={false};
		ans[0][0]=true;
		for(int sum=0;sum<=sz;sum++){
			for(int i=0;i<=n;i++){
				if(i==0)ans[i][sum]=false;
				if(sum==0)ans[i][sum]=true;
				else if(i>0){
					ans[i][sum]=ans[i-1][sum];
					if(sum>=a[i-1])ans[i][sum]= ans[i][sum] or ans[i-1][sum-a[i-1]];
				}
			}
			if(ans[n][sum]) value+=sum;
		}
		cout<<value<<endl;
	}

}
