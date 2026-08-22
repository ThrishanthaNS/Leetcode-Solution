class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int>pos,neg;
        for(int x:nums){
            if(x>0) pos.push_back(x);
            else    neg.push_back(x);
        }
        int pdx=0,ndx=0;
        for(int i=0;i<nums.size();i++){
            if(i%2==0){
                nums[i]=pos[pdx++];
            }
            else{
                nums[i]=neg[ndx++];
            }
        }
        return nums;
    }
};