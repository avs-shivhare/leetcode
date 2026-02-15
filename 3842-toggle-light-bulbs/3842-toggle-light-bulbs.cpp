class Solution {
public:
    vector<int> toggleLightBulbs(vector<int>& bulbs) {
        set<int> st;
        for(auto &i: bulbs) {
            if(st.find(i) != st.end()) st.erase(i);
            else st.insert(i);
        }
        vector<int> ans;
        for(auto &i: st) {
            ans.push_back(i);
        }
        return ans;
    }
};