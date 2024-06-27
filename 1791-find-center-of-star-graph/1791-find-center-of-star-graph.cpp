class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<int> en(n+2,0);
        for(auto i: edges) {
            en[i[0]]++;
            en[i[1]]++;
        }
        int maxi = 0;
        for(int i = 0; i<=n+1; i++) {
            if(en[maxi] < en[i]) {
                maxi = i;
            }
        }
        return maxi;
    }
};