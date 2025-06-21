class Solution {
public:
    long long maxArea(vector<vector<int>>& coords) {
        long long ans = 0;
        map<int,multiset<int>> x,y;
        for(auto i: coords) {
            x[i[0]].insert(i[1]);
            y[i[1]].insert(i[0]);
        }
        for(auto i: x) {
            if(i.second.size() > 1) {
                long long base = *prev(i.second.end())-*i.second.begin();
                long long height1 = x.begin()->first;
                long long height2 = prev(x.end())->first;
                height1 = abs(height1-i.first);
                height2 = abs(height2-i.first);
                ans = max({ans,base*height1,base*height2});
            }
        }
        for(auto i: y) {
            if(i.second.size() > 1) {
                long long base = *prev(i.second.end())-*i.second.begin();
                long long height1 = y.begin()->first;
                long long height2 = prev(y.end())->first;
                height1 = abs(height1-i.first);
                height2 = abs(height2-i.first);
                ans = max({ans,base*height1,base*height2});
            }
        }
        if(ans > 0) return ans;
        return -1;
    }
};