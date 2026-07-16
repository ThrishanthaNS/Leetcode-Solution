class Solution {
public:
    int gcd(int a,int b){
        return (b==0)?a: gcd(b,a%b);
    }
    long long gcdSum(vector<int>& nums) {
        long long gcdsum=0,maxi=nums[0];
        for(int i=0;i<nums.size();i++){
            if(nums[i]>maxi) maxi=nums[i];
            nums[i]=gcd(nums[i],maxi);
        }
        sort(nums.begin(),nums.end());
        int left=0,right=nums.size()-1;
        while(left<right){
            gcdsum+=gcd(nums[left],nums[right]);
            left++;
            right--;
        }
        return gcdsum;
    }
};