class Solution {
public:
    vector<int> numOfBurgers(int tomato, int chees) {
        int small = 0,big = 0;
        if(tomato & 1) return {};
        while(tomato && chees) {
            if(tomato%4 == 0 && chees == tomato/4) {
                return {tomato/4,small};
            }
            else if(tomato >= 2) {
                small++;
                tomato -= 2;
                chees--;
            }
            else return {};
        } 
        if(!tomato && !chees) return {big,small};
        return {};
    }
};