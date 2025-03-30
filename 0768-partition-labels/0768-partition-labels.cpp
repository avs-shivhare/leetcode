class Solution {
public:
    vector<int> partitionLabels(string s) {
        int last = -1;
        int n = s.size();
        unordered_map<char,int> mpp;
        for(int i = n-1; i>=0; i--) {
            if(mpp.count(s[i]) == 0) {
                mpp[s[i]] = i;
            }
        }
        vector<int> ans;
        unordered_set<int> st;
        for(int i = 0; i<n; i++) {
            st.insert(mpp[s[i]]);
            st.erase(i);
            if(st.size() == 0) {
                int total = i-(last+1)+1;
                last = i;
                ans.push_back(total);
            }
        }
        return ans;
    }
};