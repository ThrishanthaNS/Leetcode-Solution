class ProductOfNumbers {
public:
vector<int>nums;
int pos;
int product;
    ProductOfNumbers() {
        product=1;
        pos=-1;
        nums.push_back(product);
    }
    
    void add(int num) {
        product*=num;
        if(num==0){
            pos=nums.size();
            product=1;
        }
        nums.push_back(product);
    }
    
    int getProduct(int k) {
        int n=nums.size();
        int ans;
        if(pos>=n-k) return 0;
        return nums[n-1]/nums[n-k-1];
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */