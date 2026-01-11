class Solution {
public:
    int find(vector<int> &arr) {
        int n = arr.size();
        vector<int> left(n);
        stack<int> st;
        for(int i = 0; i<n; i++) {
            while(!st.empty() && arr[st.top()]>= arr[i]) st.pop();
            if(!st.empty()) left[i] = st.top()+1;
            st.push(i);
        }
        while(!st.empty()) st.pop();
        int ans = 0;
        for(int i = n-1; i>=0; i--) {
            while(!st.empty() && arr[st.top()] >= arr[i]) st.pop();
            int r = n-1;
            if(!st.empty()) r = st.top()-1;
            st.push(i);
            ans = max(ans,arr[i]*(r-left[i]+1));
        }
        return ans;
    }
    int maximalRectangle(vector<vector<char>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        int ans = 0;
        vector<int> arr(m,0);
        for(int i = 0; i<n; i++) {
            for(int j = 0; j<m; j++) {
                if(mat[i][j] == '1') arr[j]++;
                else arr[j] = 0;
            }
            ans = max(ans,find(arr));
        }
        return ans;
    }
};