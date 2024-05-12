class Solution {
public:
    vector<int> rearrangeBarcodes(vector<int>& bar) {
        unordered_map<int,int> mpp;
        for(int i: bar) {
            mpp[i]++;
        }
        priority_queue<pair<int,int>> q;
        for(auto i: mpp) {
            q.push({i.second,i.first});
        }
        //int n = bar.size();
        vector<int> ans;
        while(!q.empty()) {
            if(q.size() >= 2) {
                auto e1 = q.top();
                q.pop();
                auto e2 = q.top();
                q.pop();
                ans.push_back(e1.second);
                if(e1.first-1 != 0) q.push({e1.first-1,e1.second});
                ans.push_back(e2.second);
                if(e2.first-1 != 0) q.push({e2.first-1,e2.second});
            }
            else {
                auto e1 = q.top();
                q.pop();
                ans.push_back(e1.second);
                //if(e1.first-1 != 0) q.push({e1.first-1,e1.second});
            }
        }
        return ans;
    }
};