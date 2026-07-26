class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        int m1,m2,m3;
        m1=m2=m3=INT_MIN;
        int min1=0,min2=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]>=m1){
                m3=m2;
                m2=m1;
                m1=nums[i];
            }
            else if(nums[i]<m1 && nums[i]>=m2){
                m3=m2;
                m2=nums[i];
            }
            else if(nums[i]>m3){
                m3=nums[i];
            }
            if(nums[i]<=min1){
                min2=min1;
                min1=nums[i];
            }
            else if(nums[i]<min2){
                min2=nums[i];
            }
        }
        return (m1*m2*m3>min1*min2*m1)?m1*m2*m3:min1*min2*m1;
    }
};