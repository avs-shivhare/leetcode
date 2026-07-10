class Solution {
public:
    int find(vector<vector<int>> &arr,int l,int r,int &len) {
        if(l == r) return 0;
        if(arr[l][0] >= r) return 1;
        if(arr[l][len-1] < r) return -1;
        int step = 0;
        for(int i = len-1; i>=0; i--) {
            if(arr[l][i] < r) {
                step += 1<<i;
                l = arr[l][i];
            }
        }
        return step+1;
    }
    vector<int> pathExistenceQueries(int n, vector<int>& nums, int m, vector<vector<int>>& queries) {
        vector<pair<int,int>> temp;
        for(int i = 0; i<n; i++) {
            temp.push_back({nums[i],i});
        }
        sort(temp.begin(),temp.end());
        vector<int> pos(n);
        for(int i = 0; i<n; i++) {
            pos[temp[i].second] = i;
        }
        int len = 18;
        vector<vector<int>> jump(n,vector<int>(len+1,0));
        int l = 0, r= 0;
        while(l<n) {
            while(r+1<n && temp[r+1].first-temp[l].first <= m) r++;
            jump[l][0] = r;
            l++;
        }
        for(int j = 1; j<len; j++) {
            for(int i = 0; i<n; i++) {
                jump[i][j] = jump[jump[i][j-1]][j-1];
            }
        }
        vector<int> ans;
        for(auto &i: queries) {
            int l = min(pos[i[0]],pos[i[1]]);
            int r = max(pos[i[0]],pos[i[1]]);
            ans.push_back(find(jump,l,r,len));
        }
        return ans;
    }
};