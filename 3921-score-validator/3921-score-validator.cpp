class Solution {
public:
    vector<int> scoreValidator(vector<string>& events) {
        int s = 0,c = 0;
        for(auto &i: events) {
            if(i == "0" || i == "1" || i == "2" || i == "3" || i == "4" || i == "5" || i == "6") s += stoi(i);
            else if(i == "W") c++;
            else s++;
            if(c == 10) break;
        }
        return {s,c};
    }
};