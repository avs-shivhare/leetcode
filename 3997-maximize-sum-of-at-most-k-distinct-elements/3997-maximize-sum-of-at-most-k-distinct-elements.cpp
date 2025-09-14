class Solution {
public:
    vector<int> maxKDistinct(vector<int>& nums, int k) {
        priority_queue<int,vector<int>,greater<int>> q;
        unordered_map<int,int> mpp;
        vector<int> ans;
        for(auto i: nums) {
            if(mpp[i] == 0) {
                if(q.size() < k) {
                    q.push(i);
                    mpp[i]++;
                }
                else if(q.top() < i) {
                    mpp[q.top()]--;
                    q.pop();
                    q.push(i);
                    mpp[i]++;
                }
            }
        }
        while(!q.empty()) {
            ans.push_back(q.top());
            q.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};