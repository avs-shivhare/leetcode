class Solution {
public:
    string smallestSubsequence(string s) {
        stack<char> st;
        unordered_map<char,int> mpp;
        vector<bool> vis(26,false); 
        int n = s.size();
        for(int i = 0; i<n; i++) mpp[s[i]] = i;
        for(int i = 0; i<n; i++) {
            //mpp[s[i]-'a']--;
            if(vis[s[i]-'a']) continue;
            while(!st.empty() && st.top() > s[i] && mpp[st.top()] > i) {
                vis[st.top()-'a'] = false;
                st.pop();
            }
            vis[s[i]-'a'] = true;
            st.push(s[i]);
            mpp[s[i]-'a']--;
        }
        string ans = "";
        while(!st.empty()) {
            //cout<<st.top()<<endl;
            ans += st.top();
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};