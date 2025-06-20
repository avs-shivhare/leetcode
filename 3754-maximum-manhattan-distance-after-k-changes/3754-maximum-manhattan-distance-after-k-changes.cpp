class Solution {
public:
    int maxDistance(string s, int k) {
        int ans = 0;
        int t = k;
        int sum = 0;
        for(auto i: s) {
            if(i == 'E' || i == 'N') sum++;
            else if(t > 0) {
                sum++;
                t--;
            }
            else sum--;
            ans = max(ans,sum);
        }
        t = k;
        sum = 0;
        for(auto i: s) {
            if(i == 'E' || i == 'S') {
                sum++;
            }
            else if(t > 0) {
                sum++;
                t--;
            }
            else sum--;
            ans = max(ans,sum);
        }
        sum = 0;
        t = k;
        for(auto i: s) {
            if(i == 'S' || i == 'W') {
                sum++;
            }
            else if(t > 0) {
                sum++;
                t--;
            }
            else sum--;
            ans = max(ans,sum);
        }
        sum = 0;
        t = k;
        for(auto i: s) {
            if(i == 'W' || i == 'N') sum++;
            else if(t > 0) {
                sum++;
                t--;
            }
            else sum--;
            ans = max(ans,sum);
        }
        return ans;
    }
};