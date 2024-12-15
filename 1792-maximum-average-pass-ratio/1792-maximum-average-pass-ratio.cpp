class Solution {
public:
    double maxAverageRatio(vector<vector<int>>& cl, int ex) {
        priority_queue<pair<double,int>> q;
        int n = cl.size();
        for(int i = 0; i<n; i++) {
            double temp = (double)cl[i][0]/(double)cl[i][1];
            double temp2 = ((double)cl[i][0]+1)/((double)cl[i][1]+1);
            q.push({temp2-temp,i});
        }
        while(!q.empty() && ex--) {
            auto i = q.top().second;
            q.pop();
            cl[i][0]++;
            cl[i][1]++;
            double temp = (double)cl[i][0]/(double)cl[i][1];
            double temp2 = ((double)cl[i][0]+1)/((double)cl[i][1]+1);
            q.push({temp2-temp,i});
        } 
        double sum = 0;
        for(auto i: cl) {
            sum +=(double)i[0]/(double)i[1];
        }
        return sum/n;
    }
};