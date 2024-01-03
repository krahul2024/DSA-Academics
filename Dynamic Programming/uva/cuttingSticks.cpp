// this problem is similar to matrix chain multiplication or is problme of range dp
// the type in which we solve for a range and combine the results and compute final
// result on the basis of that. like let's say 1.......n then we solve for f(1...k)+f(k.....n)
// unlike in other dp type where we solve for a particular index like f(n) here we solve for a range.

//  so in this proble we have a woodstick and markings where we have to cut and we have to make all the cuts
//  so what we can do is that we can add two marks like 0 and length of the wood for sake of making problem
//  easier for us. now we can cut from 1..k and k...n then 1...k1,k1..k and k..k2,k2..n and so on
//  and cost of cutting is original length of wood which we are cutting like let's say we have a marking between
//   0..10 at 2 so to cut at  2 we have to pay 10-0 which is a[j]-a[i]
//   which gives us the function min of f(i,k)+f(k,j)+a[j]-a[i].
 
#include <iostream>
#include<vector>
#include<algorithm>
#include<map>
#include<set>
using namespace std;
int dp[51][51];
const int mod=1e9+7;
// recursive approach
int f(vector<int>a,int i,int j){
    if(j-i==1 or i>=j) return 0;
    int ans=mod;
    if(dp[i][j]!=-1) return dp[i][j];
    for(int k=i+1;k<j;k++)ans=min(ans,a[j]-a[i]+f(a,i,k)+f(a,k,j));
      return dp[i][j]=ans;
}
void solve(int sum){
  int n;
  cin>>n;
  vector<int>a(n+2);
  for(int i=1;i<=n;i++)cin>>a[i];
    a[0]=0,a[n+1]=sum;
  for(int i=0;i<51;i++)for(int j=0;j<51;j++)dp[i][j]=-1;
    cout<<"The minimum cutting is "<<f(a,0,n+1)<<".\n";
}
int main(){
  int t;
  while(cin>>t and t!=0)
    solve(t);
}
