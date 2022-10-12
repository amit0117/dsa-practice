//this problem includes finding cycling then finding 
// the number of teleport we can use dp to optimise 
// otherwise we get tle

// we can start dfs to obtain topological order
// then after this we can run dfs1 to find cycle 
// and store the number of cycle in map to answer quickly
// and for each cycle we assign a unique id to them

// then find function is used to find the number of teleport



# include <bits/stdc++.h> 
  using namespace std;
# define pb push_back
# define int long long
# define inf 1e18
# define eps 1e-8
int n,id=1,res;
vector<vector<int>>g;
unordered_map<int,int>mp;
set<int>st;
vector<int>vis,temp,code,col,dp,tele,topo;
void dfs1(int i){
    vis[i]=true;
    for(auto ch:g[i]){
        if(!vis[ch])
        dfs1(ch);
    }
    topo.push_back(i);
}
void dfs(int i,int par=-1){
   if(col[i]==1){
   vector<int>path;int count=2;
   for(int j=temp.size()-1;j>=0 and count;--j){
   path.push_back(temp[j]);
   code[temp[j]]=id;
   count-=(temp[j]==i);
   }
   mp[id]=path.size()-1;
   st.insert(id);
   id++;
   return;
    }
    else if(col[i]==2)return;
    vis[i]=true;
    col[i]=1;
    for(auto ch:g[i]){
        // if(ch==par)continue;
            temp.push_back(ch);
            dfs(ch,i);
            temp.pop_back();
        
    }
    col[i]=2;
}

int find(int i){
    if(st.count(code[i]))return mp[code[i]];
    if(dp[i]!=-1)return dp[i];
    return dp[i]=1+find(tele[i]);
}


void solve(){
cin>>n;
g.resize(n+1),tele.resize(n+1),code.resize(n+1,-1),dp.resize(n+1,-1),col.resize(n+1),vis.resize(n+1,false),temp.clear();
for(int i=1;i<=n;++i){
    cin>>tele[i];
    g[i].push_back(tele[i]);
}
for(int i=1;i<=n;++i){
    if(!vis[i])
    dfs1(i);
}
reverse(topo.begin(),topo.end());
// for(auto val:topo)cout<<val<<" ";
// cout<<endl;
vis.assign(n+1,false);
for(int i=0;i<n;++i){
    if(!vis[topo[i]]){
        temp.clear();
        temp.push_back(topo[i]);
        dfs(topo[i]);
    }
}
for(int i=1;i<=n;++i){
    cout<<find(i)<<" ";
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