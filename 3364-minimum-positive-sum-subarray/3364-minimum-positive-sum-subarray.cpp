class Solution {
public:
    int minimumSumSubarray(vector<int>& nums, int l, int r) {
        int ans=INT_MAX;
        int wz=l;
        while(wz<=r){
            int sum=0;
            for(int i=0;i<wz;i++){
                sum+=nums[i];
            }
            if(sum>0){
                ans=min(sum,ans);
            }
            for(int i=wz;i<nums.size();i++){
                sum+=nums[i];
                sum-=nums[i-wz];
                if(sum>0){
                    ans=min(sum,ans);
                }
            }
            wz++;

        }
        return ans==INT_MAX?-1:ans;
    }
};