class Solution {
public:
    //Brute force solution
    // int trap(vector<int>& height) {
    //     int n = height.size();
    //     vector<int> left(n,0),right(n,0);
    //     left[0] = height[0];
    //     right[n-1] =height[n-1];
    //     for(int i =1;i<n; i++) {
    //         left[i] = max(height[i],left[i-1]);
    //     }
    //     for(int i =n-2; i>=0; i--) {
    //         right[i] = max(height[i],right[i+1]);
    //     }
    //     int ans =0;
    //     for(int i =0; i<n; i++) {
    //         if(min(left[i],right[i])-height[i] > 0) ans += (min(left[i],right[i])-height[i]);
    //     }
    //     return ans;
    // }

    //optimal solution
    int trap(vector<int>& height) {
        int n = height.size();
        int ans =0,l =0,r = n-1;
        int left =0,right =0;
        while(l<= r) {
            if(height[l] <= height[r]) {
                if(height[l] > left) left = height[l];
                else ans += (left-height[l]);
                l++;
            }
            else {
                if(height[r] > right) right = height[r];
                else ans += (right-height[r]);
                r--;
            }
        }
        return ans;
    }
};