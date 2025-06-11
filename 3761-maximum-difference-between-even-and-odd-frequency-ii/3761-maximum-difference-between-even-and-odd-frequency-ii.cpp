class Solution {
public:
    int maxDifference(string s, int k) {
        int ans = INT_MIN;
        int n = s.size();
        for(int x = 0; x<=4; x++) {
            for(int y = 0; y<=4; y++) {
                if(x == y) continue;
                vector<int> prefix(n+1,0),prefix2(n+1,0);
                for(int i = 1; i<=n; i++) {
                    prefix[i] = prefix[i-1]+((s[i-1]-'0') == x);
                    prefix2[i] = prefix2[i-1]+((s[i-1]-'0') == y);
                }
                int mat[2][2] = {{INT_MIN,INT_MIN},{INT_MIN,INT_MIN}};
                int j = 0;
                for(int i = k; i<=n; i++) {
                    while(i-j >= k && prefix[i] > prefix[j] && prefix2[i] > prefix2[j]) {
                        int a= prefix[j]%2;
                        int b = prefix2[j]%2;
                        mat[a][b] = max(mat[a][b],prefix2[j]-prefix[j]);
                        j++;
                    }
                    int a = prefix[i]%2;
                    int b = prefix2[i]%2;
                    int temp = mat[1-a][b];
                    if(temp != INT_MIN) {
                        ans = max(ans,(prefix[i]-prefix2[i])+temp);
                    }
                }
            }
        }
        if(ans == INT_MIN) return -1;
        return ans;
    }
};