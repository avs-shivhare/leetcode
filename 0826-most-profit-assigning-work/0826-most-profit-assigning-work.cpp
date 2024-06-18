class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        vector<pair<int,int>> diff;
        int n = profit.size();
        for(int i =0; i<n; i++) {
            diff.push_back({profit[i],difficulty[i]});
        }
        sort(diff.begin(),diff.end(),greater<pair<int,int>>());
        sort(worker.begin(),worker.end(),greater<int>());
        int sum = 0;
        int m = worker.size();
        int i =0,j =0;
        while(i<n && j<m) {
            if(worker[j] >= diff[i].second) {
                sum += diff[i].first;
                j++;
            }
            else {
                i++;
            }
        }
        return sum;
    }
};