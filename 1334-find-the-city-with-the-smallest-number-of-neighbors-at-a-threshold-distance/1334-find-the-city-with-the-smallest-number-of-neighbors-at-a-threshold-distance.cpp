class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int maxi) {
        
        vector<vector<int>> mat(n,vector<int>(n,1e9));
        for(auto i: edges) {
            if(i[1] == i[0]) continue;
            mat[i[0]][i[1]] = i[2];
            mat[i[1]][i[0]] = i[2];
        }
        for(int i =0; i<n; i++) mat[i][i] = 0;
        for(int i =0; i<n; i++) {
            for(int j =0; j <n; j++) {
                for(int k =0; k<n; k++) {
                    mat[j][k] = min(mat[j][k],mat[j][i]+mat[i][k]);
                }
            }
        }
        int node = 0, val =1e9;
        for(int i =0; i<n; i++) {
            int cnt =0;
            for(int j =0; j<n; j++) {
                //if(i == j) continue;
                if(maxi >= mat[i][j]) cnt++;
            }
            if(val >= cnt ) {
                val =  cnt;
                node = i;
            }
        }
        return node;
    }
};