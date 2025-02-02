class Solution {
public:
    bool check(int mid,vector<int> &heights,int bricks,int ladders) {
        vector<int> diff;
        for(int i = 1; i<=mid; i++) {
            if(heights[i-1] < heights[i]) {
                diff.push_back(heights[i]-heights[i-1]);
            }
        }
        sort(diff.begin(),diff.end(),greater<int>());
        for(auto i: diff) {
            if(ladders > 0) ladders--;
            else if(bricks >= i) {
                bricks-= i;
            }
            else return false;
        }
        return true;
    }
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        int l = 0,r = heights.size()-1;
        int ans = 0;
        while(l<=r) {
            int mid = (l+r)>>1;
            if(check(mid,heights,bricks,ladders)) {
                ans = mid;
                l = mid+1;
            }
            else {
                r = mid-1;
            }
        }
        return ans;
    }
};