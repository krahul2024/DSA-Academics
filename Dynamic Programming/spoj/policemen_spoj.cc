#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 11,mod=1000000007;
int table[N][18];
vector<int>depth(N,0),g[N];
void dfs(int x,int p){
	for(auto i:g[x])if(i!=p) depth[i]=depth[x]+1,table[i][0]=x,dfs(i,x);
}

int lca(int x,int y){
	if(depth[x]<depth[y])swap(x,y);//just that our assumption of x is always deeper than y remains correct
	int diff=depth[x]-depth[y];
	for(int i=0;i<18;i++)if(diff &(1<<i))x=table[x][i];//each time  we find any bit set we lift x upto that point
	if(x==y)return x;
	for(int i=17;i>=0;i--)if(table[x][i]!=table[y][i])x=table[x][i],y=table[y][i];
	return table[x][0];
}


int main() {
	int n,x,y;
	cin>>n;
	for(int i=1;i<n;i++){
		cin>>x>>y; g[x].push_back(y); g[y].push_back(x);
	}
	//first of all we have to calculate the depth and then initial parent of each of the nodes 
	table[1][0]=1; dfs(1,-1);
	//now filling the table
	for(int j=1;j<=17;j++)
		for(int i=1;i<=n;i++) table[i][j]=table[table[i][j-1]][j-1];
	//now finding the lca and printing the values
	int q;
	cin>>q;
	while(q--){
		int a,b;
		cin>>a>>b;
		if(depth[a]<depth[b])cout<<"NO\n";
		else cout<<"YES "<<lca(a,b)<<'\n';
	}
}
