class Solution {
public:
    vector<bool> camelMatch(vector<string>& queries, string pattern) {
        int n = queries.size();
        vector<bool> ans(n,false);
        for(int i =0; i<n; i++) {
            string temp = queries[i];
            int x = 0,y = 0;
            bool flag = true;
            while(x<pattern.size() && y<temp.size()) {
                if(pattern[x]  == temp[y]) {
                    x++;
                    y++;
                }
                else if('A'<= temp[y] && temp[y] <= 'Z') {
                    flag = false;
                    break;
                }
                else y++;
            }
            if(x != pattern.size()) flag = false;
            while(y < temp.size()) {
                if('A'<= temp[y] && temp[y] <= 'Z') {
                    flag = false;
                    break;
                }
                y++;
            }
            if(flag) ans[i] = true;
        }
        return ans;
    }
};