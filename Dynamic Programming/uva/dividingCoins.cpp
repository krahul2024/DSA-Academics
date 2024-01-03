// in this problem we have to divide the given array in two subsets such that their 
// difference is minimum
#include <iostream>
#include<vector>
#include<algorithm>
#include<map>
#include<set>
using namespace std;
int dp[101][50001];
const int mod=1e9+7;
int f(vector<int>a,int sum,int sumby2,int n){
  if(sum>=sumby2) return sum;
  if(n==0) return mod;
  if(dp[n][sum]!=-1) return dp[n][sum];
  return dp[n][sum]=min(f(a,sum+a[n-1],sumby2,n-1),f(a,sum,sumby2,n-1));
}
void solve(){
  int n;
  cin>>n;
  vector<int>a(n);
  int sum=0,sumby2=0;
  for(int i=0;i<n;i++)cin>>a[i],sum+=a[i];
  sumby2=sum/2;
  for(int i=0;i<=n;i++)for(int j=0;j<=sum;j++)dp[i][j]=-1;
  int k=f(a,0,sumby2,n);
  // cout<<k<<"\n";
    cout<<abs(2*k-sum)<<"\n";
}
int main(){
  int t;
  cin>>t;
  while(t--)solve();
}
