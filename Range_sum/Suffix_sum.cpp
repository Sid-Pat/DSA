class BlackBox{
public:
    int n;
    vi suf;
    BlackBox(int n){
        this->n = n;
        suf.resize(n);  
    }
    void set(int idx,int val){
        suf[idx]=val;
        if(idx<n-1){
            suf[idx]+=suf[idx+1];
        }
    }
    int range_sum(int l,int r){
        if(l>r){
            return 0;
        }
        int sum = suf[l]-(r<n-1?suf[r+1]:0);
        return sum;
    }
};
