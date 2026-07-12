class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        if(arr.size()==0) return {};
        vector<int>idxsort(arr.size());
        iota(idxsort.begin(),idxsort.end(),0);
        sort(idxsort.begin(),idxsort.end(),[&](int a,int b){
            return arr[a]<arr[b];
        });
        int rank=1,prev=arr[idxsort[0]];
        for(int x:idxsort){
            if(arr[x]==prev)
                arr[x]=rank;
            else{
                prev=arr[x];
                arr[x]=++rank;
            }
           // cout<<x<<" "<<rank<<"\n";
        }
        return arr;
    }
};