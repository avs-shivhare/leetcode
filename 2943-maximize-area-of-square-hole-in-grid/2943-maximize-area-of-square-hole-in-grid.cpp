class Solution {
public:
    int maximizeSquareHoleArea(int n, int m, vector<int>& hBars, vector<int>& vBars) {
        sort(hBars.begin(),hBars.end());
        sort(vBars.begin(),vBars.end());
        int maxi = 1,last = 1,cnt = 1;
        for(auto &i: hBars) {
            if(last+1 == i) cnt++;
            else {
                cnt = 2;
            }
            last = i;
            maxi = max(maxi,cnt);
        }
        int maxi2 = 1;
        last = 1,cnt = 1;
        for(auto &i: vBars) {
            if(last+1 == i) cnt++;
            else {
                cnt = 2;
            }
            last = i;
            maxi2 = max(maxi2,cnt);
        }
        //cout<<maxi<<" "<<maxi2<<endl;
        int mini = min(maxi,maxi2);
        return mini*mini;
    }
};