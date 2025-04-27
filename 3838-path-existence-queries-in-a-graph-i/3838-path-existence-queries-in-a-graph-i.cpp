class Union {
    public:
    vector<int> parent,size;
    Union(int n) {
        parent.resize(n,1);
        iota(parent.begin(),parent.end(),0);
        size.resize(n,1);
    }
    int findParent(int u) {
        if(parent[u] == u) return u;
        return parent[u] = findParent(parent[u]);
    }
    void add(int u,int v) {
        int Uu = findParent(u);
        int Uv = findParent(v);
        if(Uv == Uu) return;
        if(size[Uv] < size[Uu]) {
            parent[Uv] = Uu;
            size[Uu] += size[Uv];
        } 
        else {
            parent[Uu] = Uv;
            size[Uv] += size[Uu];
        }
        return;
    }
};

class Solution {
public:
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        int l = 0,r = 0;
        Union us(n);
        while(r<n) {
            while(l<=r && abs(nums[r]-nums[l]) > maxDiff) {
                l++;
            }
            if(abs(nums[r]-nums[l]) <= maxDiff) {
                us.add(r,l);
            }
            r++;
        }
        vector<bool> ans;
        for(auto i: queries) {
            if(us.findParent(i[0]) == us.findParent(i[1])) ans.push_back(true);
            else ans.push_back(false);
        }
        return ans;
    }
};