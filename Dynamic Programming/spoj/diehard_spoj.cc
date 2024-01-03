#include<bits/stdc++.h>
using namespace std;
// #define int long long int
int val[3][2]={3,2,-5,-10,-20,5},ans[1100][1100][3];

int f(int h,int a,int s){
	if(a<=0 or h<=0) return 0;
	if(ans[h][a][s]!=-1) return ans[h][a][s];
	int answer=0;
	for(int i=0;i<=2;i++)
		if(s!=i){
			if(h+val[i][0]>0 and a+val[i][1]>0)
				answer=max(answer,f(h+val[i][0],a+val[i][1],i));
		}
	return ans[h][a][s]=answer+1;
}
int main() {
	int t ; cin >> t;
	while (t--) {
		memset(ans,-1,sizeof(ans));
		int h,a,mx=0; cin>>h>>a;
		for(int i=0;i<3;i++)mx=max(mx,f(h,a,i));
		cout<<mx-1<<'\n';
	}
}
