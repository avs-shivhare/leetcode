class Solution {
public:
    int minOperations(vector<string>& logs) {
        int ans = 0;
        for(auto i: logs) {
            if(i == "../") {
                if(ans) ans--;
            }
            else if(i == "./") {

            }
            else ans++;
        }
        return ans;
    }

};