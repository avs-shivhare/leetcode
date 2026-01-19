class SG{
    vector<int> sg;
    public:
    SG(int n) {
        sg.resize(4*n+1,0);
    }
    void build(vector<vector<int>> &arr,int l,int r,int ind) {
        if(l == r) {
            sg[ind] = arr[l][1];
            return;
        }
        int mid = (l+r)>>1;
        build(arr,l,mid,2*ind+1);
        build(arr,mid+1,r,2*ind+2);
        sg[ind] = max(sg[2*ind+1],sg[2*ind+2]);
        return;
    }
    int query(int l,int r,int ql,int qr,int ind) {
        //if(r>l) return 0;
        if(l > qr || r < ql) return 0;
        if(ql <= l && r <= qr) return sg[ind];
        int mid = (l+r)>>1;
        return max(query(l,mid,ql,qr,2*ind+1),query(mid+1,r,ql,qr,2*ind+2));
    }
};
class Solution {
public:
    int find(vector<vector<int>> &arr,int last) {
        int l = 0,r = arr.size()-1;
        int ans = -1;
        while(l<=r) {
            int mid = (l+r)>>1;
            if(arr[mid][0]<last) {
                ans = mid;
                l = mid+1;
            }
            else r = mid-1;
        }
        return ans;
    }
    int maxCapacity(vector<int>& costs, vector<int>& capacity, int b) {
        int n = costs.size();
        vector<vector<int>> temp(n);
        for(int i = 0; i<n; i++) {
            temp[i] = {costs[i],capacity[i]};
        }
        sort(temp.begin(),temp.end());
        SG s(n);
        s.build(temp,0,n-1,0);
        int ans = 0;
        // for(auto &i: temp) cout<<i[1]<<" ";
        // cout<<endl;
        // for(auto &i: temp) cout<<i[0]<<" ";
        // cout<<endl;
        for(int i = 0; i<n; i++) {
            if(temp[i][0] >= b) continue;
            int rem = b-temp[i][0];
            int ind = find(temp,rem);
            int total = temp[i][1];
            int x = 0;
            if(ind != -1) {
                if(i <= ind) {
                    x += max(s.query(0,n-1,0,i-1,0),s.query(0,n-1,i+1,ind,0));
                }
                else x += s.query(0,n-1,0,ind,0);
            }
            //cout<<i<<" "<<ind<<" "<<total<<" "<<x<<endl;
            ans = max(ans,total+x);
        }
        return ans;
    }
};