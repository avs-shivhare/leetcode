class Solution {
public:
    int findMinDifference(vector<string>& time) {
        sort(time.begin(),time.end());
        int n = time.size();
        int ans =1e9;
        for(int i =1; i<n; i++) {
            int t1 = (time[i-1][0]-'0')*10+(time[i-1][1]-'0');
            t1 *= 60;
            t1 += (time[i-1][3]-'0')*10+(time[i-1][4]-'0');
            int t2 = (time[i][0]-'0')*10+(time[i][1]-'0');
            t2 *= 60;
            t2 += (time[i][3]-'0')*10+(time[i][4]-'0');
            ans = min(ans,abs(t2-t1));
        }
        int t1 = (time[0][0]-'0')*10+(time[0][1]-'0');
        t1+=24;
        t1 *= 60;
        t1 += (time[0][3]-'0')*10+(time[0][4]-'0');
        int t2 = (time[n-1][0]-'0')*10+(time[n-1][1]-'0');
        t2 *= 60;
        t2 += (time[n-1][3]-'0')*10+(time[n-1][4]-'0');
        ans = min(ans,abs(t2-t1));
        return ans;
    }
};