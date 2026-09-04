class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int>maxi(n),mini(n);
        int mx=nums[0];
        for(int i=0;i<n;i++){
            mx=max(mx,nums[i]);
            maxi[i]=mx;
        }
        int mn=nums[n-1];
        for(int i=n-1;i>=0;i--){
            mn=min(mn,nums[i]);
            mini[i]=mn;
        }
        for(int i=0;i<n;i++){
            //cout<<maxi[i]<<" "<<mini[i]<<"\n";
            if(maxi[i]-mini[i]<=k) return i;
        }
        return -1;
    }
};