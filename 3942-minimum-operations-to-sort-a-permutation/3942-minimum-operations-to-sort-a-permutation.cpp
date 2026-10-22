class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n=nums.size();

        bool inc=true;
        for(int i=0;i<n;i++){
            if(nums[(i+1)%n]!=(nums[i]+1)%n){
                inc=false;
                break;
            }
        }
        int ans=INT_MAX;
        if(inc){
            for(int i=0;i<n;i++){
                if(nums[i]==0){
                    ans=min(ans,min(i,n-i+2));
                    break;
                }
            }
        }

        bool dec=true;
        for(int i=0;i<n;i++){
            if(nums[(i+1)%n]!=((nums[i]-1+n)%n)){
                dec=false;
                break;
            }
        }
        if(dec){
            for(int i=0;i<n;i++){
                if(nums[i]==0){
                    ans=min(ans,min(n-i,i+2));
                    break;
                }
            }
        }
        return ans==INT_MAX?-1:ans;
        
    }
};