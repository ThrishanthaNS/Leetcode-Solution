class Solution {
public:
string divideandsum(string s,int k){
    string res="";
    for(int i=0;i<s.size();i=i+k){
        string part=s.substr(i,k);
        int sum=0;
        
        for(char x:part){
            sum=sum+(x-'0');
        }
        res=res+to_string(sum);
    }
    return res;
}
    string digitSum(string s, int k) {
        string ans=s;
        while(ans.size()>k){
            ans=divideandsum(ans,k);
        }
        return ans;
    }
};