struct DSU{
    int n;
    vi leader,size;
    DSU(int _n){
        n=_n;
        leader.assign(n+1,0);
        size.assign(n+1,0);
        for(int i=1;i<=n;i++){
            leader[i]=i;
            size[i]=1;
        }
    }
    int FindLeader(int a){
        if(leader[a]==a)return a;
        return leader[a]=FindLeader(leader[a]);
    }
    void Merge(int a,int b){
        a=FindLeader(a), b=FindLeader(b);
        if(a==b)return;//Same group
        leader[b]=a;
        size[a]+=size[b];
    }
};
