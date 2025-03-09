class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors, int k) {

        int n = colors.size();
        int l = 0,r = 0;
        int cnt = 0;
        int ans = 0;
        while(r<n+k-1) {
            if(r>0 && colors[(r-1)%n] == colors[r%n]) cnt++;
            while(l<r && r-l+1 > k) {
                if(l+1< n && colors[l] == colors[l+1]) cnt--;
                l++;
            }
            //cout<<r<<" "<<l<<" "<<cnt<<endl;
            if(r-l+1 == k && cnt == 0) ans++;
            r++;
        }
        return ans;
    }
};