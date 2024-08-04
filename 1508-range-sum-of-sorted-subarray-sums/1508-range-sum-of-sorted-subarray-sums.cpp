class Solution {
public:
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        priority_queue<int> q;
        for(int i =0; i<n; i++) {
            int sum = 0;
            for(int j = i; j<n; j++) {
                sum += nums[j];
                //cout<<sum<<endl;
                if(q.size() < right) {
                    q.push(sum);
                }
                else if(q.top() > sum) {
                    q.pop();
                    q.push(sum);
                }
            }
        }
        int ans =0;
        int mod = 1e9+7;
        while(!q.empty() && right) {
            if(right >= left) {
                ans = (ans+q.top())%mod;
                right--;
            }
            else break;
            q.pop();
        }
        return ans;
    }
};