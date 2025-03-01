class Solution {
public:
    int countArrays(vector<int>& org, vector<vector<int>>& bd) {
        long long l = bd[0][0],r = bd[0][1];
        int n = org.size();
        for(int i = 1; i<n; i++) {
            long long diff = (long long)org[i]-(long long)org[0];
            long long low = bd[i][0]-diff;
            long long high = bd[i][1]-diff;
            l = max(l,low);
            r = min(r,high);
        }
        if(l>r) return 0;
        return r-l+1;
    }
};