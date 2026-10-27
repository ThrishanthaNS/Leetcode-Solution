class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        vector<int>sorted=nums;
        sort(sorted.begin(),sorted.end());
        int n=nums.size();
        int mid=(n+1)/2;
        int i=mid-1;
        int j=n-1;
        for(int k=0;k<n;k++){
            if(k%2==0){
                nums[k]=sorted[i--];
            }
            else{
                nums[k]=sorted[j--];
            }
        }
    }
};