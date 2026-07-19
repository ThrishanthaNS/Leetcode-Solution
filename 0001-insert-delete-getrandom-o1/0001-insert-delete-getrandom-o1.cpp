class RandomizedSet {
public:
    unordered_map<int,int>randomset;
    vector<int>num;
    RandomizedSet() {

    }
    
    bool insert(int val) {
        if(randomset.count(val)){
            return false;
        }
        num.push_back(val);
        randomset[val]=num.size()-1;
        return true;
    }
    
    bool remove(int val) {
        if(randomset.count(val)){
            int last=num.back();
            int index=randomset[val];
            num[index]=last;
            num.pop_back();
            randomset[last]=index;
            randomset.erase(val);
            return true;
        }
        return false;
    }
    
    int getRandom() {
        int index= rand()%num.size();
        return num[index];

    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */