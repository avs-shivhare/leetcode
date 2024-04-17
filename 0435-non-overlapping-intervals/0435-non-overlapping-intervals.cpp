class Solution {
public:
    static bool comparator(vector<int> t1,vector<int> t2) {
        return t1[1] < t2[1];
    }
    int eraseOverlapIntervals(vector<vector<int>>& inr) {
        sort(inr.begin(),inr.end(),comparator);
        int cnt = 0;
        // for(auto i: inr) {
        //     cout<<i[0]<<"-> "<<i[1]<<" ";
        // }
        int n = inr.size();
        int b = inr[0][1];
        for(int i =1; i<n; i++) {
            if(inr[i][0] < b) {
                cnt++;
            }
            else b = inr[i][1];
        }
        return cnt;
    }
};