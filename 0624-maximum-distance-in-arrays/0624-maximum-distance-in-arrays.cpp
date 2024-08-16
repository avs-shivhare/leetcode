class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        int maxi1 = -1e9,maxi2 = -1e9;
        int mini1 = 1e9,mini2 = 1e9;
        int n = arrays.size();
        int ind1 =-1,ind2 =-1;
        for(int i =0; i<n ; i++) {
            int currmini = arrays[i][0];
            int currmaxi = arrays[i][arrays[i].size()-1];
            if(currmini <= mini1) {
                mini2 = mini1;
                mini1 = currmini;
                ind1 = i;
            }
            else if(currmini > mini1 && currmini <= mini2) {
                mini2 = currmini;
            }

            if(currmaxi >= maxi1) {
                maxi2 = maxi1;
                maxi1 = currmaxi;
                ind2 =i;
            }
            else if(currmaxi < maxi1 && currmaxi >= maxi2) {
                maxi2 = currmaxi;
            }
        }
        if(ind1 != ind2) {
            return maxi1-mini1;
        }
        return max(maxi1-mini2,maxi2-mini1);
    }
};