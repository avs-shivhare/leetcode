class Solution {
public:
    unordered_set<string> ans;
    string temp = "";
    void find(int i,string &tiles) {
        if(i == tiles.size()) {
            ans.insert(temp);
            return;
        }
        temp.push_back(tiles[i]);
        find(i+1,tiles);
        temp.pop_back();
        find(i+1,tiles);
    }
    int numTilePossibilities(string tiles) {
        find(0,tiles);
        unordered_set<string> x;
        for(auto i: ans) {
            sort(i.begin(),i.end());
            do{
                x.insert(i);
            }while(next_permutation(i.begin(),i.end()));
        }
        return x.size()-1;
    }
};