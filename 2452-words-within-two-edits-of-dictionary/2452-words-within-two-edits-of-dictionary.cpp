class Solution {
public:
    vector<string> twoEditWords(vector<string>& q, vector<string>& d) {
        vector<string> ans;
        for(auto &i: q) {
            for(auto &j: d) {
                int cnt = 0;
                if(i.size() != j.size()) continue;
                for(int k = 0; k<i.size(); k++) {
                    if(i[k] != j[k]) cnt++;
                }
                if(cnt <= 2) {
                    ans.push_back(i);
                    break;
                }
            }
        }
        return ans;
    }
};