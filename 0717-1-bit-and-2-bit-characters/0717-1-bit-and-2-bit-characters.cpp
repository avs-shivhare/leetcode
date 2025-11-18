class Solution {
public:
    bool isOneBitCharacter(vector<int>& bits) {
        int n = bits.size();
        if(n == 1) return bits[0] == 0;
        vector<int> temp;
        for(int i = 0; i<n; i++) {
            if(temp.empty()) {
                if(bits[i] == 1) temp.push_back(bits[i]);
                else if(i == n-1) return true;
            }
            else {
                temp.pop_back();
            }
        }
        return false;
    }
};