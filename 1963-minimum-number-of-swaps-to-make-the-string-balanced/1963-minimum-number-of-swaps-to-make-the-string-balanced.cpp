class Solution {
public:
    int minSwaps(string s) {
        stack<char> st;
        for(auto i: s) {
            if(i == '[') st.push(i);
            else if(!st.empty() && i == ']' && st.top() == '[') st.pop(); 
        }
        return (st.size()+1)/2;
    }
};