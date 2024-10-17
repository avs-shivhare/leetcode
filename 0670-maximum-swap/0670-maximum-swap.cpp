class Solution {
public:
    int maximumSwap(int num) {
        int ans = num;
        string s = to_string(num);
        int n = s.size();
        for(int i =0; i<n; i++) {
            for(int j =0; j<n; j++) {
                swap(s[i],s[j]);
                ans = max(ans,stoi(s));
                swap(s[i],s[j]);
            }
        }
        return ans;
    }
};