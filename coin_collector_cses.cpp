# include <bits/stdc++.h> 
  using namespace std;
# define pb push_back
# define int long long
# define inf 1e18
# define eps 1e-8
int n,m,a,b,id=0;
vector<vector<int>>g,rg;
vector<int>vis,topo,new_topo,c,new_c,code;
set<int>st;
vector<pair<int,int>>edge;
void dfs1(int i){
  vis[i]=true;
  for(auto ch:g[i]){
    if(!vis[ch])
    dfs1(ch);
  }
  topo.push_back(i);
}
void dfs2(int i){
vis[i]=true;
code[i]=id;
new_c[id]+=c[i];
for(auto ch:rg[i]){
  if(!vis[ch]){
    dfs2(ch);
  }
}
}

void solve(){
cin>>n>>m;
edge.clear(),g.resize(n+1),rg.resize(n+1),vis.resize(n+1,false),topo.clear(),new_topo.clear(),c.resize(n+1),new_c.resize(n+1),code.resize(n+1);
for(int i=1;i<=n;++i)cin>>c[i];
for(int i=1;i<=m;++i){
  cin>>a>>b;
  g[a].push_back(b);
  rg[b].push_back(a);
  edge.push_back({a,b});
}
for(int i=1;i<=n;++i){
  if(!vis[i])dfs1(i);
}
vis.assign(n+1,false);
reverse(topo.begin(),topo.end());
for(int i=0;i<n;++i){
  if(!vis[topo[i]]){
    dfs2(topo[i]);
    id++;
  }
}
for(int i=0;i<n;++i){
  if(st.count(code[topo[i]]))
  continue;
  new_topo.push_back(code[topo[i]]);
  st.insert(code[topo[i]]);
}
vector<vector<int>>new_g(id);
for(int i=0;i<edge.size();++i){
  int u=edge[i].first,v=edge[i].second;
  if(code[u]!=code[v]){
new_g[code[u]].push_back(code[v]);
  }
}
vector<int>dp(id+1,0);
for(int i=new_topo.size()-1;i>=0;--i){
  int u=new_topo[i];
  for(auto ch:new_g[u])
  dp[u]=max(dp[u],dp[ch]);
  dp[u]+=new_c[u];
}
int ans=0;
for(int i=1;i<=n;++i){
  ans=max(ans,dp[code[i]]);
}
cout<<ans<<endl;
}
int32_t main(){ 
ios_base::sync_with_stdio(false);
cin.tie(NULL);
cout.tie(NULL);
int t;
// cin>>t;
t=1;
while(t--){
solve();
}
return 0;
}