class Solution {
public:
    long long minCost(vector<int>& b1, vector<int>& b2) {
        unordered_map<int,int> mpp;
        for(auto i: b1) mpp[i]++;
        for(auto i: b2) mpp[i]--;
        int mini = INT_MAX;
        vector<int> temp;
        for(auto i: mpp) {
            if(i.second%2) return -1;
            for(int j = 0; j<abs(i.second)/2; j++) temp.push_back(i.first);
            mini = min(mini,i.first);
        }
        sort(temp.begin(),temp.end());
        long long cost = 0;
        for(int i = 0; i<temp.size()/2; i++) {
            cost += min((long long)temp[i],2ll*mini);
        }
        return cost;
    }
};