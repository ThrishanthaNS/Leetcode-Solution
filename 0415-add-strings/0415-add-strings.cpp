class Solution {
public:
    string addStrings(string num1, string num2) {
        string ans="";
        int carry=0;
        int s1=num1.size()-1;
        int s2=num2.size()-1;
        while(s1>=0|| s2>=0||carry){
            int n1=(s1>=0)?num1[s1]-'0':0;
            int n2=(s2>=0)?num2[s2]-'0':0;
            int res=n1+n2+carry;
            carry=res/10;
            res=res%10;
            ans+=(res+'0');
            s1--;
            s2--;
        }
        
        reverse(ans.begin(),ans.end());
        return ans;
    }
};