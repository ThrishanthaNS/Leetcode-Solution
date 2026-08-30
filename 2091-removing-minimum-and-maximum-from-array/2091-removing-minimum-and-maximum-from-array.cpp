class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int maxidx=0,minidx=0,n=nums.size();
        for(int i=0;i<n;i++){
            if(nums[i]>nums[maxidx]) maxidx=i;
            if(nums[i]<nums[minidx]) minidx=i;
        }
        int l=min(minidx,maxidx);
        int r=max(minidx,maxidx);
        int ans=n;
        ans=min(ans,r+1);
        ans=min(ans,n-l);
        ans=min(ans,l+n-r+1);
        return ans;

    }
};