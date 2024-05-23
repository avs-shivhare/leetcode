class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        int n = arr.size();
        unordered_map<int,int> mpp;
        for(int i: arr) mpp[i]++;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> q;
        for(auto i: mpp) {
            q.push({i.second,i.first});
        }
        while(!q.empty() && k> 0) {
            int fr = q.top().first;
            int val = q.top().second;
            q.pop();
            while(k>0 && fr > 0) {
                k--;
                fr--;
            }
            if(fr != 0) q.push({fr,val});
        }
        return q.size();
    }
};