class Solution {
public:
    int countTriplets(vector<int>& arr) {
        int n = arr.size();
        int ans = 0;
        int xOr = 0;
        unordered_map<int,vector<int>> mpp;
        mpp[0].push_back(-1);
        for(int i =0; i<n; i++) {
            xOr ^= arr[i];
            if(mpp.find(xOr)!= mpp.end()) {
                for(int x: mpp[xOr]) {
                    ans += (i-x)-1;
                }
            }
            mpp[xOr].push_back(i);
        }
        return ans;
    }
};