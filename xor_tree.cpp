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

