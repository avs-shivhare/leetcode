class Solution {
public:
    long long calculateScore(vector<string>& in, vector<int>& val) {
        long long ans = 0;
        int n = in.size();
        int i = 0;
        while(i<n && i >= 0) {
            if(in[i] == "0") break;
            if(in[i] == "add") {
                ans += val[i];
                in[i] = "0";
                i++;
            }
            else {
                in[i] = "0";
                i += val[i];
            }
        }
        return ans;
    }
};