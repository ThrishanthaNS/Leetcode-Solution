class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        int mn=100,mx=0;
        unordered_map<int,int>mp;
        vector<int>ans;
        for(int n:nums){
            if(n<mn) mn=n;
            if(n>mx) mx=n;
            mp[n]=1;
        }
        for(int i=mn;i<=mx;i++){
            if(mp[i]!=1) ans.push_back(i);
        }
        return ans;
    }
};