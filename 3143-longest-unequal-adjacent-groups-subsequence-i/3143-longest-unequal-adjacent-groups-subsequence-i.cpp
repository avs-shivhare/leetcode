class Solution {
public:
    vector<string> getLongestSubsequence(vector<string>& words, vector<int>& group) {
        int n = words.size();
        int last0 = -1, last1 = -1;
        vector<int> index(n,-1),temp(n,1);
        int last = 0;
        for(int i = 0; i<n; i++) {
            if(group[i]) {
                if(last0 != -1) {
                    temp[i] += temp[last0];
                    index[i] = last0;
                }
                last1 = i;
            }
            else {
                if(last1 != -1) {
                    temp[i] += temp[last1];
                    index[i] = last1;
                }
                last0 = i;
            }
            if(temp[last] < temp[i]) {
                last = i;
            }
        }
        vector<string> ans;
        while(last != -1) {
            ans.push_back(words[last]);
            last = index[last];
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};