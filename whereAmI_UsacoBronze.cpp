#include <bits/stdc++.h>
using namespace std;
#define pb push_back
// #define f first
// #define s second
void solve(){
  freopen("whereami.in", "r", stdin);
	freopen("whereami.out","w", stdout);
  int n,k=0,mx=0;
  cin>>n;
  string s;
  cin>>s;
  map<string,int>count;
  //In this problem I have used most brute force approach using maps
  //first I am iterating on all subarrays length wise like first on all subs of length 1 then 2 and so on...
  //then we have to check for a substring which is of longest size and occurs twice as soon we find 
  //then we can say that there will be no substring (of length plus 1 ) which will be repeating then we 
  //print size of longest size and occurs twice +1.
  for(int i=0;i<n;i++){
    for(int j=0;j+i<n;j++){
      string st;
      for(int x=j;x<=j+i;x++)
      st.pb(s[x]);
      count[st]++;
    }
    for(int j=0;j+i<n;j++){
      string st;
      for(int k=j;k<=j+i;k++)st.pb(s[k]);
      if(count[st]==2)mx=max(mx,int(st.size()));
    }
  }
  cout<<mx+1<<"\n";
}
int main() 
{
  // int t;
  // cin>>t;
  // while(t--)
   solve();
}
