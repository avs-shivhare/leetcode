class Solution {
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        sort(arr2.begin(),arr2.end());
        int ans = 0;
        for(auto &i: arr1) {
            int l = lower_bound(arr2.begin(),arr2.end(),i-d)-arr2.begin();
            int r = upper_bound(arr2.begin(),arr2.end(),i+d)-arr2.begin();
            if(r-l == 0) ans++; 
        }
        return ans;
    }
};