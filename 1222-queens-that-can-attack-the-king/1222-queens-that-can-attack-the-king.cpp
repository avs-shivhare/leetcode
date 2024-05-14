class Solution {
public:
    vector<vector<int>> queensAttacktheKing(vector<vector<int>>& queens, vector<int>& king) {
        vector<vector<int>> board(8,vector<int>(8,0));
        for(auto i: queens) {
            board[i[0]][i[1]] = 1;
        }
        board[king[0]][king[1]] = 2;
        set<pair<int,int>> st;
        vector<vector<int>> ans;
        for(auto x: queens) {
            int row = x[0];
            int col = x[1];
            cout<<row<<" "<<col<<endl;
            for(int i = row+1; i<8; i++) {
                if(board[i][col] == 2) {
                    st.insert({x[0],x[1]});
                }
                else if(board[i][col] == 1) break;
            }
            for(int i = row-1; i>=0; i--) {
                if(board[i][col] == 2) {
                    st.insert({x[0],x[1]});
                }
                else if(board[i][col] == 1) break;
            }
            for(int i = col+1; i<8; i++) {
                if(board[row][i] == 2) {
                    st.insert({x[0],x[1]});
                }
                else if(board[row][i] == 1) break;
            }
            for(int i = col-1; i>=0; i--) {
                if(board[row][i] == 2) {
                    st.insert({x[0],x[1]});
                }
                else if(board[row][i] == 1) break;
            }
            for(int i = row+1,j = col+1; i<8 && j<8 ; i++,j++ ) {
                if(board[i][j] == 2) {
                    st.insert({x[0],x[1]});
                }
                else if(board[i][j] == 1) {
                    break;
                }
            }
            for(int i = row-1,j = col-1; i>=0 && j>=0 ; i--,j-- ) {
                if(board[i][j] == 2) {
                    st.insert({x[0],x[1]});
                }
                else if(board[i][j] == 1) {
                    break;
                }
            }
            for(int i = row+1,j = col-1; i<8 && j>=0 ; i++,j-- ) {
                if(board[i][j] == 2) {
                    st.insert({x[0],x[1]});
                }
                else if(board[i][j] == 1) {
                    break;
                }
            }
            for(int i = row-1,j = col+1; i>=0 && j<8 ; i--,j++ ) {
                if(board[i][j] == 2) {
                    st.insert({x[0],x[1]});
                }
                else if(board[i][j] == 1) {
                    break;
                }
            }
        }
        for(auto i : st) {
            ans.push_back({i.first,i.second});
        }
        return ans;
    }
};