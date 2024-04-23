class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> mpp;
        for(int i: nums) {
            mpp[i]++;
        }
        vector<int> ans;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> q;
        
        for(auto i: mpp) {
            //cout<<i.first<<endl;
            if(k >0) {
                q.push({i.second,i.first});
                k--;
            }
            else {
                if(q.top().first < i.second) {
                    q.pop();
                    q.push({i.second,i.first});
                }
            }
        }
        while(!q.empty()) {
            ans.push_back(q.top().second);
            q.pop();
        }
        return ans;
    }
};