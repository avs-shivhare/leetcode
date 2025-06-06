class Solution {
public:
    string robotWithString(string s) {
        stack<char> st;
        map<char,vector<int>> mpp;
        int n = s.size();
        for(int i = 0; i<n; i++) {
            mpp[s[i]].push_back(i);
        }
        int i = 0;
        string ans = "";
        for(auto x: mpp) {
            for(auto j: x.second) {
                //cout<<x.first<<" "<<j<<" before "<<i<<endl;
                while(!st.empty() && st.top() <= x.first) {
                    ans += st.top();
                    st.pop();
                }
                while(i<= j) {
                    st.push(s[i]);
                    i++;
                }
                //cout<<j<<" after "<<i<<endl;
                if(!st.empty() && st.top() == x.first) {
                    ans += st.top();
                    st.pop();
                }
            }
        }
        while(!st.empty()) {
            ans += st.top();
            st.pop();
        }
        return ans;
    }
};