class Solution {
public:
    vector<string> ans;
    string temp = "";
    void find(int n,int cnt) {
        if(cnt < 0) return;
        if(n == 0) {
            if(cnt == 0) ans.push_back(temp);
            return;
        }
        temp.push_back('(');
        find(n-1,cnt+1);
        temp.pop_back();
        temp.push_back(')');
        find(n-1,cnt-1);
        temp.pop_back();
        return;
    }
    vector<string> generateParenthesis(int n) {
        find(2*n,0);
        return ans;
    }
};