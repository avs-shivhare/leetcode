class Solution {
public:
    bool canMakeSubsequence(string str1, string str2) {
        int n = str1.size();
        int m = str2.size();
        int i =0,j = 0;
        while(i<n && j<m) {
            int t1 = str2[j]-'a';
            int t2 =str1[i]-'a';
            if((t2+1)%26 == t1 || t2 == t1) j++;
            i++;
        }
        return j == m;
    }
};