class Solution {
public:
    string generateString(string str1, string str2) {
        int n = str1.size();
        int m = str2.size();
        string ans(n+m-1,' ');
        vector<bool> vis(n+m-1,false);
        for(int i = 0; i<n; i++) {
            if(str1[i] == 'T') {
                for(int j = 0; j<m; j++) {
                    if(ans[i+j] != str2[j] && vis[i+j]) return "";
                    ans[i+j] = str2[j];
                    vis[i+j] = true;
                }
            }
        }
        string temp = ans;
        //cout<<ans<<endl;
        for(auto &i: ans) {
            if(i == ' ') i = 'a';
        }
        for(int i = 0; i<n; i++) {
            if(str1[i] == 'F') {
                bool flag = false;
                for(int j = 0; j<m; j++) {
                    if(ans[i+j] != str2[j]) {
                        flag = true;
                        break;
                    }
                }
                if(flag) continue;
                for(int j = m-1; j>=0; j--) {
                    if(temp[i+j] == ' ') {
                        ans[i+j] = 'b';
                        flag = true;
                        break;
                    }
                }
                if(!flag) return "";
            }
        }
        return ans;
    }
};