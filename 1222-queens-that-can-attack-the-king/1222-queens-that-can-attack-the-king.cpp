class Solution {
public:
    // 1st approach
    //create a board that have 8 row and 8 col, assign 1 fr queens and 2 for king in board 
    // start peaking queen and find if they are attack or not
    // vector<vector<int>> queensAttacktheKing(vector<vector<int>>& queens, vector<int>& king) {
    //     vector<vector<int>> board(8,vector<int>(8,0));
    //     for(auto i: queens) {
    //         board[i[0]][i[1]] = 1;
    //     }
    //     board[king[0]][king[1]] = 2;
    //     set<pair<int,int>> st;
    //     vector<vector<int>> ans;
    //     for(auto x: queens) {
    //         int row = x[0];
    //         int col = x[1];
    //         cout<<row<<" "<<col<<endl;
    //         for(int i = row+1; i<8; i++) {
    //             if(board[i][col] == 2) {
    //                 st.insert({x[0],x[1]});
    //             }
    //             else if(board[i][col] == 1) break;
    //         }
    //         for(int i = row-1; i>=0; i--) {
    //             if(board[i][col] == 2) {
    //                 st.insert({x[0],x[1]});
    //             }
    //             else if(board[i][col] == 1) break;
    //         }
    //         for(int i = col+1; i<8; i++) {
    //             if(board[row][i] == 2) {
    //                 st.insert({x[0],x[1]});
    //             }
    //             else if(board[row][i] == 1) break;
    //         }
    //         for(int i = col-1; i>=0; i--) {
    //             if(board[row][i] == 2) {
    //                 st.insert({x[0],x[1]});
    //             }
    //             else if(board[row][i] == 1) break;
    //         }
    //         for(int i = row+1,j = col+1; i<8 && j<8 ; i++,j++ ) {
    //             if(board[i][j] == 2) {
    //                 st.insert({x[0],x[1]});
    //             }
    //             else if(board[i][j] == 1) {
    //                 break;
    //             }
    //         }
    //         for(int i = row-1,j = col-1; i>=0 && j>=0 ; i--,j-- ) {
    //             if(board[i][j] == 2) {
    //                 st.insert({x[0],x[1]});
    //             }
    //             else if(board[i][j] == 1) {
    //                 break;
    //             }
    //         }
    //         for(int i = row+1,j = col-1; i<8 && j>=0 ; i++,j-- ) {
    //             if(board[i][j] == 2) {
    //                 st.insert({x[0],x[1]});
    //             }
    //             else if(board[i][j] == 1) {
    //                 break;
    //             }
    //         }
    //         for(int i = row-1,j = col+1; i>=0 && j<8 ; i--,j++ ) {
    //             if(board[i][j] == 2) {
    //                 st.insert({x[0],x[1]});
    //             }
    //             else if(board[i][j] == 1) {
    //                 break;
    //             }
    //         }
    //     }
    //     for(auto i : st) {
    //         ans.push_back({i.first,i.second});
    //     }
    //     return ans;
    // }

    //2nd approach
    // take king cordinate and find which queen are attack 
    // add that in answer and return
    vector<vector<int>> queensAttacktheKing(vector<vector<int>>& queens, vector<int>& king) {
        set<pair<int,int>> st;
        vector<vector<int>> ans;
        for(auto i: queens) {
            st.insert({i[0],i[1]});
        }
        int row = king[0];
        int col = king[1];
        for(int i = row+1; i<8; i++) {
            if(st.find({i,col}) != st.end()) {
                ans.push_back({i,col});
                break;
            }
        }
        for(int i = row-1; i>=0; i--) {
            if(st.find({i,col}) != st.end()) {
                ans.push_back({i,col});
                break;
            }
        }
        for(int i = col+1; i<8; i++) {
            if(st.find({row,i}) != st.end()) {
                ans.push_back({row,i});
                break;
            }
        }
        for(int i = col-1; i>=0; i--) {
            if(st.find({row,i}) != st.end()) {
                ans.push_back({row,i});
                break;
            }
        }
        for(int i = row+1,j = col+1; i<8 && j<8 ; i++,j++ ) {
            if(st.find({i,j}) != st.end()) {
                ans.push_back({i,j});
                break;
            }
        }
        for(int i = row-1,j = col-1; i>=0 && j>=0 ; i--,j-- ) {
            if(st.find({i,j}) != st.end()) {
                ans.push_back({i,j});
                break;
            }
        }
        for(int i = row+1,j = col-1; i<8 && j>=0 ; i++,j-- ) {
            if(st.find({i,j}) != st.end()) {
                ans.push_back({i,j});
                break;
            }
        }
        for(int i = row-1,j = col+1; i>=0 && j<8 ; i--,j++ ) {
            if(st.find({i,j}) != st.end()) {
                ans.push_back({i,j});
                break;
            }
        }
        return ans;
    }
};