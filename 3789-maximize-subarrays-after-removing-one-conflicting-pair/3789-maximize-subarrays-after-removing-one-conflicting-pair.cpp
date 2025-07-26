class Solution {
public:
    class compare {
        public:
        bool operator()(vector<int> &a,vector<int> &b) {
            if(a[1] < b[1]) return true;
            else if(a[1] > b[1]) return false;
            else if(a[0] < b[0]) return true;
            return false;
        }
    };
    long long maxSubarrays(int n, vector<vector<int>>& con) {
        for(auto &i: con) {
            if(i[1] < i[0]) {
                swap(i[1],i[0]);
            }
        }
        sort(con.begin(),con.end(),compare());
        int m = con.size();
        long long first = 0,second = 0;
        long long maxi = 0,curr = 0;
        long long ans = 1ll*(n)*(n+1)/2;
        long long temp = 0;
        for(int i = 0; i<m; i++) {
            long long start = con[i][0];
            long long base = n-con[i][1]+1;
            if(i<m-1) base = con[i+1][1]-con[i][1];
            if(start > first) {
                second = first;
                first = start;
                curr = 0;
            }
            else if(second < start) second = start;
            curr += (first-second)*base;
            temp += first*base;
            maxi = max(maxi,curr);
        }
        return ans-temp+maxi;
    }
};