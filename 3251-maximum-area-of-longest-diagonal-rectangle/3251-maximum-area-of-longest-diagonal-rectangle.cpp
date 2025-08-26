class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
        double dig = 0;
        int ans = 0;
        for(auto i: dimensions) {
            double sq = sqrt((double)i[0]*i[0]+i[1]*i[1]);
            //cout<<sq<<" "<<i[0]*i[1]<<endl;
            if(sq > dig) {
                dig = sq;
                ans = i[0]*i[1];
            }
            else if(fabs(sq-dig) < 1e-6) {
                ans = max(ans,i[0]*i[1]);
                //cout<<"done"<<endl;
            }
        } 
        return ans;
    }
};