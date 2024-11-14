class Solution {
public:
    int find(vector<int> &q,int &n,int &mid) {
        int ans = 0;
        for(auto i: q) {
            ans += i/mid+(i%mid == 0? 0: 1);
        }
        return ans;
    }
    // int check(int &n,vector<int> &q) {
    //     int low = 1,high = *max_element(q.begin(),q.end());
    //     int ans = high;
    //     while(low <= high) {
    //         int mid = (low+high)>>1;
    //         if(find(q,n,mid)) {
    //             ans = mid;
    //             low = mid+1;
    //         }
    //         else high = mid-1;
    //     }
    //     return ans;
    // }
    int minimizedMaximum(int n, vector<int>& q) {
        int ans = 0;
        int low = 1,high = *max_element(q.begin(),q.end());
        ans = high;
        while(low <= high) {
            int mid = (low+high)>>1;
            int temp = find(q,n,mid);
            //if(temp == n) ans = mid;
            if(temp > n) {
                low = mid+1;
            }
            else {
                ans = mid;
                high = mid-1;
            }
        }
        return ans;
    }
};