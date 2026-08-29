class LRUCache {
public:
list<pair<int,int>>dll;
int count;
unordered_map<int,list<pair<int,int>>::iterator>mp;
    LRUCache(int capacity) {
        count=capacity;
    }
    
    int get(int key) {
        if(mp.find(key)==mp.end()) return -1;
        auto node=mp[key];
        dll.splice(dll.end(),dll,node);
        return mp[key]->second;
    }
    
    void put(int key, int value) {
        if(mp.find(key)==mp.end()){
            dll.push_back({key,value});
            mp[key]=prev(dll.end());
            if(mp.size()>count){
                int remove=dll.front().first;
                dll.pop_front();
                mp.erase(remove);
            }
        }
        else{
            auto node=mp[key];
            dll.splice(dll.end(),dll,node);
            dll.back().second=value;
            mp[key]=prev(dll.end());
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */