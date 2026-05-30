class SG {
    public:
    int maxi = 1e5;
    vector<int> sg;
    SG() {
       sg.resize(4*maxi+1,0); 
    }
    void update(int index,int val) {
        u(0,maxi,0,index,val);
    }
    void u(int l,int r,int ind,int &index,int &val) {
        if(l > r || r < index || index < l) return;
        if(l == r) {
            sg[ind] = val;
            return;
        }
        int mid = (l+r)>>1;
        u(l,mid,2*ind+1,index,val);
        u(mid+1,r,2*ind+2,index,val);
        sg[ind] = max(sg[2*ind+1],sg[2*ind+2]);
        return;
    }
    int query(int r) {
        return q(0,maxi,0,0,r);
    }
    int q(int l,int r,int ind,int ql,int qr) {
        if(l > r || r < ql || l > qr) return 0;
        if(ql <= l && r <= qr) return sg[ind];
        int mid = (l+r)>>1;
        return max(q(l,mid,2*ind+1,ql,qr),q(mid+1,r,2*ind+2,ql,qr));
    }
};

class Solution {
public:
    vector<bool> getResults(vector<vector<int>>& queries) {
        SG s;
        set<int> st;
        st.insert(0);
        for(auto &i: queries) {
            if(i[0] == 1) st.insert(i[1]);
        }
        vector<int> pos(st.begin(),st.end());
        int n = pos.size();
        for(int i = 1; i<n; i++) {
            s.update(pos[i],pos[i]-pos[i-1]);
        }
        vector<bool> ans;
        for(int i = queries.size()-1; i>=0; i--) {
            if(queries[i][0] == 1) {
                auto x = st.find(queries[i][1]);
                auto p = prev(x);
                s.update(*x,0);
                auto nxt = next(x);
                if(nxt != st.end()) s.update(*nxt,*nxt-*p);
                st.erase(*x);
            }
            else {
                auto last = prev(st.upper_bound(queries[i][1]));
                int best = s.query(*last);
                best = max(best,queries[i][1]-*last);
                ans.push_back(best >= queries[i][2]);
            }
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};