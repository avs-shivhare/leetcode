class Solution {
public:
    vector<int> minOperations(string boxes) {
        int n = boxes.size();
        vector<int> prefix(n,0),suffix(n,0);
        int sum = 0;
        int temp = 0;
        for(int i = 0; i<n; i++) {
            sum += temp;
            prefix[i] = sum;
            temp += boxes[i]-'0';
        }
        sum = 0,temp = 0;
        for(int i = n-1; i>=0; i--) {
            sum += temp;
            suffix[i] = sum;
            temp += boxes[i]-'0';
        }
        vector<int> ans(n,0);
        for(int i = 0; i<n; i++) {
            ans[i] = prefix[i]+suffix[i];
        }
        return ans;
    }
};