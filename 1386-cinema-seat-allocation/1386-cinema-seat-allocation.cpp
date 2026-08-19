class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& rev) {
        unordered_map<int,vector<int>> mpp;
        for(auto &i: rev) {
            mpp[i[0]].push_back(i[1]);
        }
        int ans = 0;
        vector<pair<int,int>> temp = {{2,5},{4,7},{6,9}};
        for(auto &i: mpp) {
            i.second.push_back(1);
            i.second.push_back(10);
            sort(i.second.begin(),i.second.end());
            int last = 1;
            for(auto &j: i.second) {
                for(auto &x: temp) {
                    if(last < x.first && x.second < j) {
                        ans++;
                        last = x.second;
                    }
                }
                last = j;
            }
            //cout<<endl;
        }
        ans += (n-((int)mpp.size()))*2;
        return ans;
    }
};