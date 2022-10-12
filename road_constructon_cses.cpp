# include <bits/stdc++.h> 
  using namespace std;
# define pb push_back
# define int long long
# define inf 1e18
# define eps 1e-8
int n,m,component;
vector<int>par,Size;
set<int>st;
void make(int i){
    par[i]=i;
    Size[i]=1;
    st.insert(Size[i]);
}
int find(int a){
    if(par[a]==a)return a;
    return par[a]=find(par[a]);
}
void Union(int a,int b){
    a=find(a),b=find(b);
    if(a!=b){
        if(Size[a]<Size[b])
        swap(a,b);
        par[b]=a;
        st.erase(find(Size[a]));
        st.erase(find(Size[b]));
        Size[a]+=Size[b];
        st.insert(Size[a]);
    }
}
 
void solve(){
cin>>n>>m;
par.resize(n+1),Size.resize(n+1,0);
component=n;
for(int i=1;i<=n;++i)make(i);
int a,b;
for(int i=1;i<=m;++i){
    cin>>a>>b;
    if(find(a)!=find(b)){
        component--;
        Union(a,b);
    }
    cout<<component<<" "<<(*--st.end())<<endl;
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