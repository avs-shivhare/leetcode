class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int n = blocks.size();
        int ans = 1e9;
        for(int i = 0; i<n; i++) {
            int cntB = 0,cntW = 0;
            for(int j = i; j<n; j++) {
                if(blocks[j] == 'B') cntB++;
                else cntW++;
                if(cntW+cntB == k) {
                    break;
                }
            }
            if(cntW+cntB == k) {
                ans = min(ans,cntW);
            }
        }
        return ans;
    }
};