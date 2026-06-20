class Solution {
public:
    int minLights(vector<int>& lights) {
        int n = lights.size();
        vector<int> ans(n,0);
        for(int i = 0; i<n; i++) {
            if(lights[i] == 0) continue;
            int l = max(0,i-lights[i]);
            int r = min(n-1,i+lights[i]);
            ans[l]++;
            if(r+1 < n) ans[r+1]--;
        }
        for(int i = 1; i<n; i++) {
            ans[i] += ans[i-1];
        }
        int i = 0;
        int cnt = 0;
        while(i<n) {
            if(ans[i]) {
                i++;
            }
            else {
                if(i+1<n && ans[i+1] == 0) {
                    cnt++;
                    i += 3;
                }
                else {
                    cnt++;
                    i+= 2;
                }
            }
        }
        return cnt;
    }
};