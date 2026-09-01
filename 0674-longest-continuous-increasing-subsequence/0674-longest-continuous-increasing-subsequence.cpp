class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        int ans=0,count=1;;
        int prev=nums[0];
        for(int i=1;i<nums.size();i++){
            if(nums[i]<=prev){
                ans=max(ans,count);
                count=0;
            }
            count++;
            prev=nums[i];
        }
        ans=max(ans,count);
        return ans;
    }
};