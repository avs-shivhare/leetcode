class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int maxi = 0;
        int n = heights.size();
        vector<int> left(n,0),right(n,0);
        stack<int> st1,st2;
        for(int i =0; i<n; i++) {
            while(!st1.empty() && heights[st1.top()] >= heights[i]) {
                st1.pop();
            }
            if(st1.empty()) left[i] = 0;
            else left[i] = st1.top()+1;
            //cout<<left[i]<<" ";
            st1.push(i);
        }
        //cout<<endl;
        for(int i =n-1; i>=0; i--) {
            while(!st2.empty() && heights[st2.top()] >= heights[i]) {
                st2.pop();
            }
            if(st2.empty()) {
                right[i] = n-1;
            }
            else right[i] = st2.top()-1;
            maxi = max(maxi,heights[i]*(right[i]-left[i]+1));
            //cout<<maxi<<" ";
            st2.push(i);
        }
        return maxi;
    }
};