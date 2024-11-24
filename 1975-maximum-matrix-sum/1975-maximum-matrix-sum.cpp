class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        long long sum = 0;
        int cnt = 0;
        long long mini = 1e9;
        for(int i =0; i<n; i++) {
            for(int j =0; j<n; j++) {
                if(matrix[i][j] < 0) {
                    cnt++;
                }
                mini = min(mini,abs(matrix[i][j]*1ll));
                sum += abs(matrix[i][j]);
            }
        }
        if(cnt & 1) {
            return sum-2*mini;
        }
        return sum;
    }
};