class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& nums) {
        int i=0,n=nums.size(),j=1;
        while(i<n && j<n){
            while(i<n && nums[i]%2==i%2) i+=2;
            while(j<n && nums[j]%2==j%2) j+=2;
            if(j<n && i<n)
            swap(nums[i],nums[j]);
            i+=2;
            j+=2;
            
        }
        return nums;
    }
};