class Solution {
public:
    int check(vector<int> &arr,int mid) {
        int placeBall = 1;
        int prev = 0;
        for(int i =1; i<arr.size(); i++) {
            if(abs(arr[i]-arr[prev]) >= mid) {
                placeBall++;
                prev = i;
            }
        }
        return placeBall;
    }
    int maxDistance(vector<int>& position, int m) {
        sort(position.begin(),position.end());
        int n = position.size();
        int low = 0;
        int high = position[n-1];
        int ans = 0;
        while(low <= high) {
            int mid = low +(high-low)/2;
            if(check(position,mid) >= m) {
                ans = mid;
                low = mid+1;
            }
            else high = mid-1;
        }
        return ans;
    }
};