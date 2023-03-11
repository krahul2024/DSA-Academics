// Let's break this problem in three parts.
// 1.Distance between two nodes dist(x,y).
// 2.For this part, we have to find sum of distances of a node from all of its multiples. 
// Like for 2 we have to find dist(2,2)+dist(2,4)+......+dist(2,2*i) where i<=N/2
// this sum of distances for 2 or any node is defined as Strength(2) or Strength(any_node).

// 3.Greatness(planet) is Sum of strengths of all the nodes on the planet.

// We are given N nodes, N-1 edges, N unique paths such that there exists exactly one path between two nodes. All these properties tell us given planet is a tree.

// For finding distance we can use brute force approach which is just iterating to all every possible node and its multiple pair, then we have to do this thing for N nodes and then adding all of them to find greatness.

// for(int i=1;i<=N;i++) for(int j=1;j<=N;j++) if(j%i==0)sum+=distance(i,j); --> N*N*N --> O(N^3)
// slight modification in second for loop, we can iterate over multiples of any node directly without running the loop N times and this makes complexity to N*(logN)*N -----> O((N^2)*logN)

// If we use LCA to find distance, then we can reduce distance finding thing in logN which makes complexity a lot better
// , which is N*(logN)*(logN) ---> O(N(logN)*(logN)) 

// I am not explaining LCA here , Interested people can read more about it following this link:

// https://www.geeksforgeeks.org/lowest-common-ancestor-binary-tree-set-1/

// code for the same in c++:

#include<bits/stdc++.h>
using namespace std;
#define int long long int
const int N=2e5+11,mod=1e9+7;
vector<int>g[N],depth(N,0);
int table[N][21];

void dfs(int x,int p){
    for(auto i:g[x])if(i!=p)depth[i]=depth[x]+1,table[i][0]=x,dfs(i,x);
}

int lca(int x, int y){
    if(depth[x]<depth[y])swap(x,y);
    int diff=depth[x]-depth[y];
    for(int i=0;i<=19;i++) if(diff & (1<<i))x=table[x][i];
    if(x==y) return x;
    for(int i=19;i>=0;i--) if(table[x][i]!=table[y][i]) x=table[x][i],y=table[y][i];
    return table[x][0];
}

int distance(int x,int y){
    int l=lca(x,y);
    return depth[x]+depth[y]-2*depth[l];
}

signed main(){
    int n,ans=0;  cin>>n;
    for(int i=1;i<=n-1;i++){
        int x,y; cin>>x>>y; 
        g[x].push_back(y);
        g[y].push_back(x);
    }
    table[1][0]=1, dfs(1,0);
    for(int i=1;i<=19;i++) for(int j=1;j<=n;j++)table[j][i]=table[table[j][i-1]][i-1];
    for(int i=1;i<=n;i++)for(int j=i;j<=n;j+=i)ans+=distance(i,j);
    cout<<ans<<'\n';
}

// Time Complexity: O(N*(logN)*(logN)) where N is number of nodes.
