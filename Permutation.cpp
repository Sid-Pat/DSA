#include<bits/stdc++.h> //Header File
// https://www.youtube.com/watch?v=5hGCIzeKVrA
using namespace std ;

void f(int i,int n,vector<int> &ds,vector<bool> &used,vector<int> &v){
    if(ds.size()==n){
        for(int j=0;j<n;j++) cout<<ds[j]<<" ";   
            cout<<endl;
        return;
    }

    for(int k=0;k<n;k++){
        if(!used[k]){
            used[k]=1;
            ds.push_back(v[k]);
            f(i+1,n,ds,used,v);
            used[k]=0;
            ds.pop_back();
        }
    }

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
vector<bool> used(n,0);
vector<int> ds;
// f(0,n,ds,used,v);


//Always sort vector before sending to next permutation
//as it gives next permuatation greater in rank from previous one
//else it will not show previous permutation
sort(v.begin(),v.end());

//do..while() as we want initial permutation given to be the part
do{
    for(int i=0;i<n;i++) cout<<v[i]<<" ";
        cout<<endl;
}while(next_permutation(v.begin(),v.end()));



}
