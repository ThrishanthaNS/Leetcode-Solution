class Solution {
public:
    int findGCD(vector<int>& nums) {
        int mn=nums[0],mx=nums[0];
        for(int x:nums){
            if(x>mx) mx=x;
            if(x<mn) mn=x;
        }
        return gcd(mn,mx);
    }
};