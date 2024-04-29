class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n = nums.size();
        int cnt = 0;
        for(int i =0; i<n; i++) {
            int diff = 0;
            int k = 0;
            for(int j = i; j<n-1; j++) {
                if(k == 0 ) {
                    k++;
                    diff = nums[j+1]-nums[j];
                }
                if(diff == nums[j+1]-nums[j]) {
                    //cout<<"diff "<<diff<<" "<<nums[j+1]-nums[j]<<endl;
                    if(j+1-i+1 >= 3) {
                        cnt++;
                        //cout<<cnt<<" "<<i<<" "<<j+1<<endl;
                    }
                }
                else break;
            }
        }
        return cnt;
    }
};