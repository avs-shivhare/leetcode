class Solution {
public:
    int maximumGain(string s, int x, int y) {
        // string s1 = s;
        // int ans = 0;
        // string f = "ba";
        // if(x > y) {
        //     reverse(f.begin(),f.end());
        // }
        // int it = s.find(f);
        // while(it != string::npos) {
        //     ans += (f == "ab"?x:y);
        //     s.erase(it,2);
        //     it = s.find(f);
        // }
        // reverse(f.begin(),f.end());
        // it = s.find(f);
        // while(it != string::npos) {
        //     ans += (f == "ab"?x:y);
        //     s.erase(it,2);
        //     it = s.find(f);
        // }
        // return ans;
        stack<char> st;
        int ans =0;
        string temp = "ab";
        if(y>x) {
            reverse(temp.begin(),temp.end());
        }
        for(auto i: s) {
            if(i == temp[1] && !st.empty() && st.top() == temp[0]) {
                ans += (temp == "ab" ? x:y);
                st.pop();
            }
            else {
                st.push(i);
            }
        }
        s = "";
        while(!st.empty()) {
            s+= st.top();
            st.pop();
        }
        reverse(s.begin(),s.end());
        reverse(temp.begin(),temp.end());
        for(auto i: s) {
            if(i == temp[1] && !st.empty() && st.top() == temp[0]) {
                ans += (temp == "ab" ? x:y);
                st.pop();
            }
            else {
                st.push(i);
            }
        }
        return ans;
    }
};