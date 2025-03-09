class Solution {
public:
    vector<long long> findMaxSum(vector<int>& nums1, vector<int>& nums2, int k) {
        int n = nums1.size();
        vector<long long> ans(n,0);
        map<int,vector<int>> mpp;
        for(int i = 0; i<n; i++) {
            mpp[nums1[i]].push_back(i);
        }
        priority_queue<long long,vector<long long>,greater<long long>> q;
        long long sum = 0;
        for(auto i: mpp) {
            long long odd = sum;
            for(auto j: i.second) {
                if(q.size() < k) {
                    sum += nums2[j];
                    q.push(nums2[j]);
                }
                else if(q.top() < nums2[j]) {
                    sum -= q.top();
                    q.pop();
                    sum += nums2[j];
                    q.push(nums2[j]);
                }
                ans[j] = odd;
            }
        }
        return ans;
    }
};