class Solution {
public:
    int find(vector<int> &arr) {
        stack<int> st,st2;
        int n = arr.size();
        vector<int> prefix(n,0),suffix(n,0);
        int ans = 0;
        for(int i = 0; i<n; i++) {
            while(!st.empty() && arr[st.top()] >= arr[i]) st.pop();
            if(!st.empty()) prefix[i] = prefix[st.top()]+arr[i]*(i-st.top());
            else prefix[i] = arr[i]*(i+1);
            ans += prefix[i];
            st.push(i);
        }
        // int ans = 0;
        // for(int i = 0; i<n; i++) {
        //     while(!st2.empty() && arr[st2.top()] > arr[i]) st2.pop();
        //     if(!st2.empty()) prefix[i] = st2.top()+1;
        //     else prefix[i] = 0;
        //     st2.push(i);
        //     ans += (suffix[i]-prefix[i]+1)*arr[i];
        // }
        // for(auto i: arr) cout<<i<<" ";
        // cout<<endl;
        // for(auto i: prefix) cout<<i<<" ";
        // cout<<endl;
        // for(auto i: suffix) cout<<i<<" ";
        // cout<<endl;
        return ans;
    }
    int numSubmat(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        vector<int> prefix(m,0);
        int ans = 0;
        for(int i = 0; i<n; i++) {
            for(int j = 0; j<m; j++) {
                if(mat[i][j]) prefix[j]++;
                else prefix[j] = 0;
            }
            ans += find(prefix);
        }
        return ans;
    }
};