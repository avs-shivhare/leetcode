class Solution {
public:
    int minInsertions(string s) {
        stack<char> st;
        string temp = "";
        int l = 0,r = 0;
        int ans = 0;
        int n = s.size();
        while(r<n) {
            if(s[r] == '(') {
                temp += "(";
                r++;
                continue;
            }
            l = r;
            int cnt = 0;
            while(r<n && s[l] == s[r]) {
                cnt++;
                r++;
            }
            while(cnt > 0) {
                if(cnt == 1) ans++;
                temp += ")";
                cnt -= 2;
            }
        }
        //cout<<temp<<" "<<ans<<endl;
        for(int i = temp.size()-1; i>=0; i--) {
            if(temp[i] == '(') {
                if(st.empty()) ans += 2;
                else st.pop();
            }
            else st.push(temp[i]);
            //cout<<temp[i]<<" "<<ans<<endl;
        }
        ans += st.size();
        return ans;
    }
};