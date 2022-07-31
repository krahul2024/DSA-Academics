#include <bits/stdc++.h>
using namespace std;
//one test case is wrong from this answer I didn't debug this as I had solved from myself
//logic : I am searching for all possible numbers in the range a[i]+/-k:k{1,.... until i don't find any new index then take difference
// of these indexes }. I have used binary search one can use sets and maps in this problem.
#define pb push_back
#define f first
#define s second
int f1(vector<int>a,int k,int n){
  if(k>=a[n-1]) return n-1;
  int i=0,j=n-1,mid;
  while(i<=j){
    mid=i+(j-i)/2;
    if(a[mid]<=k and a[mid+1]>k) return mid;
    else if(a[mid]>k)j=mid-1;
    else if(a[mid]<k)i=mid+1;
  }
  return -1;
}
int f2(vector<int>a,int k,int n){
  if(k<=a[0]) return 0;
  int i=0,j=n-1,mid;
  while(i<=j){
    mid=i+(j-i)/2;
    if(a[mid]>=k and a[mid-1]<k) return mid;
    else if(a[mid]>k)j=mid-1;
    else if(a[mid]<k)i=mid+1;
  }
  return -1;
}
void solve(){
  freopen("angry.in", "r", stdin);
	freopen("angry.out","w", stdout);
  int n;
  cin>>n;
  vector<int>a(n);
  map<int,bool>mark;
  for(int i=0;i<n;i++)cin>>a[i];
  sort(a.begin(),a.end());
  // for(auto i:a)cout<<i<<"\n";
  int mx=0;
  for(int i=0;i<n;i++){
    int k=1,num1=a[i]+k,num2=a[i]-k,mxi=0;
    while(1){
      k++;
      int x=f1(a,num1,n),y=f2(a,num2,n);
      // cout<<x<<" "<<y<<",";
      if(mark[x] and mark[y] or x==y){mxi=x-y+1;break;}
      if(!mark[x]){
        mark[x]=1;
        num1=a[x]+k;
      }
      if(!mark[y]){
        mark[y]=1;
        num2=a[y]-k;
      }
    }
    // cout<<"\n";
    mark.clear();
    mx=max(mxi,mx);
  }
  cout<<mx<<"\n";
}
int main() 
{
  // int t;
  // cin>>t;
  // while(t--)
   solve();
}
