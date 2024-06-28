class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        vector<int> en(n,0);
        for(auto i: roads) {
            en[i[0]]++;
            en[i[1]]++;
        }
        priority_queue<pair<int,int>> q;
        for(int i =0; i<n; i++) {
            q.push({en[i],i});
        }
        while(!q.empty()) {
            en[q.top().second]= n--;
            q.pop();
        }
        long long sum =0;
        for(auto i: roads) {
            sum += (en[i[0]]+en[i[1]]);
        }
        return sum;
    }
};