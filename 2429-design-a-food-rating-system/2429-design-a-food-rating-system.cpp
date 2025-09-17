struct compare {
    bool operator()(pair<int,string> &a,pair<int,string> &b) {
        if(a.first > b.first) return false;
        else if(a.first < b.first) return true;
        else if(a.second < b.second) return false;
        return true;
    }
};
class FoodRatings {
public:
    map<string,string> curr;
    map<string,int> mpp;
    map<string,priority_queue<pair<int,string>,vector<pair<int,string>>,compare>> rat;
    FoodRatings(vector<string>& f, vector<string>& c, vector<int>& ratt) {
        int n = f.size();
        for(int i = 0; i<n; i++) {
            mpp[f[i]] = ratt[i];
            curr[f[i]] = c[i];
            rat[c[i]].push({ratt[i],f[i]});
        }
    }
    
    void changeRating(string food, int newRating) {
        string x = curr[food];
        mpp[food] = newRating;
        curr[food] = x;
        rat[x].push({newRating,food});
    }
    
    string highestRated(string c) {
        while(!rat[c].empty() && rat[c].top().first != mpp[rat[c].top().second]) rat[c].pop();
        if(!rat[c].empty()) return rat[c].top().second;
        return "";
    }
};

/**
 * Your FoodRatings object will be instantiated and called as such:
 * FoodRatings* obj = new FoodRatings(foods, cuisines, ratings);
 * obj->changeRating(food,newRating);
 * string param_2 = obj->highestRated(cuisine);
 */