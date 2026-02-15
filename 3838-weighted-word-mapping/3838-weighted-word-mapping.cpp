class Solution {
public:
    string mapWordWeights(vector<string>& s, vector<int>& w) {
        string ans = "";
        for(auto &i: s) {
            int sum = 0;
            for(auto &j: i) {
                sum += w[j-'a'];
                sum %= 26;
            }
            int rev = 25-sum;
            ans += rev+'a';
        }
        return ans;
    }
};