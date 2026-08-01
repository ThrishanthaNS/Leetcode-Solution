class AllOne {
public:
unordered_map<int,list<string>>mp;
unordered_map<string,int>keymap;
unordered_map<string,list<string>::iterator>it;
int mn=0,mx=INT_MIN;
    AllOne() {
        
    }
    void updateMinMax() {
    if (keymap.empty()) {
        mn = 0;
        mx = 0;
        return;
    }

    mn = INT_MAX;
    mx = INT_MIN;

    for (auto &p : mp) {
        if (!p.second.empty()) {
            mn = min(mn, p.first);
            mx = max(mx, p.first);
        }
    }
}
    
    void inc(string key) {
            int oldfreq=keymap[key];
            keymap[key]++;
            int newfreq=oldfreq+1;
            if(newfreq==1){
                mp[newfreq].push_back(key);
                it[key]=prev(mp[newfreq].end());
            }
            else{
                mp[oldfreq].erase(it[key]);
                mp[newfreq].push_back(key);
                it[key]=prev(mp[newfreq].end());
            }
            updateMinMax();

    }
    
    void dec(string key) {
        keymap[key]--;
        if(keymap[key]==0){
            keymap.erase(key);
            mp[1].erase(it[key]);
            it.erase(key);
        }
        else{
            mp[keymap[key]+1].erase(it[key]);
            mp[keymap[key]].push_back(key);
            it[key]=prev(mp[keymap[key]].end());
            if(keymap[key]<mn) mn=keymap[key];
        }
        updateMinMax();
    
    }
    
    string getMaxKey() {
        if(keymap.empty()) return "";
        return mp[mx].front();
    }
    
    string getMinKey() {
        if(keymap.empty()){
            return "";
        }
        return mp[mn].front();
    }
};

/**
 * Your AllOne object will be instantiated and called as such:
 * AllOne* obj = new AllOne();
 * obj->inc(key);
 * obj->dec(key);
 * string param_3 = obj->getMaxKey();
 * string param_4 = obj->getMinKey();
 */