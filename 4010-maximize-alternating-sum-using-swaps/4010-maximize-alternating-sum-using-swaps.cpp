class DisJoinSet {
    public:
    vector<int> size,parent;
    DisJoinSet(int n) {
        size.resize(n,1);
        parent.resize(n);
        iota(parent.begin(),parent.end(),0);
    }
    int findParent(int n) {
        if(parent[n] == n) return n;
        return parent[n] = findParent(parent[n]);
    }
    void add(int a,int b) {
        int ua = findParent(a);
        int ub = findParent(b);
        if(ua == ub) return;
        if(size[ua] > size[ub]) {
            parent[ub] = ua;
            size[ua] += size[ub];
        }
        else {
            parent[ua] = ub;
            size[ub] += size[ua];
        }
        return;
    }
};

class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums, vector<vector<int>>& swaps) {
        int n = nums.size();
        DisJoinSet ds(n);
        for(auto i: swaps) {
            ds.add(i[0],i[1]);
        }
        map<int,multiset<long long>> mpp;
        for(int i = 0; i<n; i++) {
            mpp[ds.findParent(i)].insert(nums[i]);
        }
        long long sum = 0;
        for(int i = 0; i<n; i++) {
            int p = ds.findParent(i);
            long long el = 0;
            if(i&1) {
                el = *(mpp[p].begin());
            }
            else {
                el = *prev(mpp[p].end());
            }
            mpp[p].erase(mpp[p].find(el));
            nums[i] = el;
            if(i&1) sum -= nums[i];
            else sum += nums[i];
        }
        return sum;
    }
};