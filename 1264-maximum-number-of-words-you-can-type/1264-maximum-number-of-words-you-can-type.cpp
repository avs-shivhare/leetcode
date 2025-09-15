class Solution {
public:
    int canBeTypedWords(string text, string b) {
        stringstream s(text);
        unordered_set<char> st(b.begin(),b.end());
        int cnt = 0;
        string temp = "";
        while(s>>temp) {
            bool flag = true;
            for(auto i: temp) {
                if(st.find(i) != st.end()) {
                    flag = false;
                    break;
                }
            }
            if(flag) cnt++;
        }
        return cnt;
    }
};