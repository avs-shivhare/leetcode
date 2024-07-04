class TreeAncestor {
public:
    int pre[(int)1e5][17];
    void build(vector<int> &parent,int n) {
        for(int i =0; i<n; i++) {
            pre[i][0] = parent[i];
        }
        for(int j = 1; j<17; j++) {
            for(int i =0; i<n; i++) {
                if(pre[i][j-1] == -1) pre[i][j] = -1;
                else pre[i][j] = pre[pre[i][j-1]][j-1];
            }
        }
        return;
    }
    TreeAncestor(int n, vector<int>& parent) {
        memset(pre,0,sizeof(pre));
        build(parent,n);
    }
    
    int getKthAncestor(int node, int k) {
        for(int i =0; i<17; i++) {
            if(k & (1<<i)) {
                if(node != -1) node = pre[node][i];
            }
        }
        return node;
    }
};

/**
 * Your TreeAncestor object will be instantiated and called as such:
 * TreeAncestor* obj = new TreeAncestor(n, parent);
 * int param_1 = obj->getKthAncestor(node,k);
 */