class Solution {
public:
    vector<int> getNoZeroIntegers(int n) {
        for(int i = 1; i<=n; i++) {
            int rem = n-i;
            string a = to_string(i);
            string b = to_string(rem);
            if(a.find("0") == string::npos && b.find("0") == string::npos) return {i,rem};
        }
        return {};
    }
};