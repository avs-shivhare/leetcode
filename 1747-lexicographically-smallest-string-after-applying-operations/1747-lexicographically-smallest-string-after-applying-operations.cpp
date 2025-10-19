class Solution {
public:
    string findLexSmallestString(string s, int a, int b) {
        queue<string> q;
        set<string> st;
        st.insert(s);
        q.push(s);
        int n = s.size();
        while(!q.empty()) {
            string temp = q.front();
            s = temp;
            q.pop();
            for(int i = 1; i<n; i+=2) {
                temp[i] = ((temp[i]-'0')+a)%10+'0';
            }
            if(st.find(temp) == st.end()) {
                q.push(temp);
                st.insert(temp);
            }
            temp = s.substr(b);
            temp += s.substr(0,b);
            if(st.find(temp) == st.end()) {
                q.push(temp);
                st.insert(temp);
            }
        }
        return *st.begin();
    }
};