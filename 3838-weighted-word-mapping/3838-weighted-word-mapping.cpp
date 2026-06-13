class Solution {
public:
    string mapWordWeights(vector<string>& words, vector<int>& weights) {
        string ans = "";
        for(auto &i: words) {
            int sum = 0;
            for(auto &j: i) {
                sum += weights[j-'a'];
                sum %= 26;
            }
            ans += (25-sum)+'a';
        }
        return ans;
    }
};