class Solution {
public:
    int longestMountain(vector<int>& arr) {
        int n = arr.size();
        if(n < 3) return 0;
        int maxi = 0;
        for(int i =0; i<n; i++) {
            if(n-i < 3) break;
            if(arr[i] >= arr[i+1]) continue;
            int x = i;
            int cnt = 0;
            while(x<n-1 && arr[x] < arr[x+1]) {
                x++;
                cnt++;
            }
            if(x == n-1 || arr[x] == arr[x+1]) continue;
            while(x<n-1 && arr[x] > arr[x+1]) {
                x++;
                cnt++;
            }
            maxi = max(maxi,cnt+1);
        }
        return maxi;
    }
};