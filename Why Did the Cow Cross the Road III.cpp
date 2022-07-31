#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define f first
#define s second
void solve(){
  freopen("cowqueue.in", "r", stdin);
	freopen("cowqueue.out","w", stdout);
  int n;
  cin>>n;
  vector<pair<int,int>>a(n);
  for(int i=0;i<n;i++)cin>>a[i].f>>a[i].s,a[i].s+=a[i].f;
  sort(a.begin(),a.end());
  int t=a[0].second;
  for(int i=1;i<n;i++)if(a[i].f<a[i-1].s)a[i].s=(a[i].s-a[i].f+a[i-1].s),a[i].f=a[i-1].s;
  cout<<a[n-1].s<<"\n";
}
int main() 
{
  // int t;
  // cin>>t;
  // while(t--)
   solve();
}
