class SG  {
    public:
    vector<int> sg;
    SG(int n) {
        sg.resize(4*n+1);
    }
    void build(int l,int r,vector<int> &arr,int ind) {
        if(l == r) {
            sg[ind] = arr[l];
            return;
        }
        int mid = (l+r)>>1;
        build(l,mid,arr,2*ind+1);
        build(mid+1,r,arr,2*ind+2);
        sg[ind] = max(sg[2*ind+1],sg[2*ind+2]);
        return;
    }
    int query(int l,int r,int ql,int qr,int ind) {
        if(l > r || r < ql || qr < l) return 0;
        if(ql <= l && r <= qr) return sg[ind];
        int mid = (l+r)>>1;
        return max(query(l,mid,ql,qr,2*ind+1),query(mid+1,r,ql,qr,2*ind+2));
    }
};
class Solution {
public:
    bool check(int r,int n) {
        if(r >= 0 && r < n) return true;
        return false;
    }
    int countLocalMaximums(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<SG*> col(m);

        for(int j = 0; j<m; j++) {
            col[j] = new SG(n);
            vector<int> temp;
            for(int i = 0; i<n; i++) {
                temp.push_back(matrix[i][j]);
            }
            col[j]->build(0,n-1,temp,0);
        }
        int cnt = 0;
        for(int i = 0; i<n; i++) {
            for(int j = 0; j<m; j++) {
                if(matrix[i][j] == 0) continue;
                int maxi = 0;
                int rl = i-matrix[i][j];
                int rr = i+matrix[i][j];
                int cl = j-matrix[i][j];
                int cr = j+matrix[i][j];
                if(check(cl,m)) {
                    maxi = max(col[cl]->query(0,n-1,rl+1,rr-1,0),maxi);
                }
                if(check(cr,m)) {
                    maxi = max(col[cr]->query(0,n-1,rl+1,rr-1,0),maxi);
                }
                for(int x = max(0,cl+1); x < min(m,cr); x++) {
                    maxi = max(maxi,col[x]->query(0,n-1,rl,rr,0));
                }
                if(maxi <= matrix[i][j]) {
                    cnt++;
                    //cout<<i<<" "<<j<<" "<<maxi<<endl;
                }
            }
        }
        return cnt;
    }
};