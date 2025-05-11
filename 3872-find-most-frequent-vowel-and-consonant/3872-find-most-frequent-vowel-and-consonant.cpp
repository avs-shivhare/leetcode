class Solution {
public:
    int maxFreqSum(string s) {
        unordered_map<char,int> mpp;
        for(auto i: s) {
            mpp[i]++;
        }
        int v = 0,c = 0;
        for(auto i: mpp) {
            if(i.first == 'a' || i.first == 'e' || i.first == 'i' || i.first == 'o' || i.first == 'u') {
                v = max(v,i.second);
            }
            else {
                c = max(c,i.second);
            }
        }
        return v+c;
    }
};