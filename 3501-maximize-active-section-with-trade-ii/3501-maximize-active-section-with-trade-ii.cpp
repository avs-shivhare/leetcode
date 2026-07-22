class SG {
    public:
    int n;
    vector<int> sg;
    SG(vector<int> &arr) {
        n = arr.size();
        sg.resize(4*n+1,0);
        if(n) build(0,n-1,0,arr);
    }
    void build(int l,int r,int ind,vector<int> &arr) {
        if(l == r) {
            sg[ind] = arr[l];
            return;
        }
        int mid = (l+r)>>1;
        build(l,mid,2*ind+1,arr);
        build(mid+1,r,2*ind+2,arr);
        sg[ind] = max(sg[2*ind+1],sg[2*ind+2]);
        return;
    }
    int query(int l,int r,int &ql,int &qr,int ind) {
        if(l > r || ql > r || qr < l) return 0;
        if(ql <= l && r <= qr) return sg[ind];
        int mid = (l+r)>>1;
        return max(query(l,mid,ql,qr,2*ind+1),query(mid+1,r,ql,qr,2*ind+2));
    }
    int query(int l,int r) {
        if(n == 0) return 0;
        return query(0,n-1,l,r,0);
    }
};
class Solution {
public:
    vector<int> maxActiveSectionsAfterTrade(string s, vector<vector<int>>& queries) {
        int cnt = 0;
        for(auto &i: s) {
            cnt += (i == '1');
        }
        vector<int> left,right,zero;
        int n = s.size();
        int i = 0;
        while(i<n) {
            int j = i;
            while(j<n && s[i] == s[j]) j++;
            if(s[i] == '0') {
                zero.push_back(j-i);
                left.push_back(i);
                right.push_back(j-1);
            }
            i = j;
        }
        int m = zero.size();
        if(m < 2) return vector<int>(queries.size(),cnt);
        vector<int> arr;
        for(int i = 1; i<m; i++) {
            arr.push_back(zero[i-1]+zero[i]);
        }
        SG ss(arr);
        vector<int> ans;
        for(auto &i: queries) {
            int l = i[0];
            int r = i[1];
            int f = lower_bound(right.begin(),right.end(),l)-right.begin();
            int ls = upper_bound(left.begin(),left.end(),r)-left.begin()-1;
            if(f >= ls || f >= m || ls < 0) {
                ans.push_back(cnt);
                continue;
            }
            int first = right[f]-max(left[f],l)+1;
            int last = min(right[ls],r)-left[ls]+1;
            if(f+1 == ls) {
                ans.push_back(cnt+first+last);
                continue;
            }
            int best = 0;
            best = max(best,first+zero[f+1]);
            best = max(best,zero[ls-1]+last);
            best = max(best,ss.query(f+1,ls-2));
            ans.push_back(cnt+best);
        }
        return ans;
    }
};