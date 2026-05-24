class Solution {
public:
    int passwordStrength(string password) {
        string sp = "!@#$";
        int ans = 0;
        unordered_set<char> st;
        for(auto &i: password) {
            if('a' <= i && i <= 'z') {
                if(st.find(i) == st.end()) {
                    ans++;
                    st.insert(i);
                }
            }
            else if('A' <= i && i <= 'Z') {
                if(st.find(i) == st.end()) {
                    st.insert(i);
                    ans += 2;
                }
            }
            else if('0' <= i && i <= '9') {
                if(st.find(i) == st.end()) {
                    st.insert(i);
                    ans += 3;
                }
            }
            else if(sp.find(i) != string::npos) {
                if(st.find(i) == st.end()) {
                    st.insert(i);
                    ans += 5;
                }
            }
        }
        return ans;
    }
};