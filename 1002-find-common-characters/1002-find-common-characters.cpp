class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        vector<int> fre(26,0);
        int n = words.size();
        for(int i =0; i<words[0].size(); i++) {
            fre[words[0][i]-'a']++;
        }
        for(int i =1; i<n; i++) {
            vector<int> temp(26,0);
            for(int j =0; j<words[i].size(); j++) {
                if(fre[words[i][j]-'a'] > temp[words[i][j]-'a']) {
                    temp[words[i][j]-'a']++;
                }
            }
            fre = temp;
        }
        vector<string> ans;
        for(int i =0; i<26; i++) {
            while(fre[i]--) {
                string t(1,i+'a');
                ans.push_back(t);
            }
        }
        return ans;
    }
};