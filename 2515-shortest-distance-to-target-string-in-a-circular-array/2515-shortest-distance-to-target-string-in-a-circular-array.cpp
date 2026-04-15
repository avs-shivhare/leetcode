class Solution {
public:
    int closestTarget(vector<string>& words, string target, int s) {

        int n = words.size();
        int ans = 1e9;
        for(int i = 0; i<n; i++) {
            if(words[i] == target) {
                int next = (i+n-s)%n;
                int prev = n;
                if(i < s) prev = s-i;
                else prev = s+(n-i);
                ans = min({ans,next,prev});
            }
        }
        if(ans == 1e9) return -1;
        return ans;
    }
};