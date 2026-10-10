class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int>tails;
        for(int x:nums){
            int low=0,high=tails.size()-1;
            int pos=high+1;
            while(low<=high){
                int mid=low+(high-low)/2;
                if(tails[mid]>=x){
                    pos=mid;
                    high=mid-1;  
                }
                else{
                    low=mid+1;
                }
            }
            if(pos==tails.size()){
                tails.push_back(x);
            } 
            else{
                tails[pos]=x;
            }
        }
        return tails.size();
    }
};