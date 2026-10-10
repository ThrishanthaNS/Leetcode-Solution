class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n=nums.size();
        int res=nums[0],maxpro=nums[0],minpro=nums[0];
        for(int i=1;i<n;i++){
            int x=nums[i];
            if(x<0){
                swap(maxpro,minpro);
            }
            maxpro=max(maxpro*x,x);
            minpro=min(minpro*x,x);
            res=max(maxpro,res);
        }
        return res;
    }
};