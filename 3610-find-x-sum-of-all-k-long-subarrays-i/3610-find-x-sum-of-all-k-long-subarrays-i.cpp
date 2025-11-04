class Solution {
public:
    vector<int> findXSum(vector<int>& nums, int k, int x) {
        unordered_map<int,int> mpp;
        int l = 0, r= 0;
        int n = nums.size();
        vector<int> ans;
        while(r<n) {
            mpp[nums[r]]++;
            while(l<r && r-l+1 > k) {
                mpp[nums[l]]--;
                if(mpp[nums[l]] == 0) mpp.erase(nums[l]);
                l++;
            }
            if(r-l+1 == k) {
                priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> q;
                int sum = 0;
                for(auto &i: mpp) {
                    if(q.size() < x) {
                        q.push({i.second,i.first});
                        sum += i.second*i.first;
                    }
                    else if(q.top().first < i.second || (q.top().first == i.second && q.top().second < i.first)) {
                        sum -= q.top().first*q.top().second;
                        q.pop();
                        q.push({i.second,i.first});
                        sum += i.second*i.first;
                    }
                }
                // cout<<l<<" "<<r<<" "<<sum<<endl;
                // while(!q.empty()) {
                //     cout<<q.top().first<<" "<<q.top().second<<endl;
                //     q.pop();
                // }
                ans.push_back(sum);
            } 
            r++;
        }
        return ans;
    }
};