#include<bits/stdc++.h> //Header File
// Reverse Ackerman function
#define f first
#define s second
using namespace std ;
const int N=1e5+10;
int parent[N];
int siz[N];

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

int main(){

#ifndef ONLINE_JUDGE
	//CodeChef CodeForces
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif

int n,m;
cin>>n>>m;

vector<pair<int,pair<int,int>>> edges;

for(int i=0;i<m;i++){
	int u,v,wt; cin>>u>>v>>wt;
	edges.push_back({wt,{u,v}});
}

sort(edges.begin(),edges.end());

for(int i=1;i<=n;i++) make(i);


int totalCost = 0;
for(auto x:edges){
	int wt = x.f;
	int u = x.s.f;
	int v = x.s.s;

	if(find(u)==find(v)) continue;
	Union(u,v);
	totalCost+=wt;
	cout<<u<<" "<<v<<endl;
}
cout<<totalCost<<endl;

}
/*
Input:
6 9
5 4 9
1 4 1
5 1 4
4 3 5
4 2 3
1 2 2
3 2 3
3 6 8
2 6 7
*/
/*
Output:
1 4
1 2
3 2
5 1
2 6
17
*/