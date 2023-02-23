#include<bits/stdc++.h> //Header File

using namespace std ;

#define f first
#define s second
#define pb push_back

const int N=1e5+10;
vector<pair<int,int>> gr[N];
int n,m;
int cost=0;

vector<int> dist(N),parent(N);
vector<bool> vis(N); //Part of MST

vector<pair<pair<int,int>,int>> mst;

const int INF = 1e9;

void primsMST(int source){
	for(int i=0;i<n;i++) dist[i]=INF;

	set<pair<int,int>> s;
	dist[source]=0;
	s.insert({0,source});//{cost,vertex}

	while(!s.empty()){
		auto x=*(s.begin());//Least weighted vertex
		s.erase(x);
		vis[x.s]=1;//Node visited
		int u=x.s;
		int v=parent[x.s];
		int w=x.f;
		// cout<<u<<" "<<v<<" "<<w<<endl;
		mst.pb({{u,v},w});
		cost+=w;
		
		for(auto it:gr[x.s]){
			if(vis[it.f]) continue;//If part of MST

			if(dist[it.f]>it.s){
				s.erase({dist[it.f],it.f});
				dist[it.f]=it.s;//Give less dist
				s.insert({dist[it.f],it.f});
				parent[it.f]=x.s;//Update parent
			}
		}
		
	}

}

int main(){

#ifndef ONLINE_JUDGE
	//CodeChef CodeForces
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif

cin>>n>>m;
for(int i=1;i<=m;i++){
	int u,v,w; cin>>u>>v>>w;
	gr[u].pb({v,w});
	gr[v].pb({u,w});
}

primsMST(0);

for(auto x:mst){
	cout<<x.f.f<<" "<<x.f.s<<" "<<x.s<<endl;
}
cout<<cost<<endl;

}