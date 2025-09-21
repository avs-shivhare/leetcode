class MovieRentingSystem {
public:
    map<int,set<pair<int,int>>> unrent;
    set<vector<int>> rented;
    map<int,map<int,int>> mpp;
    MovieRentingSystem(int n, vector<vector<int>>& entries) {
        for(auto &i: entries) {
            unrent[i[1]].insert({i[2],i[0]});
            mpp[i[0]][i[1]] = i[2];
        }
    }
    
    vector<int> search(int movie) {
        vector<int> ans;
        for(auto &i: unrent[movie]) {
            if(ans.size() < 5) ans.push_back(i.second);
            else break;
        }
        return ans;
    }
    
    void rent(int shop, int movie) {
        int p = mpp[shop][movie];
        unrent[movie].erase({p,shop});
        rented.insert({p,shop,movie});
    }
    
    void drop(int shop, int movie) {
        int p = mpp[shop][movie];
        rented.erase({p,shop,movie});
        unrent[movie].insert({p,shop});
    }
    
    vector<vector<int>> report() {
        vector<vector<int>> ans;
        for(auto &i: rented) {
            if(ans.size() < 5) {
                ans.push_back({i[1],i[2]});
            }
            else break;
        }
        return ans;
    }
};

/**
 * Your MovieRentingSystem object will be instantiated and called as such:
 * MovieRentingSystem* obj = new MovieRentingSystem(n, entries);
 * vector<int> param_1 = obj->search(movie);
 * obj->rent(shop,movie);
 * obj->drop(shop,movie);
 * vector<vector<int>> param_4 = obj->report();
 */