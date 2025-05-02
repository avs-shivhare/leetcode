class Solution {
public:
    string pushDominoes(string dom) {
        int n = dom.size();
        vector<int> prefix(n,-1);
        int last = n;
        for(int i = n-1; i>=0; i--) {
            if(dom[i] == 'L') last = i;
            else if(dom[i] == 'R' && last != n) {
                prefix[i] = last;
                last = n;
            }
        }
        last = -1;
        for(int i = 0; i<n; i++) {
            if(dom[i] == 'R') last = i;
            else if(dom[i] == 'L' && last != -1) {
                prefix[i] = last;
                last = -1;
            }
        }
        int i = 0;
        while(i<n) {
            if(dom[i] == 'L') {
                if(prefix[i] != -1) {
                    int l = prefix[i];
                    int r = i;
                    while(l<r) {
                        dom[l] == 'R';
                        dom[r] == 'L';
                        l++;
                        r--;
                    }
                }
                else {
                    dom[i] = '1';
                }
            }
            else if(dom[i] == 'R') {
                if(prefix[i] != -1) {
                    //cout<<i<<" r"<<endl;
                    int l = i;
                    int r = prefix[i];
                    while(l<r) {
                        dom[l] = 'R';
                        dom[r] = 'L';
                        l++;
                        r--;
                    }
                    i = prefix[i];
                }
                else dom[i] = '2';
            }
            i++;
        }
        // for(auto i: prefix) cout<<i<<" ";
        // cout<<endl;
        i = 0;
        while(i<n) {
            if(dom[i] == '2') {
                int x = i+1;
                dom[i] = 'R';
                while(x<n && dom[x] == '.') {
                    dom[x] = 'R';
                    x++;
                }
                i = x;
            }
            else i++;
        }
        i = n-1;
        while(i>=0) {
            if(dom[i] == '1') {
                //cout<<i<<" l"<<endl;
                int x = i-1;
                dom[i] = 'L';
                while(x>=0 && dom[x] == '.') {
                    dom[x] = 'L';
                    x--;
                }
                i = x;
            }
            else i--;
        }
        return dom;
    }
};