class Solution {
public:
    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
        long long n=s.size(),sum=0;
        int mod=1e9+7;
        vector<int>compressed,position,ans;
        vector<long long>prefixsum;
        prefixsum.push_back(sum);
        for(int i=0;i<n;i++){
            int digit=s[i]-'0';
            if(digit!=0){
                sum+=digit;
                compressed.push_back(digit);
                position.push_back(i);
                prefixsum.push_back(sum);
            }
        }
        int m=compressed.size();
        vector<long long>pow10(m+1,1),prefixnum(m+1,0);
        for(int i=1;i<=m;i++){
            pow10[i]=(pow10[i-1]*10)%mod;
        }
        for(int i=1;i<=m;i++){
            prefixnum[i]=((prefixnum[i-1]*10)+compressed[i-1])%mod;
        }
        for(auto p:queries){
            int l=lower_bound(position.begin(),position.end(),p[0])-position.begin();
            int r=upper_bound(position.begin(),position.end(),p[1])-position.begin()-1;
            if(l>r) {
                ans.push_back(0);
            }
            else{
                long long res=(prefixnum[r+1]-prefixnum[l]*pow10[r-l+1])%mod;
                long long  x=prefixsum[r+1]-prefixsum[l];
                //cout<<x<<" ";
                res=(res+mod)%mod;
                res=(res*x)%mod;
                ans.push_back(res);
            }

        } 
        return ans;
    }
};