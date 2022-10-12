# include <bits/stdc++.h> 
  using namespace std;
# define pb push_back
# define int long long
# define inf 1e18
# define eps 1e-8
int n,m,a,b;
vector<vector<int>>g,rg;
vector<int>vis,comp,topo;
void dfs1(int i){
    vis[i]=true;
    for(auto ch:g[i]){
        if(!vis[ch])
        dfs1(ch);
    }
    topo.push_back(i);
}

void dfs2(int i){
    comp.push_back(i);
    vis[i]=true;
    for(auto ch:rg[i]){
        if(!vis[ch])
        dfs2(ch);
    }
}
void solve(){
cin>>n>>m;
g.resize(n+1),vis.resize(n+1,false),comp.clear(),rg.resize(n+1),topo.clear();
for(int i=1;i<=m;++i){
    cin>>a>>b;
    g[a].push_back(b);
    rg[b].push_back(a);
    }
for(int i=1;i<=n;++i)if(!vis[i])dfs1(i);
vis.assign(n+1,false);
int count=0;
reverse(topo.begin(),topo.end());
for(int i=0;i<topo.size();++i){
    if(!vis[topo[i]])
    {   count++;
        comp.clear();
        dfs2(topo[i]);
    }
}
if(count==1)cout<<"YES"<<endl;
else {
    cout<<"NO"<<endl;
    set<int>st(comp.begin(),comp.end());
    for(int i=1;i<=n;++i){
        if(st.find(i)==st.end()){
           a=i;
            break;
        }
    }
    cout<<*st.begin()<<" "<<a<<endl;

}
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