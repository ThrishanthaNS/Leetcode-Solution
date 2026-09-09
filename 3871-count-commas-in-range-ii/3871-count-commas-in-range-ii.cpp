class Solution {
public:
    long long countCommas(long long n) {
        long long ans=0;
        while(n>999){
            if(n>=1e15){
                ans+=5*(n-1e15+1);
                n=1e15-1;
            }
            else if(n>=1e12){
                ans+=4*(n-1e12+1);
                n=1e12-1;
            }
            else if(n>=1e9){
                ans+=3*(n-1e9+1);
                n=1e9-1;
            }
            else if(n>=1e6){
                ans+=2*(n-1e6+1);
                n=1e6-1;
            }
            else{
                ans+=(n-999);
                n=999;
            }

        }
        return ans;

    }
};