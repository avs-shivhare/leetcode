class Solution {
public:
    long long binary(long long n) {
        string s = "";
        while(n) {
            if(n&1ll) {
                s += '1';
            }
            else s += '0';
            n >>= 1ll;
        }
        reverse(s.begin(),s.end());
        long long ans = 0;
        for(int i = 0; i<s.size(); i++) {
            if(s[i]-'0') ans |= (1ll<<i);
        }
        return ans;
    }
    vector<int> sortByReflection(vector<int>& nums) {
        vector<vector<long long>> temp;
        for(auto &i: nums) {
            temp.push_back({binary(i),i});
        }
        sort(temp.begin(),temp.end());
        vector<int> ans;
        for(auto &i: temp) {
            ans.push_back(i[1]);
        }
        return ans;
    }
};