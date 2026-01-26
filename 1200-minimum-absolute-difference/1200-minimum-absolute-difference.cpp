class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        sort(arr.begin(),arr.end());
        int diff = 1e9;
        vector<vector<int>> ans;
        int n = arr.size();
        for(int i = 1; i<n; i++) {
            if(arr[i]-arr[i-1] < diff) {
                diff = arr[i]-arr[i-1];
                ans = {{arr[i-1],arr[i]}};
            }
            else if(diff == arr[i]-arr[i-1]) {
                ans.push_back({arr[i-1],arr[i]});
            }
        }
        return ans;
    }
};