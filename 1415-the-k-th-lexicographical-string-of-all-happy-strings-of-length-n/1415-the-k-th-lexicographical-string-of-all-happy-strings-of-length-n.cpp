class Solution {
public:
    string temp = "";
    vector<string> ans;
    void find(int n,char last) {
        if(n == 0) {
            ans.push_back(temp);
            return;
        }
        if(last != 'a') {
            temp.push_back('a');
            find(n-1,'a');
            temp.pop_back();
        }
        if(last != 'b') {
            temp.push_back('b');
            find(n-1,'b');
            temp.pop_back();
        }
        if(last != 'c') {
            temp.push_back('c');
            find(n-1,'c');
            temp.pop_back();
        }
        return;
    }
    string getHappyString(int n, int k) {
        find(n,'d');
        sort(ans.begin(),ans.end());
        if(k-1<ans.size()) return ans[k-1];
        return "";
    }
};