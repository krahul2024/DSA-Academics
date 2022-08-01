//in this problem we have to check for all n rows and n columns and 2 diagonals if they
// have two characters or one and answer accordingly
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
// #define f first
// #define s second
map<string,bool>mark;
//to return count unique characters in a string
int f(string s){
  set<char>st;
  for(auto i:s)st.insert(i);
  // mark[s1]=1;
  return st.size();
}
//to return string with unique characters
string fs(string s){
  set<int>s1;
  for(auto i:s)s1.insert(i);
  s.clear();
  for(auto i:s1)s.pb(i);
  return s;
}
void solve(){
  freopen("tttt.in", "r", stdin);
	freopen("tttt.out","w", stdout);
  int n=3;
  set<string>s;
  map<string,int>m;
  char mat[n][n];
  for(int i=0;i<n;i++)for(int j=0;j<n;j++)cin>>mat[i][j];
  string st;
  //row wise operation
  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++)st.pb(mat[i][j]);
    s.insert(st),st.clear();
  }
  int k=n,j=0,i=0;
  //column wise operation
  while(k--){
    while(i<n)st.pb(mat[i][j]),i++;
    s.insert(st);
    j++,i=0;
    st.clear();
  }
  j=0,i=0;
//   for both diagonals
  while(i<n and j<n)st.pb(mat[i++][j++]);m[st]++,s.insert(st),j=n-1,i=0,st.clear();
  while(i<n and j>=0)st.pb(mat[i++][j--]);m[st]++,s.insert(st);
  int a1=0,a2=0;
  //to check for 2 or 1 unique characters
  for(auto x:s){
    string s1=fs(x);
    if(f(x)==1 and !mark[s1])a1++,mark[s1]=1;
    else if(f(x)==2 and !mark[s1])a2++,mark[s1]=1;
  }
  cout<<a1<<"\n"<<a2<<"\n";
}
int main() 
{
  // int t;
  // cin>>t;
  // while(t--)
   solve();
}
