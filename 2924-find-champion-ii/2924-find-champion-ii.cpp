class Solution {
public:
    int findChampion(int n, vector<vector<int>>& edges) {
        int in[n];
        memset(in,0,sizeof(in));
        for(auto i: edges) {
            in[i[1]]++;
        }
        int ans = -1;
        for(int i =0; i<n; i++) {
            if(in[i] == 0) {
                if(ans == -1) ans = i;
                else return -1;
            }
        }
        return ans;
    }
};