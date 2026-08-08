class Solution {
public:
    vector<int> validSequence(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();
        vector<int> prefix(n,0),suffix(n,0);
        vector<int> pindex(n,0),sindex(n,m);
        int j = 0;
        for(int i = 0; i<n; i++) {
            prefix[i] = j;
            pindex[i] = max(0,j-1);
            if(j < m && word1[i] == word2[j]) j++;
        }
        j = m-1;
        for(int i = n-1; i>=0; i--) {
            suffix[i] = m-1-j;
            sindex[i] = min(m-1,j+1);
            if(j >= 0 && word1[i] == word2[j]) j--;
        }
        for(int i = 0; i<n; i++) {
            if(prefix[i]+suffix[i] >= m-1) {
                int x = 0,j = 0;
                vector<int> ans;
                while(j < prefix[i]) {
                    if(word1[x] == word2[j]) {
                        ans.push_back(x);
                        j++;
                    }
                    x++;
                }
                int one = 1;
                while(j<m) {
                    if(word1[x] == word2[j]) {
                        ans.push_back(x);
                        j++;
                    }
                    else if(one) {
                        ans.push_back(x);
                        j++;
                        one--;
                    }
                    x++;
                }
                return ans;
            }
        }
        return {};
    }
};