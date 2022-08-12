//this problem is simple LCS in this problem it is advised 
// to take whole line as the input rather than a word using
// getline
#include <iostream>
using namespace std;
// const int N=1e9+7;
void solve(string s1,string s2){
  int n=s1.size(),m=s2.size();
  int dp[n+1][m+1];
  for(int i=0;i<=n;i++)
      for(int j=0;j<=m;j++){
        if(i==0 or j==0)dp[i][j]=0;
        else if(s1[i-1]==s2[j-1])dp[i][j]=dp[i-1][j-1]+1;
        else dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
      }
    cout<<"you can visit at most "<<dp[n][m]<<" cities.\n";
}
int main(){
  string s1,s2;
  int cnt=0;
  while(1){
    getline(cin,s1);
    if(s1=="#")return 0;
    getline(cin,s2);
    cnt++;
    cout<<"Case #"<<cnt<<": ";
    solve(s1,s2);
  }
}
