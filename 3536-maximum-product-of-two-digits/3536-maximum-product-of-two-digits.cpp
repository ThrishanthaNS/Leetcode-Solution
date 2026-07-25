class Solution {
public:
    int maxProduct(int n) {
        int max1=0,max2=0;
        while(n!=0){
            int r=n%10;
            if(r>=max1){
                max2=max1;
                max1=r;
            }
            else if(r<max1 && r>max2){
                max2=r;
            }
            n/=10;
        }
        return max1*max2;
    }
};