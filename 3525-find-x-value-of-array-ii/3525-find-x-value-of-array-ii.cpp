class Node {
    public:
    int pro = 1;
    int cnt[5];
    Node() {
        pro = 1;
        memset(cnt,0,sizeof(cnt));
    }
};

class SG {
    public:
    int k;
    vector<Node> sg;
    SG(int n,int k) {
        sg.resize(4*n+1,Node());
        this->k = k;
    }
    Node compare(Node &l,Node &r) {
        Node ans;
        ans.pro = (l.pro*r.pro)%k;
        for(int i = 0; i<k; i++) {
            ans.cnt[i] = l.cnt[i];
        }
        for(int i = 0; i<k; i++) {
            ans.cnt[(l.pro*i)%k] += r.cnt[i];
        }
        return ans;
    }
    void build(int l,int r,int ind,vector<int> &nums) {
        if(l == r) {
            sg[ind].pro = nums[l]%k;
            sg[ind].cnt[nums[l]%k] = 1;
            return;
        }
        int mid = (l+r)>>1;
        build(l,mid,2*ind+1,nums);
        build(mid+1,r,2*ind+2,nums);
        sg[ind] = compare(sg[2*ind+1],sg[2*ind+2]);
    }
    void update(int l,int r,int ind,int &index,int &val) {
        if(index < l || index > r) return;
        if(l == r) {
            if(index == l) {
                sg[ind].pro = val%k;
                for(int i = 0; i<k; i++) sg[ind].cnt[i] = 0;
                sg[ind].cnt[val%k] = 1;
            }
            return;
        }
        int mid = (l+r)>>1;
        update(l,mid,2*ind+1,index,val);
        update(mid+1,r,2*ind+2,index,val);
        sg[ind] = compare(sg[2*ind+1],sg[2*ind+2]);
    }
    Node query(int l,int r,int ql,int qr,int ind) {
        if(qr < l || ql > r) return Node();
        if(ql <= l && r <= qr) return sg[ind];
        int mid = (l+r)>>1;
        auto left = query(l,mid,ql,qr,2*ind+1);
        auto right = query(mid+1,r,ql,qr,2*ind+2);
        return compare(left,right);
    }
};

class Solution {
public:
    vector<int> resultArray(vector<int>& nums, int k, vector<vector<int>>& queries) {
        vector<int> ans;
        int n = nums.size();
        SG s(n,k);
        s.build(0,n-1,0,nums);
        for(auto &i: queries) {
            s.update(0,n-1,0,i[0],i[1]);
            auto temp = s.query(0,n-1,i[2],n-1,0);
            ans.push_back(temp.cnt[i[3]]);
        }
        return ans;
    }
};