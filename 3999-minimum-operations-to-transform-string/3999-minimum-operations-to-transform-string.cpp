class Solution {
public:
    int minOperations(string s) {
        vector<int> fre(26,0);
        for(auto i: s) fre[i-'a']++;
        int cnt = 0;
        for(int i =1; i<26; i++) {
            if(fre[i]) cnt++;
            if(i+1 < 26) fre[i+1] += fre[i]; 
        }
        return cnt;
    }
};