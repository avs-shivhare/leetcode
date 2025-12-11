class Solution {
public:
    int countCoveredBuildings(int n, vector<vector<int>>& build) {
        vector<int> left(n+1,-1),right(n+1,-1),above(n+1,-1),bellow(n+1,-1);
        for(auto i: build) {
            if(left[i[0]] == -1 || left[i[0]] > i[1]) left[i[0]] = i[1];
            if(right[i[0]] == -1 || right[i[0]] < i[1]) right[i[0]] = i[1];
            if(above[i[1]] == -1 || above[i[1]] > i[0]) above[i[1]] = i[0];
            if(bellow[i[1]] == -1 || bellow[i[1]] < i[0]) bellow[i[1]] = i[0]; 
        }
        int ans = 0;
        for(auto i: build) {
            if(left[i[0]] != i[1] && right[i[0]] != i[1] && above[i[1]] != i[0] && bellow[i[1]] != i[0]) {
                ans++;
            }
        }
        return ans;
    }
};