class Solution {
public:
    bool isValid(string word) {
        if(word.size() < 3) return false;
        bool v = false,c = false;
        for(auto i: word) {
            i = tolower(i);
            if('a' <= i && i <= 'z') {
                if(i == 'a' || i == 'o' || i == 'e' || i == 'i' || i == 'u') v = true;
                else c = true;
            }
            else if('0' <= i && i <= '9') {

            }
            else return false;
        }
        //cout<<c<<" "<<v<<endl;
        if(c && v) return true;
        return false;
    }
};