#include<bits/stdc++.h>
using namespace std;
#define int long long int
 
signed main(){
	int t; cin>>t;
	for(int k=1;k<=t;k++){
		int n; scanf("%lld",&n);//size of the array
		int a[n+2],ans[n+2];//array to store elements and answer
		for(int i=0;i<n;i++) scanf("%lld",&a[i]);
		ans[0]=a[0];//start element of answer is first element of the array
		if(n>1)ans[1]=max(a[1],a[0]);//we have to iterate in loop from 2nd index so we need to find result for 1th index
		for(int i=2;i<n;i++){
			ans[i]=ans[i-2]+a[i];
			if(ans[i]<ans[i-1])ans[i]=ans[i-1];//recurrence relation is something like this ans[i]=max(ans[i-2]+a[i],ans[i-1])
		}
		if(n>0)printf("Case %lld: %lld\n",k,ans[n-1]);
		else printf("Case %lld: %d\n",k,0);
	}
	return 0;
 
} 
