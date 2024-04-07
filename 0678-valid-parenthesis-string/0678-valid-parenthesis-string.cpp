class Solution {
public:
    bool checkValidString(string s) {
        int leftmax = 0,leftmin =0;
        for(char i: s) {
            if(i == '(') {
                leftmax++;
                leftmin++;
            }
            else if(i == ')') {
                leftmax--;
                leftmin--;
            }
            else {
                leftmin--;
                leftmax++;
            }
            if(leftmax<0) return false;
            if(leftmin < 0) leftmin =0;
        } 
        return leftmin == 0;
    }
};