class Solution {
public:
    string removeSubstring(string s, int k) {
        vector<pair<int,int>> st;
        int n = s.size();
        for(int i  = 0; i<n; i++) {
            if(st.empty()) st.push_back({i,1});
            else if(s[i] == s[st.back().first]) {
                st.back().second++;
            }
            else {
                st.push_back({i,1});
            }
            while(st.size() > 1) {
                int x = st.size();
                //cout<<st[x-2].first<<" "<<st[x-2].second<<" -> "<<st[x-1].first<<" "<<st[x-1].second<<endl;
                if(s[st[x-2].first] == '(' && st[x-2].second >= k && s[st[x-1].first] == ')' && st[x-1].second >= k) {
                    st.pop_back();
                    if(st.back().second-k == 0) st.pop_back();
                    else st.back().second-=k;
                }
                else break;
            }
            //cout<<i<<" -> "<<st.size()<<endl;
        }
        string ans = "";
        for(auto i: st) {
            int cnt = i.second;
            while(cnt--) {
                ans += s[i.first];
            }
        } 
        return ans;
    }
};