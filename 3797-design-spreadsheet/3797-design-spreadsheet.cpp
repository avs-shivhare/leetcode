class Spreadsheet {
public:
    unordered_map<string,int> mpp;
    Spreadsheet(int rows) {
        
    }
    
    void setCell(string cell, int value) {
        mpp[cell] = value;
    }
    
    void resetCell(string cell) {
        mpp[cell] = 0;
    }
    
    int getValue(string formula) {
        string s1 = "",s2 = "";
        for(int i = 1; i<formula.size(); i++) {
            if(formula[i] == '+') {
                s1 = formula.substr(1,i-1);
                s2 = formula.substr(i+1);
                int val1 = 0,val2 = 0;
                if('A' <= s1[0] && s1[0] <= 'Z') {
                    val1 = mpp[s1];
                }
                else val1 = stoi(s1);
                if('A' <= s2[0] && s2[0] <= 'Z') {
                    val2 = mpp[s2];
                }
                else val2 = stoi(s2);
                return val1+val2;
            }
        }
        return 0;
    }
};

/**
 * Your Spreadsheet object will be instantiated and called as such:
 * Spreadsheet* obj = new Spreadsheet(rows);
 * obj->setCell(cell,value);
 * obj->resetCell(cell);
 * int param_3 = obj->getValue(formula);
 */