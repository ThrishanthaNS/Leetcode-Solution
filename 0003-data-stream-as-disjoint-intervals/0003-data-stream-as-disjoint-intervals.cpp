class SummaryRanges {
public:
    map<int,int>mp;
    SummaryRanges() {
        
    }
    
    void addNum(int value) {
        auto right = mp.lower_bound(value);
        auto left = right;
        if (right != mp.begin())
            --left;
        else
            left = mp.end();
        if(right==mp.end() && left==mp.end()){
            mp[value]=value;
            return;
        }
        bool mergeright=false,mergeleft=false;
        if(left!=mp.end() && left->second==value-1) mergeleft=true;
        if(right!=mp.end() && right->first==value+1) mergeright=true;
        if((left!=mp.end() && value>=left->first && value<=left->second)||
            (right!=mp.end() && value>=right->first && value<=right->second)) return;


        if(mergeright && mergeleft){
            int start=left->first,end=right->second;
            mp.erase(left);
            mp.erase(right);
            mp[start]=end;
        }
        else if(mergeleft){
                int start=left->first;
                mp.erase(left);
                mp[start]=value;
        }
        else if(mergeright){
                int end=right->second;
                mp.erase(right);
                mp[value]=end;
        }
        else{
            mp[value]=value;
        }
    }
    
    vector<vector<int>> getIntervals() {
        vector<vector<int>>ans;
        for(const auto&[l,r]:mp){
            ans.push_back({l,r});
        }
        return ans;
    }
};

/**
 * Your SummaryRanges object will be instantiated and called as such:
 * SummaryRanges* obj = new SummaryRanges();
 * obj->addNum(value);
 * vector<vector<int>> param_2 = obj->getIntervals();
 */