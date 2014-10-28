/*
Greedy thought: Total_left > 0, means can go through all stations.
We also need a temp_left to get the start_station.

*/
int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
    int temp_left = 0;
    int total_left = 0;
    int prev_station = -1;
    for (int i = 0; i < gas.size(); i++) {
        // temp_left means that how many left when passing through curr station
        temp_left += gas[i] - cost[i];
        total_left += temp_left;
        if (temp_left < 0) {
            // start a new round
            prev_station = i;
            temp_left = 0;
        }
    }
    
    return total_left >= 0 ? prev_station + 1 : -1;
}