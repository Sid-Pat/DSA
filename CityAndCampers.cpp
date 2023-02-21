#include<bits/stdc++.h>
using namespace std ;

#define int long long int 
#define f first
#define s second
#define pb push_back
#define rep(a, c) for (int(a) = 0; (a) < (c); (a)++)
#define repl(a, b, c) for (int(a) = (b); (a) <= (c); (a)++)
typedef vector<int> vi;
typedef pair<int, int> pi;
const int mod=(int)1e9+7;
void fast_file(){
	ios::sync_with_stdio(false); cin.tie(0);
	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	#endif
}

const int N=1e5+1;
multiset<int> m;
int parent[N];
int siz[N];

void make(int v){
	parent[v]=v;
	siz[v]=1;
	m.insert(1);
}

int find(int v){
	if(parent[v]==v) return v;
	//Path Compression
	return parent[v]=find(parent[v]);
}

void merge(int a,int b){
	m.erase(m.find(siz[a]));
	m.erase(m.find(siz[b]));
	m.insert(siz[a]+siz[b]);
}

void Union(int a,int b){
	a=find(a);
	b=find(b);
	if(a!=b){ 
		//Union by size
		if(siz[a]<siz[b]) swap(a,b); //a>b always
		parent[b]=a;
		merge(a,b);
		siz[a]+=siz[b];
	}
}

int32_t main(){
fast_file();

int tc=1; 
// cin>>tc;
while(tc--){
	int n,q; cin>>n>>q;

	for(int i=1;i<=n;i++) make(i);

	while(q--){
		int a,b; cin>>a>>b;
		Union(a,b);
		if(m.size()==1) cout<<0<<endl;
		else cout<<1<<endl;

	}

}


return 0;
}