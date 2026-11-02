class Solution {
public:
    int minMoves2(vector<int>& nums) {
        int n=nums.size();
        if(n<2) return 0;
        if(n==2){
            return abs(nums[0]-nums[1]);
        }
        sort(nums.begin(),nums.end());
        int mid1=n/2,mid2=mid1+1;
        long long sum1=0,sum2=0;
        for(int i=0;i<n;i++){
            sum1+=abs(nums[i]-nums[mid1]);
            sum2+=abs(nums[i]-nums[mid2]);
        }
        return sum1<sum2?sum1:sum2;

    }
};