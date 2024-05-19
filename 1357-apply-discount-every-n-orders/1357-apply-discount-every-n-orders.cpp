class Cashier {
public:
    unordered_map<int,int> mpp;
    int n = 0;
    int bill = 0;
    int dis = 0;
    Cashier(int y, int discount, vector<int>& products, vector<int>& prices) {
        n = y;
        dis= discount;
        int x = products.size();
        for(int i =0; i<x; i++) {
            mpp[products[i]] = prices[i];
        }
    }
    
    double getBill(vector<int> product, vector<int> amount) {
        double total = 0.0;
        int x = product.size();
        for(int i =0; i<x; i++) {
            total += mpp[product[i]]* amount[i];
        }
        if(bill+1 == n) {
            total *= (((double)100-dis)/(double)100);
        }
        bill = (bill+1)%n;
        return total;
    }
};

/**
 * Your Cashier object will be instantiated and called as such:
 * Cashier* obj = new Cashier(n, discount, products, prices);
 * double param_1 = obj->getBill(product,amount);
 */