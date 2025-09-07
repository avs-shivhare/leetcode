class Solution {
public:
    vector<int> sumZero(int n) {
        vector<int> ans;
        int cnt = 1;
        while(ans.size() < n) {
            if(ans.size()+1 == n) {
                ans.push_back(0);
            }
            else {
                ans.push_back(cnt);
                ans.push_back(-cnt);
                cnt++;
            }
        }
        return ans;
    }
};