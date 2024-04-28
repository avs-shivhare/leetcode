class RandomizedSet {
public:
    int size =0;
    int i =0;
    unordered_set<int> st;
    RandomizedSet() {
        
    }
    
    bool insert(int val) {
        if(st.find(val) != st.end()) return false;
        st.insert(val);
        size++;
        return true;   
    }
    
    bool remove(int val) {
        if(st.find(val) != st.end()) {
            st.erase(val);
            size--;
            return true;
        }
        return false;
    }
    
    int getRandom() {
        int val = rand() % size;
        for(auto it = st.begin(); it != st.end(); it++) {
            if(val == 0) {
                return *(it);
            }
            val--;
        }
        return *(st.begin());
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */