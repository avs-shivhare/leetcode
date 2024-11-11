class Solution {
public:
    bool prime[1001];
    vector<int> temp;
    void find() {
        memset(prime,true,sizeof(prime));
        prime[0] = false;
        prime[1] = false;
        for(int i =2; i*i<=1000; i++) {
            if(prime[i]) {
                for(int j =i*i; j<=1000; j+= i) {
                    prime[j] = false;
                }
            }
        }
        for(int i= 2; i<=1000; i++) {
            if(prime[i]) temp.push_back(i);
        }
    }
    bool primeSubOperation(vector<int>& nums) {
        find();
        int n = nums.size();
        for(int i = n-2; i>=0; i--) {
            if(nums[i] >= nums[i+1]) {
                int ind = lower_bound(temp.begin(),temp.end(),nums[i]-nums[i+1]+1)-temp.begin();
                //cout<<nums[i]-nums[i+1]+1<<endl;
                if(ind == temp.size() || nums[i] <= temp[ind]) {
                    return false;
                }
                nums[i] -= temp[ind];
                if(nums[i] >= nums[i+1]) return false;
            }
        }
        return true;
    }
};