#include<bits/stdc++.h>
using namespace std;
#define int long long int
signed main() {
	int t; cin >> t; while (t--) {
		int sum,a,b,c,ans=0; cin>>sum>>a>>b>>c;
		for(int i=0;i<=min(sum,a);i++)
			for(int j=0;j<=min(sum-i,b);j++)
				for(int k=0;k<=min(sum-i-j,c);k++) ans++;
		cout<<ans<<'\n';
	}
	return 0;
}
