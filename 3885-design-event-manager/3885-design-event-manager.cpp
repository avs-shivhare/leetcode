class EventManager {
public:
    unordered_map<int,int> mpp;
    map<int,set<int>,greater<int>> q;
    EventManager(vector<vector<int>>& events) {
        for(auto &i: events) {
            mpp[i[0]] = i[1];
            q[i[1]].insert(i[0]);
        }
    }
    
    void updatePriority(int eventId, int newPriority) {
        if(mpp.find(eventId) != mpp.end()) {
            int old = mpp[eventId];
            q[old].erase(eventId);
            if(q[old].empty()) q.erase(old);
            mpp[eventId] = newPriority;
            q[newPriority].insert(eventId);
        }
    }
    
    int pollHighest() {
        if(q.empty()) return -1;
        int p = q.begin()->first;
        int e = *(q[p].begin());
        q[p].erase(e);
        if(q[p].empty()) q.erase(p);
        return e;
    }
};

/**
 * Your EventManager object will be instantiated and called as such:
 * EventManager* obj = new EventManager(events);
 * obj->updatePriority(eventId,newPriority);
 * int param_2 = obj->pollHighest();
 */