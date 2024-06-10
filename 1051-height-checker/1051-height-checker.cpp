class Solution {
public:
    int heightChecker(vector<int>& heights) {
        vector<int> temp(heights.begin(),heights.end());
        sort(temp.begin(),temp.end());
        int cnt = 0;
        int n = temp.size();
        for(int i = 0; i<n; i++) {
            if(heights[i] != temp[i]) cnt++;
        }
        return cnt;
    }
};