
struct dsu{

int n;
vector<int> parent;
vector<int> siz;

dsu(int x){
    n=x;
    parent.assign(n+1,-1);
    for(int i=1;i<n;i++) parent[i]=i;
    siz.resize(n+1,0);
}

void make(int v){
    siz[v]=1;
    parent[v]=v;
}

int find(int v){
    if(parent[v]==v) return v;
    //Path Compression
    return parent[v]=find(parent[v]);
}

void Union(int a,int b){
    a=find(a);
    b=find(b);
    if(a!=b){ 
        //Union by size
        if(siz[a]<siz[b]) swap(a,b); //a>b always
        parent[b]=a;
        siz[a]+=siz[b];
    }
}

};
