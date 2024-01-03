// this code got one testcase wrong.
// in this problem we have to find profit for every single cow and then compare it with rentals and take max of both 
// and sum all the maximas that's it.
#include <bits/stdc++.h>
#define int long long int
#define pb push_back
using namespace std;
const int mod=1e9+7;
struct pr{
	int cap,price;
}typedef pr;
bool compapr(pr a,pr b){
	if(a.price==b.price) return a.cap>b.cap;
	else return a.price>b.price;
}
void solve(){
	freopen("rental.in","r",stdin);
	freopen("rental.out","w",stdout);
	int n,m,r,capacity=0,arsum=0,mx;
	cin>>n>>m>>r;
	vector<int>an(n),ar(r);
	vector<pr>apr(m);
	for(int i=0;i<n;i++)cin>>an[i],arsum+=an[i];
	for(int i=0;i<m;i++)cin>>apr[i].cap>>apr[i].price,capacity+=apr[i].cap;
	for(int i=0;i<r;i++)cin>>ar[i];
	if(r<n){
		int i=r;
		while(i<n)ar.pb(0),i++;
		r=n;
	}
	if(capacity<arsum)apr.pb({arsum-capacity,0}),m+=1;
	sort(begin(an),end(an),greater<int>());
	sort(begin(ar),end(ar));
	sort(begin(apr),end(apr),compapr);
	int i=0,j=0,sum=0;
	vector<int>asum;
	while(i<m and j<n){
		if(apr[i].cap>=an[j]){
			sum+=apr[i].price*an[j];
			apr[i].cap-=an[j];
			an[j]=0;
			asum.pb(sum);
			sum=0;
			if(apr[i].cap==0)i++;
			j++;
		}
		else if(apr[i].cap<an[j]){
			sum+=apr[i].cap*apr[i].price;
			an[j]-=apr[i].cap;
			apr[i].cap=0;
			i++;
		}
	}
// 	for(int i=0;i<n;i++)cout<<an[i]<<" "<<ar[i]<<"\n";
    sum=0;
    for(int i=0;i<n;i++)sum+=(max(ar[i],asum[i]));
    cout<<sum<<"\n";
}
signed main() 
{
    solve();
}
