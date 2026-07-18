class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int n=numbers.size();
        int right=n-1,left=0;
        while(left<right){
            int r=numbers[right];
            int l=numbers[left];
            if(l+r==target) return {left+1,right+1};
            else if(l+r > target) right--;
            else left++;
        }
        return {};
    }
};