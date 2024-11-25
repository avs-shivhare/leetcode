class Solution {
public:
    int slidingPuzzle(vector<vector<int>>& board) {
        string temp = "";
        for(int i =0; i<2; i++) {
            for(int j =0; j<3; j++) {
                temp += to_string(board[i][j]);
            }
        }
        if(temp == "123450") return 0;
        queue<pair<string,pair<int,int>>> q;
        unordered_set<string> st;
        int row[4] = {1,-1,0,0};
        int col[4] = {0,0,1,-1};
        int ind = 0;
        for(int i =0; i<6; i++) {
            if(temp[i] == '0') {
                ind = i;
                break;
            }
        }
        q.push({temp,{ind,0}});
        st.insert(temp);
        while(!q.empty()) {
            int n = q.size();
            for(int i =0; i<n; i++) {
                auto x = q.front();
                q.pop();
                int r = x.second.first/3;
                int c = x.second.first%3;
                for(int p = 0; p<4; p++) {
                    int newrow= r+row[p];
                    int newcol = c+col[p];
                    if(newrow >=0 && newrow <2 && newcol >=0 && newcol <3) {
                        ind = newrow*3+newcol;
                        swap(x.first[x.second.first],x.first[ind]);
                        if(st.count(x.first) == 0) {
                            if(x.first == "123450") return x.second.second+1;
                            else {
                                q.push({x.first,{ind,x.second.second+1}});
                                st.insert(x.first);
                            }
                        }
                        swap(x.first[x.second.first],x.first[ind]);
                    }
                }
            }
        }
        return -1;
    }
};