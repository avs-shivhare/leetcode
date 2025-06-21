class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int n = nums.size();
        vector<int> odd,even;
        for(int i = 0; i<n; i++) {
            if(nums[i] & 1) odd.push_back(i);
            else even.push_back(i);
        }
        int cnt = 0;
        int ans = 0;
        if(odd.size() > even.size()) {
            swap(odd,even);
        }
        else if(odd.size() == even.size()) {
            if(odd[0] == 0) swap(even,odd);
        }
        int i = 0,j = 0;
        int x = 0;
        while(i<even.size() || j<odd.size()) {
            if(i < even.size()) {
                if(even[i] > x) {
                    ans += even[i]-x;
                    cnt++;
                }
                i++;
                x++;
            }
            else if(j != odd.size()) return -1;
            if(j < odd.size()) {
                if(odd[j] > x) {
                    ans += odd[j]-x;
                    cnt++;
                }
                j++;
                x++;
            }
            else if(i != even.size()) return -1;
            //cnt++;
        }
        int ans2 = 0;
        if(odd.size() == even.size()) {
            swap(odd,even);
            i = 0,j = 0;
            x = 0;
            while(i<even.size() || j<odd.size()) {
                if(i < even.size()) {
                    if(even[i] > x) {
                        ans2 += even[i]-x;
                        cnt++;
                    }
                    i++;
                    x++;
                }
                else if(j != odd.size()) return -1;
                if(j < odd.size()) {
                    if(odd[j] > x) {
                        ans2 += odd[j]-x;
                        cnt++;
                    }
                    j++;
                    x++;
                }
                else if(i != even.size()) return -1;
                //cnt++;
            }
            return min(ans,ans2);
        }
        return ans;
    }
};