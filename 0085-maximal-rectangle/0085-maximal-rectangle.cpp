class Solution {
public:
    int maxHeight(vector<int> height) {
        int n = height.size();
        stack<int> st1,st2;
        vector<int> left(n,0),right(n,0);
        for(int i =0; i<n; i++) {
            while(!st1.empty() && height[st1.top()] >= height[i]) {
                st1.pop();
            }
            if(st1.empty()) left[i] = 0;
            else left[i] = st1.top()+1;
            st1.push(i);
        }
        int ans = 0;
        for(int i =n-1; i>=0; i--) {
            while(!st2.empty() && height[st2.top()] >= height[i]) st2.pop();
            if(st2.empty()) right[i] = n-1;
            else right[i] = st2.top()-1;
            st2.push(i);
            ans = max(ans,(right[i]-left[i]+1)*height[i]);
        }
        return ans;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<int> height(m,0);
        int maxi = 0;
        for(int i =0; i<n; i++) {
            for(int j =0; j<m; j++) {
                if(matrix[i][j] == '1') height[j]++;
                else height[j] = 0;
            }
            maxi =max(maxi,maxHeight(height));
        }
        return maxi;
    }
};