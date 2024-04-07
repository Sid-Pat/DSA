//Euler Tour Traversal
int n=2e5+5;
vector<set<int>> adj(n);
vi vis(n);
vi path;
void dfs(int u,int p){
    vis[u]=1;
    path.pb(u);
    for(auto v:adj[u]){
        if(vis[v]==1) continue;
        dfs(v,u);
        path.pb(u);
    }
}
void solve(){
    int n; cin>>n;
    for(int i=1;i<=n-1;i++){
        int u,v; cin>>u>>v;
        adj[u].insert(v);
        adj[v].insert(u);
    }
    dfs(1,-1);
    cout<<path<<"\n";
}
