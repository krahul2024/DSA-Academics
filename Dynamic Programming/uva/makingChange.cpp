// bit manipulation stuff
#include <bits/stdc++.h>
// #define int long long int
#define pb push_back
using namespace std;
const int mod=1e9+7;
int dig(int x){
  return log10(x)+1;
}
void solve(int x[],float vl){
	int coins[6]={5,10,20,50,100,200},c0=0;
	vector<int>a;
	for(int i=0;i<6;i++){
		int l=x[i];
		while(l--){
			a.pb(coins[i]);
		}
	}
	int val=(int)(vl*100.0);
	if(val%5!=0)val=(val/5)*5+5;
// 	cout<<val;
	int sum=0;
	for(auto i:a)sum+=i;
		int n=a.size();
	vector<int>sumArr;
	bool dpSum[sum+11][n+11];
		for(int i=0;i<=sum;i++){
			for(int j=0;j<=n;j++){
				// cout<<i<<" "<<j<<"\n";
				dpSum[i][j]=0;
				if(j==0)dpSum[i][j]=0;
				if(i==0)dpSum[i][j]=1;
				else if(a[j-1]<=i)dpSum[i][j]=dpSum[i][j-1] or dpSum[i-a[j-1]][j-1];
				else dpSum[i][j]=dpSum[i][j-1];
				// cout<<dpSum[i][j]<<' ';
			}
		// 	cout<<"\n";
			if(dpSum[i][n] and i%5==0 and i>=val)sumArr.pb(i);
		}
		// cout<<n<<" "<<sum<<'\n';
// 	int dpw[n+1][val+1];
// 	for(int i=0;i<=n;i++){
// 	  for(int j=0;j<=val;j++){
// 	    if(i==0)dpw[i][j]=0;
// 	    if(j==0)dpw[i][j]=0;
// 	    if(i>0){
// 	      if(a[i-1]<j)dpw[i][j]=dpw[i-1][j-a[i-1]]+1,dpw[i-1][j];
// 	      else dpw[i][j]=dpw[i-1][j];
// 	    }
// 	  }
// 	}
// 	cout<<dpw[n][val]<<'\n';
	int dpchange[n+1][sum+1];
	for(int i=0;i<=n;i++){
	  for(int j=0;j<=sum;j++){
	    if(i==0)dpchange[i][j]=mod;
	    if(j==0)dpchange[i][j]=0;
	    if(i>0){if(j>=a[i-1])dpchange[i][j]=min(dpchange[i-1][j-a[i-1]]+1,dpchange[i-1][j]);
	    else dpchange[i][j]=dpchange[i-1][j];}
	  }
	}
vector<int>retArr;
for(auto i:sumArr)if(i>=val)retArr.pb(i-val);
// for(auto i:sumArr)cout<<i<<" ";
  int dp[7][sum-val+1];
  for(int i=0;i<=7;i++)for(int j=0;j<=sum-val;j++){
    if(i==0)dp[i][j]=mod;
    if(j==0)dp[i][j]=0;
    if(i>0){
      if(coins[i-1]<=j)dp[i][j]=min(1+dp[i][j-coins[i-1]],dp[i-1][j]);
      else dp[i][j]=dp[i-1][j];
    }
  }
  // for(auto i:retArr)cout<<i<<' '<<dp[7][i]<<'\n';
  int vx=sumArr[0];
  int mn=dpchange[n][vx]+dp[7][vx-val];
  for(int i=1;i<sumArr.size();i++)mn=min(mn,dp[7][sumArr[i]-val]+dpchange[n][sumArr[i]]);
  int k=dig(mn);
  k=3-k;
  while(k--)cout<<' ';
  cout<<mn<<"\n";
}
signed main() 
{
    bool yes=1;
   while(yes){
     int x[6],sum=0;
     float val;
     for(int i=0;i<6;i++)cin>>x[i],sum+=x[i];
     if(sum==0) return 0;
     else{
       cin>>val;
       solve(x,val);
     }
   }
    

}
