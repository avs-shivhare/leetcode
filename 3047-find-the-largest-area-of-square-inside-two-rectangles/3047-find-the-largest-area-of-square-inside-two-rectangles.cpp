class Solution {
public:
    long long check(vector<int> &a1,vector<int> &a2,vector<int> &b1,vector<int> &b2) {
        if(a2[1] < b1[1] || a2[0] < b1[0] || a1[1] > b2[1] || a1[0] > b2[0]) return 0;
        int x1,x2,y1,y2;
        y2 = min(a2[1],b2[1]);
        y1 = max(a1[1],b1[1]);
        x1 = max(a1[0],b1[0]);
        x2 = min(a2[0],b2[0]);
        long long t = min(y2-y1,x2-x1);
        return t*t;
    }
    long long largestSquareArea(vector<vector<int>>& b, vector<vector<int>>& t) {
        int n = b.size();
        long long ans = 0;
        for(int i = 0; i<n; i++) {
            for(int j = i+1; j<n; j++) {
                ans = max(ans,check(b[i],t[i],b[j],t[j]));
            }
        }
        return ans;
    }
};