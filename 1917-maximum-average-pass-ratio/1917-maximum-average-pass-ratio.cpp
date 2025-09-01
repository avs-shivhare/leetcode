class Solution {
public:
    long double find(long double i,long double j) {
        return (i+1)/(j+1)-i/j;
    }
    double maxAverageRatio(vector<vector<int>>& cl, int ex) {
        priority_queue<pair<long double,pair<int,int>>> q;
        for(auto i: cl) {
            q.push({find(i[0],i[1]),{i[0],i[1]}});
        }
        int n = cl.size();
        while(!q.empty() && ex--) {
            auto i = q.top().second.first+1;
            auto j = q.top().second.second+1;
            q.pop();
            q.push({find(i,j),{i,j}});
        }
        long double avg = 0;
        while(!q.empty()) {
            //cout<<q.top()[1]<<" "<<q.top()[2]<<endl;
            avg += (long double)q.top().second.first/(long double)q.top().second.second;
            q.pop();
        }
        return avg/n;
    }
};