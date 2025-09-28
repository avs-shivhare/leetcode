class Solution {
public:
    string majorityFrequencyGroup(string s) {
        unordered_map<char,int> mpp;
        for(auto i: s) mpp[i]++;
        unordered_map<int,string> mpp2;
        for(auto &i: mpp) {
            mpp2[i.second] += i.first;
        }
        int fre = 0;
        string ans = "";
        for(auto i: mpp2) {
            if(ans.size() < i.second.size()) {
                ans = i.second;
                fre = i.first;
            }
            else if(ans.size() == i.second.size() && i.first > fre) {
                ans = i.second;
                fre = i.first;
            }
        }
        return ans;
    }
};