
struct manacher{
    vector<int> p;

    void run_manacher(string s){
        // cout<<s<<endl;

        int n = s.length();

        p.assign(n,1); //atleast one length pallindrome
        int l=1, r=1;

        for(int i=0;i<n;i++){
            p[i] = max(0ll , min(r-i , p[l+r-i]));  //only line to remember

            while(i-p[i]>=0 && i+p[i]<n && s[i-p[i]]==s[i+p[i]]){
                p[i]++;
            }

            if(i+p[i]>r){ //bounding box
                r = i+p[i];
                l = i-p[i];
            }

        }
        // cout<<p<<endl;
    }

    void build(string s){
        string t;
        for(auto x:s){
            t += string("#") + x; 
        }
        run_manacher(t+"#");
    }

    int getLongest(int cen , bool odd){
            int pos = 2*cen + 1+ (!odd);
            return  p[pos]-1;
        }

    bool checkPalin(int l, int r){
        if(r-l+1<= getLongest((l+r)/2 , l%2 == r%2)){
            return 1;
        }else{
            return 0;
        }
    } 

} m;
