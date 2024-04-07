//Problem C:Book Codeforces
//https://codeforces.com/contest/1573/problem/C
    int n; cin>>n;
    vvi adj(n+1),radj(n+1);//adjacency list and reverse adjacency list
    vi in(n+1);//indegree
    vi vis(n+1);
    vi topo;
    for(int i=1;i<=n;i++){
        int k;
        cin>>k;
        while(k--){
            int x; cin>>x;
            adj[x].pb(i); //x padhne ke baad i padh sakte hai
            radj[i].pb(x);
            in[i]++; //indegree of i badh jayegi
        }
    }
    //Kahn's Algorithm:
    queue<int> q;
    //indegree=1 push karo
    for(int i=1;i<=n;i++){
        if(in[i]==0){
            q.push(i);
        }
    }
    while(!q.empty()){
        int u=q.front();
        q.pop();
        topo.pb(u);
        vis[u]=1;
        for(int v:adj[u]){//Release indegree of children from u to v
            if(--in[v]==0)
                q.push(v);
        }
    }
    // dbg(topo);
    if(topo.size()!=n){
        cout<<"-1\n";
        return;
    }

//Not related to Kahn's Algo
    vi dp(n+1,1);
    //'u' se v1,v2, .. . vk ko dekho jo pehle khatam karne the 'u' se
    for(int u:topo){
        for(int v:radj[u]){
            if(u>v){
                //same reading mein kar lunga kaam
                dp[u]=max(dp[u],dp[v]);
            }else{
                //extra reading lagegi
                dp[u]=max(dp[u],dp[v]+1);
            }
        }
    }
    // cout<<dp<<"\n";
    cout<<mxe(dp)<<"\n";
