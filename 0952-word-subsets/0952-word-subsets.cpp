class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        vector<int> fre(26,0);
        for(auto i: words2) {
            vector<int> temp(26,0);
            for(auto j: i) temp[j-'a']++;
            for(int j = 0; j<26; j++) fre[j] = max(fre[j],temp[j]);
        }
        vector<string> ans;
        for(auto i: words1) {
            vector<int> temp(26,0);
            for(auto j: i) temp[j-'a']++;
            bool flag = true;
            for(int j = 0; j<26; j++) {
                if(fre[j] > temp[j]) {
                    //cout<<i<<" -> "<<fre[j]<<" "<<temp[j]<<" "<<(char)(j+'a')<<endl;
                    flag = false;
                    break;
                }
            }
            if(flag) ans.push_back(i);
        }
        return ans;
    }
};