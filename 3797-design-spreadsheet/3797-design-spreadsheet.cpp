class Spreadsheet {
public:
    unordered_map<int,int> arr[26];
    Spreadsheet(int rows) {
        
    }
    
    void setCell(string cell, int value) {
        int r = cell[0]-'A';
        int c = stoi(cell.substr(1));
        arr[r][c] = value;
    }
    
    void resetCell(string cell) {
        int r = cell[0]-'A';
        int c = stoi(cell.substr(1));
        arr[r][c] = 0;
    }
    
    int getValue(string formula) {
        stringstream s(formula.substr(1));
        string temp = "";
        int sum = 0;
        while(getline(s,temp,'+')) {
            if('0' <= temp[0] && temp[0] <= '9') {
                sum += stoi(temp);
            }
            else {
                int r = temp[0]-'A';
                int c = stoi(temp.substr(1));
                sum += arr[r][c];
            }
        }
        return sum;
    }
};

/**
 * Your Spreadsheet object will be instantiated and called as such:
 * Spreadsheet* obj = new Spreadsheet(rows);
 * obj->setCell(cell,value);
 * obj->resetCell(cell);
 * int param_3 = obj->getValue(formula);
 */