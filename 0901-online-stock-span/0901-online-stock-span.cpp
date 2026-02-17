class StockSpanner {
public:
    StockSpanner() {

    }
    // int count = 0;
    stack<int> st;
    vector<int> prices;
    int i=0;
    int next(int price) {
        prices.push_back(price);
        while (!st.empty() && prices[st.top()] <= price) {
            st.pop();
        }
        int prevIndex= st.empty() ?-1: st.top();
        int span=i-prevIndex;
        st.push(i);
        i++;
        return span;

    }
}
;

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */