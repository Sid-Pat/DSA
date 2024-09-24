
pair<int,vi> LIS(vi &a){
    int n = a.size();
    int dp[n];
    int dpi[n];
    for(int i=0;i<n;i++) dp[i]=0;
    for(int i=0;i<n;i++){
        dp[i] = 1;
        dpi[i] = i;
        for(int j=0;j<i;j++){
            if(a[j]<a[i]){ //If we can use the previous segment then use that best answer
                if(dp[i]<dp[j]+1){
                    dp[i]=dp[j]+1;
                    dpi[i]=j;
                }
            }
        } 
    }
    int ans = 0;
    int id = 0;
    for(int i=0;i<n;i++){
        if(ans<dp[i]){
            ans = dp[i];
            id = i;
        }
    }
    vi res;
    res.pb(a[id]);
    while(dpi[id]!=id){
        id = dpi[id];
        res.pb(a[id]);
    }
    reverse(all(res));
    return {ans,res};
}
    
void solve(){
    vi a = {50,4,10,8,30,100};
    pair<int,vi> lis = LIS(a);
    cout<<lis.first<<"\n";
    cout<<lis.second<<"\n";
    return;
}
