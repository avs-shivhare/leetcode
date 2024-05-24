class Solution {
public:
    int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {
        int n = words.size();
        vector<int> fr(26,0);
        int maxi = 0;
        for(auto i: letters) fr[i-'a']++;
        for(int i= 0;i<(1<<n); i++) {
            vector<int> Fr(26,0);
            for(int j =0; j<n;j++) {
                if(i&(1<<j)) {
                    for(int k = 0; k<words[j].size(); k++) {
                        Fr[words[j][k]-'a']++;
                    }
                }
            }
            bool flag = true;
            for(int j =0; j<26; j++) {
                if(Fr[j] > fr[j]) {
                    flag = false;
                    break;
                }
            }
            if(flag) {
                int total = 0;
                for(int j =0; j<26; j++) {
                    total += Fr[j]*score[j];
                }
                maxi = max(maxi,total);
            }
        }
        return maxi;
    }
};