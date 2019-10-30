#include<bits/stdc++.h>
using namespace std;
#define pb(x) push_back(x)
#define mp(x,y) make_pair(x,y)
#define F first
#define S second
#define forit(it,cont) for(auto it=cont.begin();it!=cont.end();it++)
#define for0(i,n) for(i=0;i<n;i++)
#define for1(i,n) for(i=1;i<=n;i++)
#define for0r(i,n) for(i=n-1;i>=0;i--)
#define for1r(i,n) for(i=n;i>=1;i--)
#define ll long long 
vector<ll> adj[100010];
vector<ll> lvl(100010);
vector<ll> init(100010);
vector<ll> goal(100010);
vector<ll> vis(100010);
ll len=0,ans[100010];
void dfs1(ll s,ll level)
{
	vis[s]=1;
	lvl[s]=level+1;
	forit(it,adj[s])
	{
		if(!vis[*it])
			dfs1(*it,lvl[s]);
	}
}

void dfs2(ll s,ll evenl,ll oddl)
{
	vis[s]=1;
	if(lvl[s]%2==0&&evenl%2==1)
			init[s]^=1;
	if(lvl[s]%2==1&&oddl%2==1)
			init[s]^=1;
	if(init[s]!=goal[s])
	{
		if(lvl[s]%2==0)evenl++,ans[++len]=s;
		else oddl++,ans[++len]=s;
	}
	forit(it,adj[s])
	{
		if(!vis[*it])
			dfs2(*it,evenl,oddl);
	}
}
int main()
{
	ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	ll n,i,u,v;
	cin>>n;
	for1(i,n-1)
	cin>>u>>v,adj[u].pb(v),adj[v].pb(u);
	for1(i,n)
	cin>>init[i];
	for1(i,n)
	cin>>goal[i];
	dfs1(1,-1);
	vis.assign(100010,0);
	dfs2(1,0,0);
	cout<<len<<endl;
	for1(i,len)
	cout<<ans[i]<<endl;
	return 0;	
}
