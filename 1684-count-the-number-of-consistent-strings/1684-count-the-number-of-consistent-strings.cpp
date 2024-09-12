class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        unordered_set<char> st;
        for(auto i: allowed) {
            st.insert(i);
        }
        int cnt = 0;
        for(auto i: words) {
            bool flag = true;
            for(auto x: i) {
                if(st.count(x) == 0) {
                    flag = false;
                    break;
                }
            }
            if(flag) cnt++;
        }
        return cnt;
    }
};