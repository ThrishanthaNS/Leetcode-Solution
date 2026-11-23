class ProductOfNumbers {
public:
vector<int>productarr;

    ProductOfNumbers() {
        //product=1;
    }
    
    void add(int num) {
        productarr.push_back(num);
    }
    
    int getProduct(int k) {
        int n=productarr.size();
        int ans=1;
        for(int i=n-1;i>=n-k;i--){
            ans*=productarr[i];
        }
        return ans;
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */