/*
Scan twice:  one from left and one from right. 
Using a array to store the max_profit of current day. 
Scan 1st to get each day’s profit.
Scan 2nd to get the possible second transaction's profit by purchasing stock on that day
*/

int maxProfit(vector<int> &prices) {
    if (prices.size() < 2)
        return 0;
    // from this day to buy, how many profits i can earn
    int num_days = prices.size();
    vector<int> m_profits(num_days, 0);
    int max_profit = 0;
    int temp_profit = 0;
    int min_price = prices[0];
    int max_price;
    for (int i = 1; i < num_days; i++) {
        temp_profit = prices[i] - min_price;
        if (temp_profit > max_profit) {
            max_profit = temp_profit;
            m_profits[i] = max_profit;
        }
        else 
            m_profits[i] = m_profits[i - 1];
        if (min_price > prices[i])
            min_price = prices[i];
    } 
    max_price = prices[num_days - 1];
    for (int i = num_days - 2; i >= 0; i--) {
        temp_profit = max_price - prices[i] + m_profits[i];
        if (temp_profit > max_profit)
            max_profit = temp_profit;
        if (max_price < prices[i])
            max_price = prices[i];
    }
    
    return max_profit;
}