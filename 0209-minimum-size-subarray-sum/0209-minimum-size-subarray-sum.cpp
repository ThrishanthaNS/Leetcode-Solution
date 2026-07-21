#include<bits/stdc++.h>
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        long long i=0,j=0,n=nums.size();
        int ans=INT_MAX;
        long long sum=0;
        while(i<n){
            sum+=nums[i];
            if(sum>=target){
                ans=fminimum(ans,i-j+1);
                while(sum>=target){
                    ans=fminimum(ans,i-j+1);
                    sum-=nums[j];
                    j++;
                }
            }
            i++;
        }
        return (ans==INT_MAX)?0:ans;;
    }
};