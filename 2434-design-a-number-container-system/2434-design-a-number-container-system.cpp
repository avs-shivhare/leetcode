class NumberContainers {
public:
    unordered_map<int,set<int>> mpp;
    unordered_map<int,int> ind;
    NumberContainers() {
        
    }
    
    void change(int index, int number) {
        if(ind.count(index)) {
            mpp[ind[index]].erase(index);
            if(mpp[ind[index]].size() == 0) mpp.erase(ind[index]);
        }
        mpp[number].insert(index);
        ind[index] = number;
    }
    
    int find(int number) {
        if(mpp.count(number)) {
            return *(mpp[number].begin());
        }
        return -1;
    }
};

/**
 * Your NumberContainers object will be instantiated and called as such:
 * NumberContainers* obj = new NumberContainers();
 * obj->change(index,number);
 * int param_2 = obj->find(number);
 */