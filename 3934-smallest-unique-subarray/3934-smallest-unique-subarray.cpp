class Solution {
public:
   bool equalSubarry(vector<int>& nums, int k) {

        int n = nums.size();

        long long mod = 1e9 + 7;
        long long base = 31;

        // Calculate base^(k-1)
        long long power = 1;

        for(int i = 1; i < k; i++) {
            power = (power * base) % mod;
        }

        // Calculate hash of first window
        long long hashVal = 0;

        for(int i = 0; i < k; i++) {
            hashVal = (hashVal * base + nums[i]) % mod;
        }

        unordered_map<long long, int> mp;

        mp[hashVal]++;

        // Sliding window
        for(int i = k; i < n; i++) {

            // Remove outgoing element
            hashVal = (hashVal - nums[i-k] * power % mod + mod) % mod;

            // Shift remaining elements and add new element
            hashVal = (hashVal * base + nums[i]) % mod;

            mp[hashVal]++;
        }

        // Check whether any subarray occurs exactly once
        for(auto& [hashValue, freq] : mp) {
            if(freq == 1) {
                return true;
            }
        }

        return false;
    }
    int smallestUniqueSubarray(vector<int>& nums) {
        int low=1,high=nums.size()-1;
        int ans=nums.size();
        while(low<=high){
            int mid=low+(high-low)/2;
            if(equalSubarry(nums,mid)){
                ans=mid;
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return ans;
    }
};