class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        priority_queue<int> q;
        int n = matrix.size();
        for(int i =0; i<n; i++) {
            for(int j =0; j<n; j++) {
                if(k) {
                    q.push(matrix[i][j]);
                    k--;
                }
                else if(q.top() > matrix[i][j]) {
                    q.pop();
                    q.push(matrix[i][j]);
                }
            }
        }
        return q.top();
    }
};