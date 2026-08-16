class Solution {
public:
    vector<int> asteroidCollision(vector<int>& a) {
        vector<int>res;
        res.push_back(a[0]);
        for(int i=1;i<a.size();i++){
            res.push_back(a[i]);
            while(res.size()>=2){
                int a1=res.back();
                res.pop_back();
                int a2=res.back();
                res.pop_back();
                if(a1<0  && a2>0){
                if(abs(a1)==abs(a2)) break;
                else if(abs(a1)>a2) res.push_back(a1);
                else res.push_back(a2);
                // else{
                //     res.push_back(a2);
                //     res.push_back(a1);
                //     break;
                // }
            }
            else {
                res.push_back(a2);
                res.push_back(a1);
                break;
            }
        }
    }
        return res;
    }
};