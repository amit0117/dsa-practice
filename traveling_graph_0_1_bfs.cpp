# include <bits/stdc++.h> 
# define int long long 
# define pb push_back
# define inf (1e9+10)
using namespace std; 
vector<vector<pair<int,int>>>graph(2e5+10);
vector<int>present(2e5+10,0);
vector<int>level(2e5+10,inf);
int o_1_bfs(int start,int des){
    deque<int>dq;
    level[start]=0;
    dq.push_back(start);
    while(dq.size()){
        int curr=dq.front();
        dq.pop_front();
        for( auto child:graph[curr]){
            int child_v=child.first,child_wt=child.second;
            if(level[curr]+child_wt<level[child_v]){
            level[child_v]=level[curr]+child_wt;
            if(child_wt==1)dq.pb(child_v);
            else dq.push_front(child_v);
            }
        }
    }
    return level[des];
}
void reset(int n){
    graph.clear();
    present.clear();
    level.clear();
graph.resize(n+1);
present.resize(n+1,0);
level.resize(n+1,inf);
}
int32_t main(){ 
ios_base::sync_with_stdio(false);
cin.tie(NULL);
cout.tie(NULL);
int t;cin>>t;
while(t--){
int n,m;cin>>n>>m;
reset(n);
for(int i=0;i<m;++i){
    int a,b;cin>>a>>b;
        graph[a].pb({b,0});
        graph[b].pb({a,0});
        // means both are adjacent vertices
    if(abs(a-b)==1){
        present[min(a,b)]=1;
    }
}
for(int i=1;i<n;++i){
    if(present[i]==0){
        graph[i].pb({i+1,1});
        graph[i+1].pb({i,1});
    }
}
cout<<o_1_bfs(1,n)<<endl;
}
return 0;
}