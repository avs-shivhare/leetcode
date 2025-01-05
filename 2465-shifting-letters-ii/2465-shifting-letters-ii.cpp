class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        int n = s.size();
        int prefix[n];
        memset(prefix,0,sizeof(prefix));
        for(auto i: shifts) {
            if(i[2] == 1) {
                prefix[i[0]]++;
                if(i[1]+1 < n) prefix[i[1]+1]--;
            }
            else {
                prefix[i[0]]--;
                if(i[1]+1 < n) prefix[i[1]+1]++;
            }
        }
        int curr = 0;
        for(int i = 0; i<n; i++) {
            curr += prefix[i];
            if(curr < 0) {
                int x = s[i]-'a';
                //cout<<x<<" "<<curr<<endl;
                x = ((x-(abs(curr)%26))+26)%26;
                //cout<<x<<endl;
                s[i] = (x+'a');
            }
            else {
                int x = s[i]-'a';
                x = (x+curr)%26;
                s[i] = (x+'a');
            }
        }
        return s;
    }
};