class Solution {
public:
    vector<vector<int>> filterOccupiedIntervals(vector<vector<int>>& oc, int fr, int fre) {
        sort(oc.begin(),oc.end());
        vector<vector<int>> temp;
        for(auto &i: oc) {
            if(temp.empty() || temp.back()[1]+1 < i[0]) temp.push_back(i);
            else temp.back()[1] = max(temp.back()[1],i[1]);
            if(fr <= temp.back()[0] && temp.back()[1] <= fre) temp.pop_back();
            else if(fr <= temp.back()[0] && temp.back()[0] <= fre) temp.back()[0] = fre+1;
            else if(fr <= temp.back()[1] && temp.back()[1] <= fre) temp.back()[1] = fr-1;
            else if(temp.back()[0] <= fr && fre <= temp.back()[1]) {
                auto x = temp.back();
                temp.back()[1] = fr-1;
                temp.push_back({fre+1,x.back()});
            }
        }
        return temp;
    }
};