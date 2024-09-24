
bool comp(vi &a,vi &b){
    return (a[2]<b[2]); //Based on height
}

int boxStacking(vvi &b){
    int n = b.size();
    sort(all(b),comp);
    int dp[n+1];
    for(int i=0;i<=n;i++) dp[i]=0;
    for(int i=1;i<=n;i++){
        dp[i] = b[i-1][2];
        for(int j=1;j<i;j++){
            if(b[j-1][0]<b[i-1][0] && b[j-1][1]<b[i-1][1] && b[j-1][2]<b[i-1][2])
                dp[i] = max(b[i-1][2]+dp[j],dp[i]);
        }
    }
    int ans = 0;
    for(int i=0;i<=n;i++){
        ans = max(dp[i],ans);
    }
    return ans;
}

    
void solve(){
    //Box Stacking Problem
    //w x d x h
    vvi boxes = {
        {2,1,2},
        {3,2,3},
        {2,2,8},
        {2,3,4},
        {2,2,1},
        {4,4,5},
    };
    int ht = boxStacking(boxes);
    cout<<ht<<"\n";
    return;
}
