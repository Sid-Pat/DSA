const int N = 2e5+10;

struct Node{
    int prefix;
    int sum;
};

vi ar(N);
vector<Node> st(4*N);

void mergeResult(int si){
    st[si].sum = st[2*si].sum + st[2*si+1].sum;
    st[si].prefix = max({st[2*si].prefix, st[2*si].sum + st[2*si+1].prefix,0ll});
                    //left subarray max part , left array sum + right subarray max part
}

void buildTree(int si,int ss,int se){
    if(ss==se){
        st[si].prefix = st[si].sum = ar[ss];
        return;
    }

    int mid = (ss+se)/2;

    buildTree(2*si,ss,mid);
    buildTree(2*si+1,mid+1,se);
    mergeResult(si);
}

Node query(int si,int ss,int se,int qs,int qe){
    if(qs>se || qe<ss){
        Node temp;
        temp.sum = temp.prefix = 0;
        return temp;
    }

    if(qs<=ss && se<=qe) return st[si]; //maximum sum in this range 

    int mid = (ss+se)/2;

    Node l = query(2*si,ss,mid,qs,qe);
    Node r = query(2*si+1,mid+1,se,qs,qe);

    Node res;
    res.sum = l.sum + r.sum;
    res.prefix = max({l.prefix , l.sum+r.prefix , 0ll});
    return res;
}

void update(int si,int ss,int se,int q){
    if(ss==se){
        st[si].prefix = st[si].sum = ar[ss];
        return;
    }

    int mid = (ss+se)/2;

    if(q<=mid) update(2*si,ss,mid,q);
    else update(2*si+1,mid+1,se,q);

    mergeResult(si);
}

void solve(){
    int n,q,t,k,u,a,b;

    cin>>n>>q;
    
    for(int i=1;i<=n;i++) cin>>ar[i];

    buildTree(1,1,n);

    while(q--){
        cin>>t;
        if(t==1){
            cin>>k>>u;
            ar[k] = u;
            update(1,1,n,k);
        }else{
            cin>>a>>b;
            cout<<max(0ll, query(1,1,n,a,b).prefix)<<endl;
        }
    }

    // cout<<v<<"\n";
}
