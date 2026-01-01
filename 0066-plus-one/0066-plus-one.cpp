class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int c = 1;
        reverse(digits.begin(),digits.end());
        int n = digits.size();
        for(int i = 0; i<n; i++) {
            c += digits[i];
            digits[i] = c%10;
            c /= 10;
        }
        if(c) digits.push_back(c);
        reverse(digits.begin(),digits.end());
        return digits;
    }
};