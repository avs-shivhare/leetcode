class Solution {
public:
    bool check(char x) {
        if(x == 'a' || x == 'e' || x == 'o' || x == 'i' || x == 'u') return true;
        return false;
    }
    long long countOfSubstrings(string word, int k) {
        int n = word.size();
        int l = 0,r = 0;
        long long ans =0;
        vector<int> prefix(n,0);
        int x = n;
        prefix[n-1] = n;
        for(int i = n-1; i>=0; i--) {
            prefix[i] = x;
            if(!check(word[i])) {
                x = i;
            }
        }
        int con = 0;
        unordered_map<char,int> mpp;
        while(r<n) {
            if(check(word[r])) {
                mpp[word[r]]++;
            }
            else con++;
            while(l<r && con > k) {
                if(check(word[l])) {
                    mpp[word[l]]--;
                    if(mpp[word[l]] == 0) mpp.erase(word[l]);
                }
                else con--;
                l++;
            }
            if(con == k && mpp.size() == 5 ) {
                while(l<r && con == k && mpp.size() == 5) {
                    ans += prefix[r]-r;
                    if(check(word[l])) {
                        mpp[word[l]]--;
                        if(mpp[word[l]] == 0) mpp.erase(word[l]);
                    }
                    else con--;
                    l++;
                }
            }
            r++;
        }
        return ans;
    }
};