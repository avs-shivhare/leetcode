class KthLargest {
public:
    priority_queue<int,vector<int>,greater<int>> q;
    int x =0;
    KthLargest(int k, vector<int>& nums) {
        x = k;
        int n = nums.size();
        for(int i =0; i<n; i++) {
            if(q.size() < k) {
                q.push(nums[i]);
            }
            else {
                if(q.top() < nums[i]) {
                    q.pop();
                    q.push(nums[i]);
                }
            }
        }
    }
    
    int add(int val) {
        if(q.size() < x) q.push(val);
        else if(!q.empty() && q.top() < val) {
            q.pop();
            q.push(val);
        }
        return q.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */