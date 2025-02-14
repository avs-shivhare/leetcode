class ProductOfNumbers {
public:
    vector<long long> arr;
    vector<long long> prefix;
    bool update = false;
    ProductOfNumbers() {
        
    }
    
    void add(int num) {
        update = false;
        arr.push_back(num);
        prefix.push_back(num);
    }
    
    int getProduct(int k) {
        if(update) {
            int n = prefix.size();
            return prefix[n-k];
        }
        update = true;
        int n = arr.size();
        prefix[n-1] = arr[n-1];
        for(int i = n-2; i>=0; i--) {
            prefix[i] = prefix[i+1]*arr[i];
        }
        return prefix[n-k];
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */