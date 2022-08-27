// this problem is similar to coin change problem but instead if making coin sum we have to make x^2+y^2=z^2 and using infinte amount
// of any coin(s) or co-ordinates. time-comp O(m*s*s) same as space if done using recursion
#include <bits/stdc++.h>
using namespace std;
#define nl printf("\n")
// #define int long long int
const int mod=1e9+7;
int dp[41][301][301];
struct pr{
  int l,r;
}typedef pr;
int sq(int a){
  return a*a;
}
int f(vector<pr>a,int x,int y,int s,int n){
  if(sq(x)+sq(y)==sq(s)) return 0;
  if(n==0) return mod;
  if(dp[n][x][y]!=-1) return dp[n][x][y];
  if(sq(x+a[n-1].l)+sq(y+a[n-1].r)<=sq(s)) return dp[n][x][y]=min(1+f(a,x+a[n-1].l,y+a[n-1].r,s,n),f(a,x,y,s,n-1));
  else return dp[n][x][y]=f(a,x,y,s,n-1);
}
void solve(){
  int m,s;
  scanf("%d %d",&m,&s);
  vector<pr>a(m);
  for(int i=0;i<m;i++)scanf("%d %d",&a[i].l,&a[i].r);
  memset(dp,-1,sizeof(dp));
  int k=f(a,0,0,s,m);
  k==mod?puts("not possible"):printf("%d\n",k);
}

signed main() 
{
  int t;
  cin>>t;
  while(t--)
    solve();
}
