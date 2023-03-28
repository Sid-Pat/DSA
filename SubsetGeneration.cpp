#include<bits/stdc++.h> //Header File
// https://www.youtube.com/watch?v=5hGCIzeKVrA
using namespace std ;

// Code Daily
// Subset Way - 1 (Recursion):

//Removing too therefore we can pass ds as refrence
void f(int i,vector<int> &v,int n,vector<int>& ds){
    if(i==n){
        for(int id=0;id<ds.size();id++) cout<<ds[id]<<" ";
            cout<<endl;
        return;
    }

    //not take
    f(i+1,v,n,ds);
    ds.push_back(v[i]);
    f(i+1,v,n,ds);
    ds.pop_back();
}

int main(){

#ifndef ONLINE_JUDGE
    //CodeChef CodeForces
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif

int n; cin>>n;
vector<int> v(n);
for(int i=0;i<n;i++) cin>>v[i];
vector<int> ds;
// f(0,v,n,ds);

//Subset Way - 2 //Bit Manipulation
for(int i=0;i<(1<<n);i++){
    for(int j=0;j<n;j++){
        if(i&(1<<j)){
            cout<<v[j]<<" ";
        }
    }
    cout<<endl;
}

return 0;

}
