class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        int sum = 0;
        int m = rolls.size();
        for(auto i: rolls) {
            sum += i;
        }
        int diff = ((n+m)*mean)-sum;
        vector<int> ans;
        for(int i =0; i<n; i++) {
            if(diff-6 > n-i-1) {
                ans.push_back(6);
                diff -= 6;
            }
            else {
                //cout<<diff<<endl;
                ans.push_back(diff-(n-i-1));
                diff -= diff-(n-i-1);
            }
        }
        for(auto i: ans) {
            if(i < 1 || i > 6) return {};
        }
        if(diff > 0) return {};
        return ans;
    }
};