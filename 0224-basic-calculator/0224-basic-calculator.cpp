class Solution {
public:
    int solve(string &s,int &i){
        long long res=0;
        long long num=0;
        int sign=1;
        while(i<s.size()){
            char c=s[i];
            if(isdigit(c)){
                num=0;
                while(i<s.size() && isdigit(s[i])){
                    num=num*10+(s[i]-'0');
                    i++;
                }
                res=res+sign*num;
                continue;
            }
            if(c=='+') sign=1;
            else if (c=='-') sign=-1;
            else if(c=='('){
                i++;
                int val=solve(s,i);
                res=res+sign*val;
            }
            else if(c==')'){
                return res;
            }
            i++;

        }
        return res;
    }
    int calculate(string s) {
        int i=0;
        return solve(s,i);
    }
};