class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        int n = arr.size();
        vector<int> prefix(n+1,0);
        int x = 0;
        for(int i =1; i<=n; i++) {
            x ^= arr[i-1];
            prefix[i] = x;
        }
        vector<int> ans;
        for(auto i: queries) {
            int temp = prefix[i[1]+1];
            temp ^= prefix[i[0]];
            ans.push_back(temp);
        }
        return ans;
    }
};