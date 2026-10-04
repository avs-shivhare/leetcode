class Solution {
public:
    int find(int n,int last) {
        int ans = 10;
        if(last >= n) ans = min({ans,last-n,last+(10-n),10-last+n});
        else ans = min({ans,n-last,10-last+n,last+(10-n)});
        //cout<<n<<" "<<last<<" "<<ans<<endl;
        return ans;
    }
    int minRotations(string s) {
        int last = 0;
        int ans = 0;
        for(auto &i: s) {
            ans += find(i-'0',last);
            last = i-'0';
        }
        return ans;
    }
};