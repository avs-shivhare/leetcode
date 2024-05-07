class Solution {
public:
    void merge(vector<int> &nums,int low,int mid,int high) {
        int l = low,r = mid+1;
        vector<int> temp;
        while(l<= mid && r <= high) {
            if(nums[l] <= nums[r]) {
                temp.push_back(nums[l++]);
            }
            else {
                temp.push_back(nums[r++]);
            }
        }
        while(l<= mid) {
            temp.push_back(nums[l++]);
        }
        while(r <= high) {
            temp.push_back(nums[r++]);
        }
        for(int i =low; i<= high; i++) {
            nums[i]= temp[i-low];
        }
        return;
    }
    int mergeSort(vector<int> &nums,int low,int high) {
        if(low >= high) {
            return 0;
        }
        int cnt = 0;
        int mid = (low+high)>>1;
        cnt += mergeSort(nums,low,mid);
        cnt += mergeSort(nums,mid+1,high);
        cnt += reverse(nums,low,mid,high);
        merge(nums,low,mid,high);
        return cnt;
    }
    int reverse(vector<int> &nums,int low,int mid,int high) {
        int cnt = 0;
        int r = mid+1;
        for(int i = low; i<= mid; i++) {
            while(r <= high && (long long)nums[i] > (long long)2*nums[r]) r++;
            cnt += (r-(mid+1));
        }
        return cnt;
    }
    int reversePairs(vector<int>& nums) {
        return mergeSort(nums,0,nums.size()-1);
    }
};