class Solution {
public:
    double mincostToHireWorkers(vector<int>& quality, vector<int>& wage, int k) {
        int n = quality.size();
        vector<pair<double,int>> ratio;
        for(int i =0; i<n; i++) {
            double r = (double)wage[i]/(double)quality[i];
            ratio.push_back({r,i});
        }
        sort(ratio.begin(),ratio.end());
        priority_queue<int> q;
        double maxRatio = 0.0;
        int totalQuality = 0;
        for(int i =0; i<k; i++) {
            maxRatio = max(maxRatio,ratio[i].first);
            totalQuality += quality[ratio[i].second];
            q.push(quality[ratio[i].second]);
        }
        double ans = maxRatio*totalQuality;
        for(int i = k; i<n; i++) {
            totalQuality -= q.top();
            q.pop();
            maxRatio = max(maxRatio,ratio[i].first);
            totalQuality += quality[ratio[i].second];
            ans = min(ans,totalQuality*maxRatio);
            q.push(quality[ratio[i].second]);
        }
        return ans;
    }
};