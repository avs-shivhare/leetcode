class Skiplist {
public:
    unordered_map<int,int> mpp;
    Skiplist() {
        
    }
    
    bool search(int target) {
        return mpp.find(target) != mpp.end();
    }
    
    void add(int num) {
        mpp[num]++;
    }
    
    bool erase(int num) {
        if(mpp.find(num) != mpp.end()) {
            mpp[num]--;
            if(mpp[num] == 0) mpp.erase(num);
            return true;
        }
        return false;
    }
};

/**
 * Your Skiplist object will be instantiated and called as such:
 * Skiplist* obj = new Skiplist();
 * bool param_1 = obj->search(target);
 * obj->add(num);
 * bool param_3 = obj->erase(num);
 */