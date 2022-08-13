#include<bits/stdc++.h>
using namespace std;
// ways to partition n into k groups
const int mod=1e9+7;
void solve(){
  int n,k;
  cin>>n>>k;
  // vector<vector<int>>dp(n+1,vector<int>(k+1));
  int dp[n+1][k+1];
  dp[0][0]=1;// we can always group 0 into 0 groups in 1 way
  for(int i=0;i<=n;i++)for(int j=0;j<=k;j++){
      dp[i][j]=0;// as arrays don't have default value as 0
      if(j==1)dp[i][1]=1;// as we have to group n into 1 goup so there is one way
      // as we have dealt with k=1 and n=0, we can also say that if we have n=1 which is
      // we have one element, so in this case when n=1 and k=1 then one way other wise 0 ways so we can also exclude n=1
      if(i>1 and j>1){
        if(i>=j)dp[i][j]=(dp[i-1][j-1]+dp[i-j][j])%mod; // we will group only when no.of elements >= no.of groups
            else dp[i][j]=dp[i-1][j-1]%mod; //otherwise previous
          }
      }
  cout<<dp[n][k];
}
int main(){
  solve();
}
