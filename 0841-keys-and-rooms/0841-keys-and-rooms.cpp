class Solution {
public:
    bool f(int key,vector<vector<int>> &rooms,unordered_set<int> &st) {
        if(st.empty()) return true;
        auto k = st.find(key);
        if(k != st.end()) {
            st.erase(k);
            if(st.empty()) return true;
            for(int i = 0; i<rooms[key].size(); i++) {
                if(f(rooms[key][i],rooms,st)) return true;
            }
        }
        return false;
    }
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        unordered_set<int> st;
        for(int i =0; i<n; i++) {
            st.insert(i);
        }
        return f(0,rooms,st);
    }
};