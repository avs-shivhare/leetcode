class Solution {
public:
    struct compare{
        bool operator()(pair<int,int> &t1,pair<int,int> &t2) {
            if(t1.first < t2.first) return false;
            else if(t1.first > t2.first) return true;
            else if(t1.first == t2.first && t1.second >= t2.second) return false;
            return true; 
        }
    };
    vector<int> frequencySort(vector<int>& nums) {
        unordered_map<int,int> mpp;
        for(auto i: nums) {
            mpp[i]++;
        }
        vector<int> ans;
        priority_queue<pair<int,int>,vector<pair<int,int>>,compare> q;
        for(auto i: mpp) {
            q.push({i.second,i.first});
        }
        while(!q.empty()) {
            int n = q.top().first;
            int val = q.top().second;
            while(n--) {
                ans.push_back(val);
            }
            q.pop();
        }
        return ans;
    }
};