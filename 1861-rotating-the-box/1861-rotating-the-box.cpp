class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& box) {
        int n = box.size();
        int m = box[0].size();
        vector<vector<char>> ans(m,vector<char>(n));
        // for(auto i: box) {
        //     for(auto j: i) cout<<j<<" ";
        //     cout<<endl;
        // }
        for(int i =n-1; i>=0; i--) {
            for(int j =0; j<m; j++) {
                ans[j][n-i-1] = box[i][j];
            }
        }
        // for(auto i: ans) {
        //     for(auto j: i) cout<<j<<" ";
        //     cout<<endl;
        // }
        for(int j =0; j<n; j++) {
            queue<char> q;
            int ind = m-1;
            for(int i =m-1; i>=0; i--) {
                if(ans[i][j] == '#') q.push(ans[i][j]);
                else if(ans[i][j] == '*') {
                    while(!q.empty()) {
                        ans[ind][j] = q.front();
                        q.pop();
                        ind--;
                    }
                    while(ind >i) ans[ind--][j] = '.';
                    ind = i-1;
                }
            }
            while(!q.empty()) {
                ans[ind][j] = q.front();
                q.pop();
                ind--;
            }
            while(ind >=0) ans[ind--][j] = '.';
        }
        return ans;
    }
};