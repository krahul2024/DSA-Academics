// this problem on submitting a solution without memset gave a TLE but with memset it gave 
// AC so i don't know the logic behind this weird thing.
//   i have attached code in the end which got TLE verdict without memset when i used for loop
// approach:- so the approach for this problem is that we need not to add original numbers as we are checking 
// divisibility for some number 2..100 so here modular maths comes handy as we know (a+b)%m=(a%m+b%m)%m
// also whatever we will add and after taking mod we will get the same remainder whether it is negative or
// positive number.
// so after taking mod after each sum we take mod and when we have added all the numbers then we check for
// remainder=0, if we encounter rem=0 then we return true and take OR of all results.
#include<bits/stdc++.h>
using namespace std;
// const int mod=1e9+7;
int dp[10011][201];
int md(int n,int k){
  return (n%k+k)%k;
}
int n,k;
vector<int>a(10017);
int f(int sum,int i){
    if(i==n){
      if(sum==0)return 1;
      else return 0;
    }
    if(dp[i][sum]!=-1) return dp[i][sum];
    return dp[i][sum]=f(md(sum+a[i],k),i+1) or f(md(sum-a[i],k),i+1);
}
void solve(){
  scanf("%d %d",&n,&k);
  for(int i=0;i<n;i++)scanf("%d",&a[i]),a[i]=md(a[i],k);
  // for(int i=0;i<=n;i++)for(int j=0;j<k;j++)dp[i][j]=-1;
    memset(dp,-1,sizeof(dp));
  int yes=f(a[0],1);
  yes?puts("Divisible"):puts("Not divisible");
  return;
}
int main(){
  int t;
  scanf("%d",&t);
  while(t--)
  solve();
}

// code without memset which got TLE
// #include <iostream>
// #include<vector>
// #include<algorithm>
// #include<map>
// #include<set>
// using namespace std;
// const int mod=1e9+7;
// int dp[10011][201];
// int md(int n,int k){
//   return (n%k+k)%k;
// }
// int n,k;
// int f(vector<int>a,int sum,int i){
// //     if(i==n){
//       if(sum==0)return 1;
//       else return 0;
//     }
//     if(dp[i][sum]!=-1) return dp[i][sum];
//     return dp[i][sum]=f(a,md(sum+a[i],k),i+1) or f(a,md(sum-a[i],k),i+1);
// }
// void solve(){
//   scanf("%d %d",&n,&k);
//   vector<int>a(n);
//   for(int i=0;i<n;i++)scanf("%d",&a[i]),a[i]=md(a[i],k);
//   for(int i=0;i<=n;i++)for(int j=0;j<k;j++)dp[i][j]=-1;
//   int yes=f(a,a[0],1);
//   yes?puts("Divisible"):puts("Not divisible");
//   return;
// }
// int main(){
//   int t;
//   scanf("%d",&t);
//   while(t--)
//   solve();
// }
