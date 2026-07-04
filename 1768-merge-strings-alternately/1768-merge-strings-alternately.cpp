class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        string mergestring="";
        int i=0,n1=word1.size(),n2=word2.size();
        while(i<n1&&i<n2){
            mergestring+=word1[i];
            mergestring+=word2[i];
            i++;
        }
        while(i<n1){
            mergestring+=word1[i];
            i++;
        }
        while(i<n2){
            mergestring+=word2[i];
            i++;
        }
        return mergestring;
    }
};