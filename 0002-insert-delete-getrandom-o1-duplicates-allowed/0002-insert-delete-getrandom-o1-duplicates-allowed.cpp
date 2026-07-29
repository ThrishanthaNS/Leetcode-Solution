class RandomizedCollection {
public:
unordered_map<int,unordered_set<int>>randomset;
vector<int>num;
    RandomizedCollection() {
        
    }
    
    bool insert(int val) {
       bool ret=randomset[val].empty();
       randomset[val].insert(num.size());
       num.push_back(val);
       return ret;
    }
    
    bool remove(int val) {
        if(randomset[val].empty()) return false;
        int removeidx=*randomset[val].begin();
        randomset[val].erase(removeidx);
        int lastval=num.back();
        int lastidx=num.size()-1;
        if(lastidx!=removeidx){
            randomset[lastval].erase(lastidx);
            randomset[lastval].insert(removeidx);
            num[removeidx]=lastval;
        }
        num.pop_back();
        if(randomset[val].empty()){
            randomset.erase(val);
        }
        return true;
    }
    
    int getRandom() {
        int index= rand()%num.size();
        return num[index];

    }
};
/**
 * Your RandomizedCollection object will be instantiated and called as such:
 * RandomizedCollection* obj = new RandomizedCollection();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */