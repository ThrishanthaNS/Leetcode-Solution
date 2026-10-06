class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int count=0,n=nums.size();
        for(int x:nums){
            if(x) count++;
        }
        int swap=0;
        for(int i=0;i<count;i++){
            if(nums[i]==0) swap++;
        }
        int minswap=swap;
        for(int i=count;i<n*2;i++){
            if(nums[(i-count)%n]==0) swap--;
            if(nums[i%n]==0) swap++;
            minswap=min(swap,minswap);
        }

        return minswap;
    }
};