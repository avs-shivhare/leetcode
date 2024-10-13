class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        int mini = -1e6;
        int maxi = 1e6;
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> q;
        priority_queue<pair<int,pair<int,int>>> q2;
        int n = nums.size();
        map<pair<int,int>,int> mpp;
        for(int i =0; i<n; i++) {
            q.push({nums[i][0],{i,0}});
            q2.push({nums[i][0],{i,0}});
        }
        while(true) {
            auto x = q.top();
            auto y = q2.top();
            //cout<<y.first<<" "<<x.first<<endl;
            if(maxi-mini > y.first - x.first) {
                maxi = y.first;
                mini = x.first;
            }
            else if(maxi-mini == y.first-x.first && x.first < mini) {
                maxi = y.first;
                mini = x.first;
            }
            q.pop();
            int ind = x.second.first;
            int ind2 = x.second.second;
            mpp[{ind,ind2}] = x.first;
            if(ind2+1 < nums[ind].size()) {
                q.push({nums[ind][ind2+1],{ind,ind2+1}});
                q2.push({nums[ind][ind2+1],{ind,ind2+1}});
            }
            else break;
            while(mpp.count({q2.top().second.first,q2.top().second.second})) {
                mpp.erase({q2.top().second.first,q2.top().second.second});
                q2.pop();
            }
        }
        return {mini,maxi};
    }
};