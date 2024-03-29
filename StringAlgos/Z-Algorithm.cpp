#include "bits/stdc++.h"
#define int long long
#define uint unsigned long long
#define f first
#define s second
#define pb push_back
#define vi vector<int>
#define vvi vector<vi>
#define vb vector<bool>
#define vvb vector<vb >
#define fr(i,n) for(int i=0; i<(n); i++)
#define rep(i,a,n) for(int i=(a); i<=(n); i++)
#define nl cout<<"\n"
#define dbg(var) cout<<#var<<"="<<var<<" "
#define all(v) v.begin(),v.end()
#define sz(v) (int)(v.size())
#define srt(v)  sort(v.begin(),v.end())         // sort 
#define mxe(v)  *max_element(v.begin(),v.end())     // find max element in vector
#define mne(v)  *min_element(v.begin(),v.end())     // find min element in vector
#define unq(v)  v.resize(distance(v.begin(), unique(v.begin(), v.end())));
// make sure to sort before applying unique // else only consecutive duplicates would be removed 
using namespace std;

int MOD=1e9+7;      // Hardcoded, directly change from here for functions!



// ================================== take ip/op like vector,pairs directly!==================================
template<typename typC,typename typD> istream &operator>>(istream &cin,pair<typC,typD> &a) { return cin>>a.first>>a.second; }
template<typename typC> istream &operator>>(istream &cin,vector<typC> &a) { for (auto &x:a) cin>>x; return cin; }
template<typename typC,typename typD> ostream &operator<<(ostream &cout,const pair<typC,typD> &a) { return cout<<a.first<<' '<<a.second; }
template<typename typC,typename typD> ostream &operator<<(ostream &cout,const vector<pair<typC,typD>> &a) { for (auto &x:a) cout<<x<<'\n'; return cout; }
template<typename typC> ostream &operator<<(ostream &cout,const vector<typC> &a) { int n=a.size(); if (!n) return cout; cout<<a[0]; for (int i=1; i<n; i++) cout<<' '<<a[i]; return cout; }
// ===================================END Of the input module ==========================================



//==================================== compute higher powers with mod ===================================
uint power(int x, int y, int p =  MOD)
{
    unsigned long long res = 1;

    x = x % p;
    while (y > 0)
    {

        if (y & 1)
            res = (res * x) % p;

        y = y >> 1;
        x = (x * x) % p;
    }
    return res;
}

// =============================================================================================================

uint modInverse(int n, int p=MOD)       // using fermats little thm. [p needs to be prime which is mostly the case as mod value generally is 1e9+7]
{
    return power(n, p - 2, p);
}
// can also derive this using extended euclidean... however this has a much simpler code....


// =========================================Used to calculate nCr of higher values ===================================
uint nCr(int n, int r, int p=MOD)     // faster calculation.. 
{
    if (n < r)
        return 0;

    if (r == 0)
        return 1;
        
    vector<int> fac(n+1,0);
    fac[0] = 1;
    for (int i = 1; i <= n; i++)
        fac[i] = (fac[i - 1] * i) % p;

    return (fac[n] * modInverse(fac[r], p) % p * modInverse(fac[n - r], p) % p) % p;
}


// ==================================BINARY SEARCH MODULE=========================================
bool poss(int mid,vector<int>& arr){        // evaludate the condition!
    if(mid)   return mid;
    return 1;
}

int BinSearch(vector<int>& arr ,int lo,int hi, bool pos=1){      // pos means find max ...
    int res=-1;
    while(lo<=hi){
        int mid=(lo+hi+1)/2;
        if(poss(mid,arr)){
            res=mid;
            if(pos)    lo=mid+1;
            else hi=mid-1;
        }
        else{
            if(pos)    hi=mid-1;
            else lo=mid+1;
        }
    }
    return res;
}

// =====================================END of BinSearch Module=========================================
/// ====================================PRIME utility ==================================================
// int sz=1e6+5;
// bool PrimeSieve[1000005];   // 1e6+5
// void buildSieve(){
//     for(int i=2;i<=sz;i++)    PrimeSieve[i]=1;
//     PrimeSieve[0]=0;// 
//     PrimeSieve[1]=0;    // 1 is neither prime nor composite 
//     for(int i=2;i<sz;i++){
//         if(PrimeSieve[i]==0)    continue;       // the current number itself is composite 
//         for(int j=2;j*i<sz;j++){
//             PrimeSieve[i*j]=0;
//         }
//     }
// }
// add SieveOfEratosthenes
// add isPrime ad
bool isPrime(int n){
    for(int i=2;i*i<=n;i++){
        if(n%i==0)  return 0;
    }
    return 1;
}

/// ====================================PRIME utility ENDS here==================================================

void solve(){
    int n; cin>>n;

    string s; cin>>s;

    vi a(n,0);

//Naive Approach   O(N^2)
  
    for(int i=1;i<n;i++){
        for(int j=i;j<n;j++){
            if(s[j]==s[j-i]){
                a[i]++;
            }else{
                break;
            }
        }
    }

    cout<<a<<endl;

    
    /*
        Z Algorithm  : O(N)
                            */
                
vector<int> z(n,0);

    //Just like KMP
    int l= 0, r=0;
    for(int i=1;i<n;i++){
//Headstart inside segment
        if(i<r){
            z[i] = min(r-i , z[i-l]);
        }

//matching like KMP
        while(i+z[i] < n && s[z[i]]==s[i+z[i]]){
            z[i]++;
        }

//Border right se badhi karte jao
        if(i+z[i] > r){
            l = i;
            r = i+z[i];
        }
    }

    cout<<z<<endl;
    
    // cout<<v<<"\n";
}

int32_t main()
{

 #ifndef ONLINE_JUDGE
    freopen("input.txt", "r" , stdin);
    freopen("output.txt", "w", stdout);              // take input from the file and O/P on the console-- > more clarity!
#endif
 
 ios_base::sync_with_stdio(false);
 cin.tie(NULL);

    int T = 1;
    cin >> T;
    while (T--)
    {
        solve();
    }
    return 0;
}

