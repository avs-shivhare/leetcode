class Solution {
public:
    int countSeniors(vector<string>& details) {
        int cnt =0;
        for(auto i: details) {
            int x = stoi(i.substr(11,2));
            if(x > 60) cnt++;
        }
        return cnt;
    }
};