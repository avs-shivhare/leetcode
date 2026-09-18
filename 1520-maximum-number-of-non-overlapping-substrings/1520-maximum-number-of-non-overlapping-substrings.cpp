class Solution {
public:
    bool check(int l,int r,vector<vector<int>> &prefix,vector<int> &fre) {
        for(int i = 0; i<26; i++) {
            if(prefix[r+1][i]-prefix[l][i] == 0) continue;
            if(prefix[r+1][i]-prefix[l][i] != fre[i]) return false;
        }
        return true;
    }
    vector<string> maxNumOfSubstrings(string s) {
        unordered_map<int,vector<int>> mpp;
        int n = s.size();
        vector<vector<int>> prefix(n+1,vector<int>(26,0));
        vector<int> fre(26,0);
        prefix[0] = fre;
        for(int i = 0; i<n; i++) {
            if(mpp[s[i]].size() < 2) mpp[s[i]].push_back(i);
            else mpp[s[i]][1] = i;
            fre[s[i]-'a']++;
            prefix[i+1] = fre;
        }
        vector<pair<int,int>> temp;
        for(int i = 0; i<26; i++) {
            for(int j = i; j<26; j++) {
                if(mpp[i+'a'].empty() || mpp[j+'a'].empty()) continue;
                int l = min(mpp[i+'a'].front(),mpp[j+'a'].front());
                int r = max(mpp[i+'a'].back(),mpp[j+'a'].back());
                if(check(l,r,prefix,fre)) {
                    temp.push_back({l,r});
                }
            }
        }
        //temp.push_back({0,n-1});
        sort(temp.begin(),temp.end(),[&](auto &a,auto &b){
            if(a.second == b.second) return a.first > b.first;
            return a.second <= b.second;
        });
        vector<pair<int,int>> ans;
        for(auto &i: temp) {
            //cout<<i.first<<" "<<i.second<<endl;
            if(ans.empty() || ans.back().second < i.first) ans.push_back(i);
        }
        vector<string> t;
        for(auto &i: ans) {
            //cout<<i.first<<" "<<i.second<<endl;
            string tt = "";
            for(int j = i.first; j<=i.second; j++) tt += s[j];
            t.push_back(tt);
        }
        return t;
    }
};