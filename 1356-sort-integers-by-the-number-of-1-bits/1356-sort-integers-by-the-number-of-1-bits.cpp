class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
        vector<pair<int,int>> temp;
        for(auto &i: arr) {
            int cnt = 0;
            for(int j = 0; j<32; j++) {
                if(i&(1<<j)) cnt++;
            }
            temp.push_back({cnt,i});
        }
        sort(temp.begin(),temp.end(),[&](auto &a,auto &b){
            if(a.first == b.first) return a.second <= b.second;
            return a.first <= b.first;
        });
        vector<int> ans;
        for(auto &i: temp) ans.push_back(i.second);
        return ans;
    }
};