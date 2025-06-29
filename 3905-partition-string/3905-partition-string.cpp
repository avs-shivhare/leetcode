class Solution {
public:
    vector<string> partitionString(string s) {
        unordered_set<string> st;
        string temp = "";
        vector<string> ans;
        st.insert(temp);
        for(auto i: s) {
            temp += i;
            if(st.count(temp) == 0) {
                ans.push_back(temp);
                st.insert(temp);
                temp = "";
            }
        }
        return ans;
    }
};