class LRUCache {
public:
    int size, capacity;
    list<int> tags;
    unordered_map<int, pair<int, list<int>::iterator>> data;
    LRUCache(int capacity) {
        size = 0;
        LRUCache::capacity = capacity;
    }
    
    void add(int key) {
        auto &d = data[key];
        auto itr = d.second;
        tags.erase(itr);
        d.second = tags.insert(tags.end(), key);
    }
    int get(int key) {
        auto itr = data.find(key);
        if (itr == data.end()) {
            return -1;
        } else {
            add(key);
            return (*itr).second.first;
        }
    }
    
    void set(int key, int value) {
        auto ret = data.insert(make_pair(key, make_pair(value, tags.end())));
        if (ret.second) {
            if (size == capacity) {
                data.erase(tags.front());
                tags.pop_front();
            } else {
                size++;
            }
            (*ret.first).second.second = tags.insert(tags.end(), key);
        } else {
            (*ret.first).second.first = value;
            add(key);
        }
    }
};
