class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        map<int,int>mp;
        if(nums.size()<=1) return nums.size();
        int prev=nums[0];
        for(int x:nums) {
            mp[x]++;
            if(x<prev) prev=x;
        }
        int ans=0,count=0;
        for(auto& [x,c]:mp){
            if(x==prev || x==prev+1){
                count++;
                prev=x;
            }
            else{
                ans=max(ans,count);
                prev=x;
                count=1;
            }
        }
        return max(ans,count);
    }
};