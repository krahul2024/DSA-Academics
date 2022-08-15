// in this problem we just have to create a map strings and int and assign sums for each strings
// after this we have to check for occurrences of second largest element if only one then output the 
// corresponding string else ouput tie there may be some tricky cases if unique strings count is less than 7 and if only one unique
// string with sum=0 then that may be a tricky case what i think so.
#include <bits/stdc++.h>
using namespace std;
#define int long long int
#define pb push_back 
bool comp(int a,int b){
  return a>b;
}
void solve(){
  freopen("notlast.in", "r", stdin);
	freopen("notlast.out","w", stdout);
  int n;
  cin>>n;
  string s;
  int k;
  map<string,int>m;
  for(int i=0;i<n;i++)cin>>s>>k,m[s]+=k;
  vector<int>a;
  for(auto i:m)a.pb(i.second);
  sort(a.begin(),a.end());
  int cnt=1;
//   if unique strings count is 7
  if(a.size()==7){
  for(int i=1;i<a.size();i++){
    if(a[i]!=a[i-1])cnt++;
    if(cnt==2){k=a[i];break;}
  }
  cnt=0;
  for(int i=0;i<n;i++)if(a[i]==k)cnt++;
  if(cnt==1){for(auto i:m)if(i.second==k){cout<<i.first<<"\n";break;}}
  else if(cnt>1)puts("Tie");
    return;
  }
//   if unique strings count is less than 7 but greater than 1
  else if(a.size()>=2){
    cnt=0;
      for(int i=0;i<n;i++)if(a[i]==a[0])cnt++;
      if(cnt==1){for(auto i:m)if(i.second==a[0]){cout<<i.first<<"\n";break;}}
      else if(cnt>1)puts("Tie");
      return;
  }
//   if only one unique string
  else if(a.size()==1){
    for(auto i:m){
      if(i.second!=0){cout<<i.first<<"\n";break;}
      else puts("Tie");
    }
    return;
  }
}
signed main() 
{
  solve();
}
