#include<bits/stdc++.h>
using namespace std;
int main() {//this problem is just fibonacci calculation
	int n=1000004,mod=1000000007;
	vector<int>a(n);
	a[0]=a[1]=0,a[2]=a[3]=1;
	for(int i=4;i<=n-1;i++)a[i]=a[i-2]%mod+a[i-3]%mod,a[i]%=mod;
	int q; cin >> q;
	while (q--) {
		scanf("%d",&n);
		cout<<a[n]%mod<<'\n';
	}
}
