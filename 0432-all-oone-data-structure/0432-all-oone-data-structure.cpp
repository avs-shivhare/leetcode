class AllOne {
public:
    unordered_map<string,int> mpp;
    set<pair<int,string>> st;
    AllOne() {
        
    }
    
    void inc(string key) {
        auto it = st.find({mpp[key],key});
        if(it != st.end()) {
            st.erase(it);
            st.insert({mpp[key]+1,key});
        }
        else {
            st.insert({1,key});
        }
        mpp[key]++;
    }
    
    void dec(string key) {
        auto it = st.find({mpp[key],key});
        if(it != st.end()) {
            st.erase(it);
            if(mpp[key]-1 >0) {
                st.insert({mpp[key]-1,key});
            }
        }
        mpp[key]--;
        if(mpp[key] == 0) mpp.erase(key);
    }
    
    string getMaxKey() {
        if(st.size() == 0) return "";
        return (*--st.end()).second;
    }
    
    string getMinKey() {
        if(st.size() == 0) return "";
        return (*st.begin()).second;
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