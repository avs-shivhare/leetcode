class Solution {
public:
    int countSymmetricIntegers(int low, int high) {
        int ans = 0;
        for(int i = low; i<=high; i++) {
            string temp = to_string(i);
            if(temp.size() & 1) continue;
            int sum1 = 0,sum2 = 0;
            int l = 0,r = temp.size()-1;
            while(l<r) {
                sum1 += (temp[l]-'0');
                sum2 += (temp[r]-'0');
                l++;
                r--;
            }
            if(sum1 == sum2) ans++;
        }
        return ans;
    }
};