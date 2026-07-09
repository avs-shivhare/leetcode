class Union {
    public:
    vector<int> size,parent;
    Union(int n) {
        size.resize(n,1);
        parent.resize(n,0);
        iota(parent.begin(),parent.end(),0);
    }
    int find(int n) {
        if(n == parent[n]) return n;
        return parent[n] = find(parent[n]);
    }
    void add(int a,int b) {
        int ua = find(a);
        int ub = find(b);
        if(ua == ub) return;
        if(size[ua] < size[ub]) swap(ua,ub);
        size[ua] += size[ub];
        parent[ub] = ua;
        return;
    }
};
class Solution {
public:
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int max, vector<vector<int>>& queries) {
        int l = 0, r = 0;
        Union ds(n);
        while(r<n) {
            while(l<=r && nums[r]-nums[l] > max) {
                l++;
            }
            if(l<=r && nums[r]-nums[l] <= max) {
                ds.add(l,r);
            }
            r++;
        }
        vector<bool> ans;
        for(auto &i: queries) {
            ans.push_back(ds.find(i[0]) == ds.find(i[1]));
        }
        return ans;
    }
};