class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
        vector<int> ans;
        int n = code.size();
        for(int i =0; i<n; i++) {
            int cnt = 0;
            int sum = 0;
            bool flag = true;
            int j = (i+1)%n;
            if(k < 0) {
                flag = false;
                j = i-1;
                if(j == -1) j = n-1;
            }
            if(k == 0) {
                ans.push_back(sum);
                continue;
            }
            while(cnt++ < abs(k)) {
                //cout<<j<<endl;
                sum += code[j];
                if(flag) {
                    j++;
                    j %= n;
                } 
                else {
                    j--;
                    if(j == -1) j = n-1;
                }
            }
            ans.push_back(sum);
        }
        return ans;
    }
};