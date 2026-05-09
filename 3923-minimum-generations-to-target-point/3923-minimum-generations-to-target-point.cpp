class Solution {
public:
    int minGenerations(vector<vector<int>>& points, vector<int>& target) {
        set<vector<int>> st(points.begin(),points.end());
        for(auto &i: points) {
            if(i[0] == target[0] && i[1] == target[1] && i[2] == target[2]) return 0;
        }
        int c = 0;
        while(true) {
            int cnt = 0;
            c++;
            int n = points.size();
            for(int i = 0; i<n; i++) {
                for(int j = i+1; j<n; j++) {
                    vector<int> temp = {(points[i][0]+points[j][0])/2,(points[i][1]+points[j][1])/2,(points[i][2]+points[j][2])/2};
                    if(st.find(temp) == st.end()) {
                        cnt++;
                        st.insert(temp);
                        points.push_back(temp);
                    }
                    if(temp[0] == target[0] && temp[1] == target[1] && temp[2] == target[2]) return c;
                }
            }
            if(cnt == 0) break;
        }
        return -1;
    }
};