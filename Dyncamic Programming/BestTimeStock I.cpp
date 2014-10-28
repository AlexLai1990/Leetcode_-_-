/*
Find the min_price and update the profit of each day to get max profit
*/

int maxProfit(vector<int> &prices) {
    int m_profit = 0;
    if (prices.size() < 2)
        return m_profit;
    int min_price = prices[0];
    int temp_profit = 0;
    for (int i = 1; i < prices.size(); i++) {
        temp_profit = prices[i] - min_price; 
        if (temp_profit > m_profit)
            m_profit = temp_profit;
            
        if (temp_profit <= 0) {
            min_price = prices[i];
        }
    }
    return m_profit;
}