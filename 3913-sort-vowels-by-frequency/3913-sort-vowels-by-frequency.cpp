class Solution {
public:
    string sortVowels(string s) {
        unordered_map<char,pair<int,int>> mpp;
        int n = s.size();
        for(int i = 0; i<n; i++) {
            if(s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u') {
                if(mpp.find(s[i]) != mpp.end()) {
                    mpp[s[i]].first++;
                }
                else {
                    mpp[s[i]] = {1,i};
                }
            }
        }
        vector<pair<int,int>> temp;
        for(auto &i: mpp) {
            temp.push_back(i.second);
        }
        sort(temp.begin(),temp.end(),[&](auto a,auto b){
            if(a.first != b.first) return a.first > b.first;
            return a.second < b.second;
        });
        if(temp.empty()) return s;
        int j = 0;
        string ans = "";
        for(int i = 0; i<n; i++) {
            if(s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u') {
                ans += s[temp[j].second];
                temp[j].first--;
                if(temp[j].first == 0) j++; 
            }
            else ans += s[i];
        }
        return ans;
    }
};