//Stronger Takahashi (Atcoder) 
//https://atcoder.jp/contests/abc213/tasks/abc213_e
const vector<pair<int,int>>change = 
{

{2,-1}, {2,0}, {2,1},
{1,-2}, {1,-1}, {1,0}, {1,1}, {1,2},
{0,-2}, {0,-1}, {0,0}, {0,1}, {0,2},
{-1,-2}, {-1,-1}, {-1,0}, {-1,1}, {-1,2},
{-2,-1}, {-2,0}, {-2,1}

};
void solve(){
    int n,m; cin>>n>>m;
    vector<vector<char>> grid(n,vector<char>(m));
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            cin>>grid[i][j];
    //Cost function of dijkstra's algo is changed 
    //It is number of 2*2 blocks destroyed.
    vvi dist(n,vi(m,1e9));

    priority_queue<vi>pq;
    // pq stores large value first therefore negative to avoid this
    pq.push({0,0,0}); //{-dist,i.j} 
    dist[0][0]=0;
    while(!pq.empty()){
        vi val=pq.top();
        pq.pop();
        int d=val[0],i=val[1],j=val[2];
        if(dist[i][j]!=-d)continue; 
        //Already updated before therefore no worries

        for(auto it:change){
            int di=it.f,dj=it.s;
            int ni=i+di,nj=j+dj;
            //Is safe function
            if(ni<0||ni>=n||nj<0||nj>=m)continue;
            // int cost=(grid[ni][nj]=='.'&&(abs(i-ni)+abs(j-nj)<=1))?0:1;
            int cost=0;
            //When it is pakka ki todna hai then cost = 1 
            // (directly pahuch gaye dur cell par to peeche vale bhi break ho jayenge)
            if(ni==i&&nj==j){
                continue;
            }if(grid[ni][nj]=='#'){
                cost=1;
            }else if(grid[ni][nj]=='.'&&abs(ni-i)+abs(nj-j)==1){
                cost=0;
                //Yaha tak to pakka vala hai
            }else{//directly reachable cells nhi hai but unpe '.' hai
                //Isliye abhi ke liye unpar 1 cost de do higher vali
                //Baad mein yadi pahuchne ka 0 cost vala tarika hua to update
                //ho jayenge.
                //Tough to understand :)    
                cost=1;
            }
            if(dist[ni][nj]<=dist[i][j]+cost) continue; //Relaxing of edges
            
            dist[ni][nj]=dist[i][j]+cost;
            pq.push({-dist[ni][nj],ni,nj});
        }
    }
    cout<<dist[n-1][m-1]<<"\n"; 
    // for(int i=0;i<n;i++){
    //     for(int j=0;j<m;j++){
    //         cout<<grid[i][j]<<" ";
    //     }cout<<"\n";
    // }  
    // for(int i=0;i<n;i++){
    //     for(int j=0;j<m;j++){
    //         cout<<dist[i][j]<<" ";
    //     }cout<<"\n";
    // }   
}
