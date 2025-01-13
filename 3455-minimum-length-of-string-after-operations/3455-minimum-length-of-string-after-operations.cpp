class Solution {
public:
    int minimumLength(string s) {
        unordered_map<char,vector<int>> mpp;
        int n = s.size();
        for(int i = 0; i<n; i++) {
            mpp[s[i]].push_back(i);
            if(mpp[s[i]].size() == 3) {
                int first = mpp[s[i]][0];
                int last = mpp[s[i]][2];
                mpp[s[i]][0] = mpp[s[i]][1];
                mpp[s[i]].pop_back();
                mpp[s[i]].pop_back();
                s[first] = '1';
                s[last] = '1';
            }
            
        }
        int cnt = 0;
        for(auto i: s) {
            //cout<<i<<" ";
            if(i != '1') cnt++;
        }
        //cout<<endl;
        return cnt;
    }
};