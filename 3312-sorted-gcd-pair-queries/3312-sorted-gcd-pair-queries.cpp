class Solution {
public:
    vector<int> gcdValues(vector<int>& nums, vector<long long>& queries) {
        int mx=*max_element(nums.begin(),nums.end());
        vector<int>freq(mx+1,0);
        for(int x:nums){
            freq[x]++;
        }
        vector<long long>gcdcount(mx+1,0);
        for(int g=mx;g>=1;g--){
            long long count=0;
            for(int mul=g;mul<=mx;mul+=g){
                count+=freq[mul];
            }
            long long  pairs=(count*(count-1))/2;
            for(int mul=2*g;mul<=mx;mul+=g){
                pairs-=gcdcount[mul];
            }
            gcdcount[g]=pairs;
        }
        int sum=-1;
        for(int i=0;i<mx+1;i++){
            sum+=gcdcount[i];
            gcdcount[i]=sum;
        }
        vector<int>res;
        for(int x:queries){
            auto it=lower_bound(gcdcount.begin(),gcdcount.end(),x);
            int idx=distance(gcdcount.begin(),it);
            res.push_back(idx);
        }
        return res;
    }
};