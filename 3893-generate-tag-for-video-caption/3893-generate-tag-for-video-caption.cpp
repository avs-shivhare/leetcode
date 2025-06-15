class Solution {
public:
    string generateTag(string caption) {
        stringstream s(caption);
        string ans = "#";
        string temp = "";
        while(s>>temp) {
            if(ans == "#") {
                for(auto i: temp) {
                    ans += tolower(i);
                }
            }
            else {
                ans += toupper(temp[0]);
                for(int i = 1; i<temp.size(); i++) {
                    ans += tolower(temp[i]);
                }
            }
        }
        while(ans.size() > 100) ans.pop_back();
        return ans;
    }
};