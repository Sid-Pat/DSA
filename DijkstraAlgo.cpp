#include<bits/stdc++.h>
using namespace std ;

#define int long long int 
#define f first
#define s second
#define pb push_back

const int N=1e5+10;
const int inf = 1e12;
vector<pair<int,int>> gr[N];
vector<int> dist(N,inf);

void fast_file(){
	ios::sync_with_stdio(false); cin.tie(0);
	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	#endif
}

int32_t main(){
fast_file();

int n,m; cin>>n>>m;

for(int i=0;i<m;i++){
	int u,v,w; cin>>u>>v>>w;
	gr[u].pb({v,w});
	gr[v].pb({u,w});
}

int source; cin>>source;

dist[source]=0;
set<pair<int,int>> s; //{wt,vertex}
s.insert({0,source});

while(!s.empty()){
	auto x = *(s.begin());
	s.erase(x);

	for(auto it:gr[x.s]){
		if(dist[it.f]>dist[x.s]+it.s){
			s.erase({dist[it.f],it.f});
			dist[it.f]=dist[x.s]+it.s;
			s.insert({dist[it.f],it.f});
		}
	}
}

for(int i=1;i<=n;i++){
		if(dist[i]<inf){
			cout<<dist[i]<<" ";
		}
		else cout<<"-1"<<endl; //Never updated
	}
	cout<<endl;

return 0;
}