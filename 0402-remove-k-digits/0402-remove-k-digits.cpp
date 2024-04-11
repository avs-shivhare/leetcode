class Solution {
public:
    string removeKdigits(string num, int k) {
        int n = num.size();
        if(k == 0) return num;
        if(n == k) return "0";
        stack<char> st;
        for(char i: num) {
            while(!st.empty() && st.top() > i && k) {
                st.pop();
                k--;
            }
            st.push(i);
        }
        while(!st.empty() && k) {
            k--;
            st.pop();
        }
        num = "";
        while(!st.empty()) {
            num += st.top();
            st.pop();
        }
        reverse(num.begin(),num.end());
        while(1<num.size() && num[0] == '0') num.erase(num.begin());
        if(num.size() == 0) return "0";
        return num;
    }
};