// this is classic coin change problem in which we have to find number of ways to make 
// some amount of coins
#include <iostream>
#include<cstring>
using namespace std;
int main() 
{
  int a[5]={1,5,10,25,50};
  int dp[8000];
  memset(dp,0,sizeof(dp));
  dp[0]=1;
  for(int i=0;i<5;i++)for(int j=a[i];j<=7999;j++)dp[j]+=dp[j-a[i]];
  string s;
  while(cin>>s)printf("%lld\n",dp[stoi(s)]);
}
