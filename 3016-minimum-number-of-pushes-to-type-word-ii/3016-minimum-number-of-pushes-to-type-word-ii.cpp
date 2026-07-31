class Solution {
public:
    int minimumPushes(string word) {
        vector<int>mp(26,0);
        for(char x:word){
            mp[x-'a']++;
        }
        sort(mp.begin(),mp.end(),greater<>());
        int ans=0,count=-1;
        for(int c:mp){
            if(c==0) break;
            count++;
            ans+=((count/8)+1)*c;
        }
        return ans;
    }
};