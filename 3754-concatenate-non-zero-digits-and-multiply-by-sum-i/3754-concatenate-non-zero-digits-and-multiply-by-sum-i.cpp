class Solution {
public:
    long long sumAndMultiply(int n) {
        long long sum=0,nonzero=0,rev=0;
        while(n!=0){
            int r=n%10;
            n/=10;
            if(r==0) continue;
            sum+=r;
            rev=rev*10+r;
        }
        while(rev!=0){
            int r=rev%10;
            nonzero=nonzero*10+r;
            rev/=10;
        }
        return nonzero*sum;

    }
};