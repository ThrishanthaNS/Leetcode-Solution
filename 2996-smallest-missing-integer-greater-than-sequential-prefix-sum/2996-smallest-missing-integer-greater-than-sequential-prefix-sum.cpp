class Solution {
public:
    int missingInteger(vector<int>& nums) {
        int ans=nums[0];
        unordered_map<int,int>mp;
        mp[ans]=1;
        for(int num:nums){
            mp[num]=1;
        }
        for(int i=1;i<nums.size();i++){
            if(nums[i]==nums[i-1]+1){
                ans+=nums[i];
            }
            else{
                break;
            }
        }
        while(mp[ans]){
            ans++;
        }
        return ans;
    }
};