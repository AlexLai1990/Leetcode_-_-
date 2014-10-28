/*
Can make as many transactions as possible. 
Greedy thought: we need to add each increasing difference for each day and the day before that day.
*/

// Solution 1
 int maxProfit(vector<int> &prices) {
    int m_profit = 0;
    if (prices.size() < 2)
        return m_profit; 
    int diff_today = 0;
    for (int i = 1; i < prices.size(); i++) { 
        diff_today = prices[i] - prices[i - 1];
        if (diff_today > 0)
            m_profit += diff_today;
    }
    return m_profit;
}