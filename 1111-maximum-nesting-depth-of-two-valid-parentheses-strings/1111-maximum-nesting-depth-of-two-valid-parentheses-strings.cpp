class Solution {
public:
    vector<int> maxDepthAfterSplit(string seq) {
        int n = seq.size();
        vector<int> ans(n,0);
        int cnt = 0,cnt2 = 0;
        for(int i = 0; i<seq.size(); i++) {
            if(seq[i] == '(') {
                if(cnt <= cnt2) {
                    cnt++;
                    ans[i] = 1;
                }
                else {
                    cnt2++;
                    ans[i] = 0;
                }
            }
            else {
                if(cnt >= cnt2) {
                    cnt--;
                    ans[i] = 1;
                }
                else {
                    cnt2--;
                    ans[i] = 0;
                }
            }
        }
        return ans;
    }
};