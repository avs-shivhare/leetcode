class Solution {
public:
    string decodeCiphertext(string en, int r) {
        int n = en.size();
        int m = n/r;
        vector<string> temp;
        string s = "";
        int cnt = 0;
        for(int i = 0; i<n; i++) {
            s += en[i];
            cnt++;
            if(cnt%m == 0) {
                temp.push_back(s);
                s = "";
            }
            cnt %= m;
        }
        string ans = "";
        for(int i = 0; i<m; i++) {
            int j = 0, k= i;
            while(j<r && k<m) {
                ans += temp[j][k];
                j++;
                k++;
            }
        }
        while(!ans.empty() && ans.back() == ' ') ans.pop_back();
        return ans;
    }
};