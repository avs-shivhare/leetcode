class Solution {
public:
    int minArrivalsToDiscard(vector<int>& arr, int w, int m) {
        unordered_map<int,int> mpp;
        unordered_set<int> st;
        int l = 0,r = 0;
        int n = arr.size();
        int ans = 0;
        while(r<n) {
            while(l<r && r-l+1 > w) {
                if(st.find(l) == st.end()) mpp[arr[l]]--;
                l++;
            }
            if(mpp[arr[r]]+1 <= m) {
                mpp[arr[r]]++;
            }
            else {
                ans++;
                st.insert(r);
            }
            r++;
        }
        return ans;
    }
};