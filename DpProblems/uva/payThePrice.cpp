// in this problem we have to find no of ways in which we can make a given sum<=300 using coins of values<=300 and we are
// bounded on the value of coins like we have a range of number of coins to be used like
// make sum 6 using 2,3,4,5 no.of coins and value is b/w value=>{1,300} also quantity of coins is infinite
// basically this is problem of unbounded knapsack. we can solve it by this approach
// --> suppose we are making a sum using n coins so either we can take a particular coin to sum it or not
// while considering a coin we also increase no. of coins as we are considering this coin.sizeso the relation becomes
// f(index,sum,numOfCoins)=f(index-1,sum-coins[index-1],numOfCoins-1)+f(index-1,sum,numOfCoins-1) this when coin value is less or equal than sum
// f(index-1,sum,numOfCoins-1) this when coin value is greater than sum
// time complexity and space complexity:- O(N*Sum*NumberOfCoins)~~O(N^3)
// although it can be solved in space complexity O(N^2);
// I have solved using 2 both approaches

// FIRST CODE
#include <bits/stdc++.h>
using namespace std;
#define int long long int
#define pb push_back
int dp[301][301][301];
void solve(int sum, int l1, int l2) {
  l1 <= 300 ? l1 = l1 : l1 = 301;
  l2 <= 300 ? l2 = l2 : l2 = 300;
  printf("%lld\n", dp[300][sum][l2] - (l1 ? dp[300][sum][l1 - 1] : 0));
}
signed main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  //  NOTE:- while solving this problem I thought that we have to solve seperately for every case but we don't nee to do that if cntwe calculate
//   for N=300 we cover all cases
  // below is precalculation for the same
  int N = 300;
  vector<int>a(N);
  for (int i = 0; i < N; i++)a[i] = i + 1;
  for (int i = 0; i <= N; i++)for (int j = 0; j <= N; j++)for (int k = 0; k <= N; k++) {
        if (i == 0 or j == 0)dp[i][j][k] = 0;
        if (j == 0 and k <= N)dp[i][j][k] = 1;
        if (i > 0) {
          if (j - a[i - 1] >= 0 and k > 0) dp[i][j][k] = dp[i][j - a[i - 1]][k - 1] + dp[i - 1][j][k];
          else dp[i][j][k] = dp[i - 1][j][k];
        }
      }

  // in this problem we have to take unknown number of inputs which i have implemented myself and in the ohter code I have
  // inplemented using stringstream
  string s;
  while (getline(cin, s) and s.size()) {
    string sum, l1, l2;
    int cnt = 0;
    for (int i = 0; i < s.size(); i++)if (s[i] == ' ')cnt++;
    if (cnt == 0) {
      sum = s;
      int sm = stoll(sum);
      // if(sm==0)cout<<1<<"\n";
      solve(sm, 0, sm);
    }
    else if (cnt == 1) {
      int i = 0;
      while (s[i] != ' ')sum.pb(s[i++]);
      i++;
      while (i < s.size())l2.pb(s[i++]);
      int l2s = stoll(l2), sm = stoll(sum);
      // cout<<sm<<' '<<l2s;
      solve(sm, 0, l2s);
    }
    else if (cnt == 2) {
      int i = 0;
      while (s[i] != ' ')sum.pb(s[i++]);
      i++;
      while (s[i] != ' ' and i < s.size())l1.pb(s[i++]);
      i++;
      while (i < s.size())l2.pb(s[i++]);
      int l2s = stoll(l2), sm = stoll(sum), l1s = stoll(l1);
      solve(sm, l1s, l2s);
    }
    s.clear();
  }
  return 0;
}

// 2ND CODE using 2d dp and stringstream for unknown number of inputs

#include <stdio.h>
#include<iostream>
#include<sstream>
#include<vector>
#include<cstring>
using namespace std;
#define int long long int
#define pb push_back
int dp[301][301];
void solve(int sum, int l1, int l2) {
  l1 <= 300 ? l1 = l1 : l1 = 300;
  l2 <= 300 ? l2 = l2 : l2 = 300;
  // we are returning l2-l1-1 cuz we have to make atleat l1 amd atmost l2 so we won't consider
  // ways for l1-1
  cout << dp[sum][l2] - (l1 ? dp[sum][l1 - 1] : 0) << "\n";

}
signed main()
{
  //same precalculaion here too
  // but here we are not maintaining an array for coins, we will be using the fact that suppose we will be making every sum possible from 
  // every coin in every iteration or we have made sum till some particular i/index and won't be considering it from now on so we will start from the next
  // value of coin and then for every value of sum we will play whether to take this coin to make the sum or not if we take that then we have 
  // used one coin else we skip it.
  // taking that coin for sum f(j,k)=f(j-i,k-1)+f(j,k) that's it. we don't to define an extra statement 
  // for j-i>=0 as we are taking j>=i always.
  memset(dp, 0, sizeof(dp));
  dp[0][0] = 1;
  for (int i = 0; i <= 300; i++)
    for (int j = i; j <= 300; j++)
      for (int k = 1; k <= 300; k++) {
        dp[j][k] = dp[j - i][k - 1] + dp[j][k];
      }
  char s[1000];
  // this thing i searched from internet to take unknown integer input in cpp 
  while (gets(s)) {
    stringstream sin(s);
    int a[3], n = 0;
    while (sin >> a[n])n++;
    int l1, l2;
    if (n == 1)solve(a[0], 0, a[0]);
    else if (n == 2)solve(a[0], 0, a[1]);
    else if (n == 3)solve(a[0], a[1], a[2]);
  }
  return 0;
}
