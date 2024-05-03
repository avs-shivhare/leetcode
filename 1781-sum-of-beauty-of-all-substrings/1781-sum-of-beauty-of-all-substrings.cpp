class Solution {
public:
    int minElement(vector<int> &vis) {
        int mini = 1e9;
        for(int i : vis) {
            if(i < mini && i>0) mini = i;
        }
        return mini;
    }
    int beautySum(string s) {
        int ans =0;
        int n = s.size();
        for(int i =0; i<n; i++) {
            vector<int> vis(26,0);
            for(int j =i; j<n; j++) {
                vis[s[j]-'a']++;
                int maxi = *max_element(vis.begin(),vis.end());
                int mini = minElement(vis);
                ans += maxi-mini;
            }
        } 
        return ans;
    }
};