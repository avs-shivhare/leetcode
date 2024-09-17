class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        stringstream ss1(s1);
        stringstream ss2(s2);
        unordered_map<string,int> mpp1,mpp2;
        string temp = "";
        while(ss1 >> temp) {
            mpp1[temp]++;
        }
        while(ss2 >> temp) {
            mpp2[temp]++;
        }
        vector<string> ans;
        for(auto i: mpp1) {
            if(i.second == 1 && mpp2.count(i.first) == 0) ans.push_back(i.first);
        }
        for(auto i: mpp2) {
            if(i.second == 1 && mpp1.count(i.first) == 0) ans.push_back(i.first);
        }
        return ans;
    }
};