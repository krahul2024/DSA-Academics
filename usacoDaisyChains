#include<bits/stdc++.h>
using namespace std;
// #define int long long int
const int mod=1e9+7;
void solve(){
	int n;
	cin>>n;
	int arr[n];
	for(int i=0;i<n;i++)cin>>arr[i];
	int sum=0,cnt=0;
	for(int i=0;i<n;i++){
		for(int j=i;j<n;j++){for(int k=i;k<=j;k++)sum+=arr[k];
			double x=double(sum)/(double(j-i+1));
			for(int k=i;k<=j;k++)if(double(arr[k])==x){cnt++;break;}
			sum=0;}
	}
	cout<<cnt<<"\n";
}
int main(){
solve();
}
