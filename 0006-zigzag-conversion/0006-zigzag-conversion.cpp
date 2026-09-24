class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows==1) return s;
        vector<string>rows(numRows);
        string result;
        bool down=false;
        int i=0;
        for(char x:s){
            rows[i]+=x;
            if(i==0 || i==numRows-1){
                down=!down;
            }
            i+=down?1:-1;
        }
        for(i=0;i<numRows;i++){
            result+=rows[i];
        }
        return result;

    }
};