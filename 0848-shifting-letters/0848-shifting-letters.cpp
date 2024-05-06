class Solution {
public:
    char shift(char i,int dist) {
        int temp = ((i-'a')+dist)%26;
        return temp+'a';
    }
    string shiftingLetters(string s, vector<int>& arr) {
        int n = arr.size();
        for(int i = n-1; i>0; i--) {
            arr[i] %= 26;
            arr[i-1] %= 26;
            arr[i-1] = (arr[i]+arr[i-1])%26;
        }
        for(int i =0;i<n; i++) {
            s[i] = shift(s[i],arr[i]);
        }
        return s;
    }
};