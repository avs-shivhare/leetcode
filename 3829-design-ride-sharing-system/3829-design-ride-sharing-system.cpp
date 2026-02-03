class RideSharingSystem {
public:
    queue<int> r,d;
    unordered_set<int> st;
    RideSharingSystem() {
        
    }
    
    void addRider(int rid) {
        r.push(rid);
        st.insert(rid);
    }
    
    void addDriver(int did) {
        d.push(did);
    }
    
    vector<int> matchDriverWithRider() {
        while(!r.empty() && st.find(r.front()) == st.end()) {
            r.pop();
        }
        if(!r.empty() && !d.empty()) {
            vector<int> ans = {d.front(),r.front()};
            d.pop();
            r.pop();
            return ans;
        }
        return {-1,-1};
    }
    
    void cancelRider(int rid) {
        st.erase(rid);
    }
};

/**
 * Your RideSharingSystem object will be instantiated and called as such:
 * RideSharingSystem* obj = new RideSharingSystem();
 * obj->addRider(riderId);
 * obj->addDriver(driverId);
 * vector<int> param_3 = obj->matchDriverWithRider();
 * obj->cancelRider(riderId);
 */