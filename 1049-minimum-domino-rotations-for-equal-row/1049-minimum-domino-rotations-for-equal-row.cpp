class Solution {
public:
    int minDominoRotations(vector<int>& t, vector<int>& b) {
        unordered_map<int,int> mpp;
        for(auto i: t) mpp[i]++;
        for(auto i: b) mpp[i]++;
        int n = t.size();
        unordered_set<int> st;
        for(auto i: mpp) {
            if(i.second >= n) st.insert(i.first);
        }
        int ans = 1e9;
        for(auto i: st) {
            int x = 0,y = 0;
            bool flag = true;
            for(int j = 0; j<n; j++) {
                if(t[j] != i) {
                    if(b[j] == i) x++;
                    else {
                        flag = false;
                        break;
                    }
                }
                if(b[j] != i) {
                    if(t[j] == i) y++;
                    else {
                        flag = false;
                        break;
                    }
                }
            }
            if(flag) ans = min({x,y,ans});
        }
        if(ans >= 1e9) return -1;
        return ans;
    }
};