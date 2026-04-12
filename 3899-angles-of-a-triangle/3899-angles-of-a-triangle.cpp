class Solution {
public:
    vector<double> internalAngles(vector<int>& sides) {
        sort(sides.begin(),sides.end());
        if(sides[0]+sides[1] <= sides[2]) return {};
        vector<double> ans(3);
        ans[0] = acos((sides[1]*sides[1]+sides[2]*sides[2]-sides[0]*sides[0])/(2.0*sides[1]*sides[2]));
        ans[1] = acos((sides[0]*sides[0]+sides[2]*sides[2]-sides[1]*sides[1])/(2.0*sides[0]*sides[2]));
        ans[2] = acos((sides[1]*sides[1]+sides[0]*sides[0]-sides[2]*sides[2])/(2.0*sides[1]*sides[0]));
        ans[0] = ans[0]*180/M_PI;
        ans[1] = ans[1]*180/M_PI;
        ans[2] = ans[2]*180/M_PI;
        sort(ans.begin(),ans.end());
        return ans;
    }
};