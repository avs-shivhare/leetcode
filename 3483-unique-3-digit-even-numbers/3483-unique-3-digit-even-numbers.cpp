class Solution {
public:
    unordered_set<int> st;
    int vis[11];
    void find(int i,vector<int> &digits,int num) {
        if(i >= 3) {
            if(99 < num && num < 1000 && (num&1) == 0) st.insert(num);
            return;
        }
        for(int j = 0; j<digits.size(); j++) {
            if(vis[j] == 0) {
                vis[j] = 1;
                find(i+1,digits,num*10+digits[j]);
                vis[j] = 0;
            }
        }
        return;
    }
    int totalNumbers(vector<int>& digits) {
        memset(vis,0,sizeof(vis));
        find(0,digits,0);
        //for(auto &i: st) cout<<i<<endl;
        return st.size();
    }
};