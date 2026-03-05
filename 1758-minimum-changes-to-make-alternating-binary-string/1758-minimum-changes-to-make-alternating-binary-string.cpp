class Solution {
public:
    int find(string &s,bool flag) {
        int ans = 0;
        for(auto &i: s) {
            if(flag) {
                if(i == '1') ans++;
            }
            else {
                if(i == '0') ans++;
            }
            flag = !flag;
        }
        return ans;
    }
    int minOperations(string s) {
        return min(find(s,false),find(s,true));
    }
};