class Solution {
public:
    int find(string &s) {
        int cnt = 0;
        for(auto i: s) {
            if(i == 'a' || i == 'e' || i == 'o' || i == 'u' || i == 'i') cnt++;
        }
        return cnt;
    }
    string reverseWords(string s) {
        vector<string> temp;
        stringstream ss(s);
        string t = "";
        while(ss >> t) {
            temp.push_back(t);
        }
        int cnt = 0;
        int n = temp.size();
        string ans = "";
        for(int i = 0; i<n; i++) {
            if(i == 0) {
                cnt = find(temp[i]);
            }
            else if(find(temp[i]) == cnt) {
                reverse(temp[i].begin(),temp[i].end());
            }
            ans += temp[i]+" ";
        }
        ans.pop_back();
        return ans;
    }
};