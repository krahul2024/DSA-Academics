// This problem is divided into two parts. 
// 1.Array formation
// Initially we are given an array , we have to add w coins to each box in  range l,r, a total of q times.
// This query thing can be done in two ways one is brute force way in which we take a range l,r, iterate over all the elements in range l,r and add w to each one of them. This adding w on range takes O(n) time so for q queries it is overall N*Q time, which will time-out.
// Second Way is take an additional array of 0s. For any given range l,r,w : add w to additional[l-1] and subtract w from additional[r], do this for all Q queries. After all the queries are done Take prefix sum of additional array. 
// Now add additional[i] to corresponding original given arr[i], we will get same resultant array as we get doing in first way.  This takes just Q time.
// Illustration of second way

int original[N], additional[N+1]={0};
for(int i=1;i<=Q;i++){
int l,r,w; cin>>l>>r>>w;
    additional[l-1]+=w;
    additional[r]-=w;
}
original[0]+=additional[0]//adding first element.
for(int i=1;i<N;i++)additional[i]+=additional[i-1],original[i]+=additional[i];

// 2.Dynamic programming part 
// We will be using dp on ranges for solving this problem. 
// See the solution for more understanding , if having some trouble then try solving problems on mcm dp and then approach this problem.

// Code for the same in c++:

#include<bits/stdc++.h>
using namespace std;
#define int long long int
int loss[605][605],inflation[605][605],coins[605],N,Q,K;

int f(int i,int j){
    if(i==j ) return 0;
    if(loss[i][j]!=-1)return loss[i][j];
    int value=INT_MAX,sum;
    for(int k=i;k<j;k++){
        sum=f(i,k)+f(k+1,j)+(inflation[i][k]^inflation[k+1][j]);
        if(sum<value)value=sum,inflation[i][j]=(inflation[i][k]+inflation[k+1][j])%K;
    }
    return loss[i][j]=value;
}

signed main(){
    cin>>N>>Q>>K; vector<int>extra(N+1,0);
    for(int i=0;i<N;i++)cin>>coins[i];
    for(int i=0;i<Q;i++){
        int l,r,w; cin>>l>>r>>w;
        extra[l-1]+=w,extra[r]-=w;
    }
    coins[0]+=extra[0];
    for(int i=1;i<=N;i++)coins[i]+=(extra[i]+=extra[i-1]);
    for(int i=0;i<N;i++)inflation[i][i]=coins[i];
    for(int i=0;i<=N;i++)for(int j=0;j<=N;j++)loss[i][j]=-1;
    cout<<f(0,N-1)<<'\n';
}

// Time complexity: O(N^3+N^2+Q) , N is size of the array and Q is number of queries.




