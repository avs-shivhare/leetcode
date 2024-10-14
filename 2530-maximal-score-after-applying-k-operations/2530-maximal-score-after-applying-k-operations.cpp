class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        priority_queue<long long> q;
        for(auto i: nums) q.push(i);
        long long ans =0;
        while(!q.empty() && k--) {
            auto x =q.top();
            q.pop();
            ans += x;
            long long temp = x/3 + (x%3 != 0?1:0);
            //cout<<temp<<endl;
            if(temp > 0) q.push(temp);
        }
        return ans;
    }
};