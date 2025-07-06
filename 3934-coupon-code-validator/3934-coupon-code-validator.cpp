class Solution {
public:
    vector<string> validateCoupons(vector<string>& code, vector<string>& b, vector<bool>& is) {
        unordered_set<string> st;
        st.insert("electronics");
        st.insert("grocery");
        st.insert("pharmacy");
        st.insert("restaurant");
        map<string,multiset<string>> mpp;
        int n = code.size();
        for(int i = 0; i<n; i++) {
            bool flag = true;
            for(auto j: code[i]) {
                if(('A' <= j && j<= 'Z') || ('a' <= j && j <= 'z') || ('0' <= j && j<= '9') || j == '_') {

                }
                else {
                    flag = false;
                    break;
                }
            }
            if(!code[i].empty() && flag && st.count(b[i]) && is[i]) mpp[b[i]].insert(code[i]);
        }
        vector<string> ans;
        for(auto i: mpp) {
            for(auto j: i.second) ans.push_back(j);
        }
        return ans;
    }
};