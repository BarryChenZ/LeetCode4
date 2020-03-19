struct Node {
    Node(int f): freq(f), keys(list<int>()) {}
    int freq;
    list<int> keys;
};

struct Data {
    Data() {}
    Data(int v, list<Node>::iterator i, list<int>::iterator ii): value(v), nodeIt(i), listIt(ii) {}
    int value;
    list<Node>::iterator nodeIt;
    list<int>::iterator listIt;
};

class LFUCache {
public:
    LFUCache(int capacity): l({Node(1)}), size(capacity), count(0) {}
    
    int get(int key) {
        if(size == 0) return -1;
        auto it = cache.find(key);
        if(it != cache.end()) {
            update(it);
            return it->second.value;
        } else return -1;
    }
    
    void put(int key, int value) {
        if(size == 0) return;
        auto it = cache.find(key);
        if(it != cache.end()) {
            update(it);
            it->second.value = value;
        } else {
            checkSize();
            cache[key] = Data(value, l.begin(), l.begin()->keys.insert(l.begin()->keys.begin(), key));
            ++count;
        }
    }
    void update(unordered_map<int,Data>::iterator it) {
        auto &nodeIt = it->second.nodeIt;
        auto &listIt = it->second.listIt;
        auto nxt = next(nodeIt, 1);
        if(nxt == l.end() || nxt->freq != nodeIt->freq+1) nxt = l.insert(nxt, Node(nodeIt->freq+1));
        nxt->keys.splice(nxt->keys.begin(), nodeIt->keys, listIt);
        if(nodeIt->freq != 1 && nodeIt->keys.empty()) l.erase(nodeIt);
        nodeIt = nxt;
    }
    
    void checkSize() {
        if(count < size) return;
        --count;
        auto it = l.begin();
        if(it->keys.empty()) ++it;
        auto key = it->keys.back(); it->keys.pop_back();
        cache.erase(key);
    }
    
    list<Node> l;
    unordered_map<int,Data> cache; 
    int size;
    int count;
    
    // void print() {
    //     for_each(l.begin(), l.end(), [](Node& x) {
    //         cout << x.freq << ": ";
    //         for_each(x.keys.begin(), x.keys.end(), [](int& y) {
    //            cout << y << " ";
    //         });
    //         cout << endl;
    //     });
    // }
};
