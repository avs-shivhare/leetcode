class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> st;
        int n = pushed.size();
        int i = 0,j = 0;
        while(i<n && j<n) {
            if(st.empty() || st.top() != popped[j]) {
                st.push(pushed[i++]);
            }
            else if(st.top() == popped[j]) {
                st.pop();
                j++;
            }
            else return false;
        }
        if(j == n && i<n) return false;
        while(j<n && !st.empty()) {
            if(st.top() == popped[j]) {
                st.pop();
                j++;
            }
            else return false;
        }
        if(st.empty() && i ==n && j == n) return true;
        return false;
    }
};