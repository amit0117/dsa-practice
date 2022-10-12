# include <bits/stdc++.h> 
  using namespace std;
# define pb push_back
# define int long long
# define inf 1e18
# define eps 1e-8
int n,m,a,b,c;
vector<vector<pair<int,int>>>g;
vector<int>dis,vis;
const int mod=1e9+7; 
void solve(){
cin>>n>>m;
g.resize(n+1),dis.resize(n+1,inf),vis.resize(n+1,false);
for(int i=0;i<m;++i){
  cin>>a>>b>>c;
  g[a].push_back({b,c});
}
priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
pq.push({0,1});
vector<int>path(n+1,0),mn(n+1,inf),mx(n+1,-inf);
path[1]=1;
dis[1]=0;
mn[1]=0,mx[1]=0;
while(!pq.empty()){
  auto curr=pq.top();
  pq.pop();
  int d=curr.first,u=curr.second;
  if(vis[u])continue;
  vis[u]=true;
  for(auto ch:g[u]){
    int v=ch.first,w=ch.second;
    if(dis[v]<dis[u]+w)continue;
    else if(dis[v]==dis[u]+w){
    path[v]+=path[u];
    path[v]%=mod;
    dis[v]=dis[u]+w;
    mn[v]=min(mn[v],mn[u]+1);
    mx[v]=max(mx[v],mx[u]+1);
    // pq.push({dis[v],v});
    }
    else if(dis[v]>dis[u]+w){
    dis[v]=dis[u]+w;
    path[v]=path[u];
    mn[v]=mn[u]+1;
    mx[v]=mx[u]+1;
    pq.push({dis[v],v});
    }
  }
}
cout<<dis[n]<<" "<<path[n]<<" "<<mn[n]<<" "<<mx[n]<<endl;
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