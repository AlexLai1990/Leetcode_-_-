/*
 Care about the corner case:
 0 point, 1 point, duplicate points, slope infinity, slop 0.
 It’s trivial to create a customer key.http://stackoverflow.com/questions/17016175/c-unordered-map-using-a-custom-class-type-as-the-key
 So we can use std::string to do that.
 */

int maxPoints(vector<Point> &points) {
    if (points.size() == 0)
        return 0;
    if (points.size() == 1)
        return 1;
    int max_ret = INT_MIN;
    Point curr;
    Point test;
    unordered_map<string, bool> m_points;
    for (int i = 0; i < points.size(); i++) {
        unordered_map<double, int> m_slopes;
        int count_x_axis = 0;
        int count_y_axis = 0;
        int duplicate_count = 1;
        double curr_slope;
        int max_curr = INT_MIN;
        curr = points[i];
        string coordinate;
        coordinate += to_string(curr.x);
        coordinate.append("-");
        coordinate += to_string(curr.y);
        if (m_points.find(coordinate) != m_points.end() )
            continue;
        m_points[coordinate] = true;
        for (int j = 0; j < points.size(); j++) {
            if (j == i)
                continue;
            test = points[j];
            if (test.y == curr.y && test.x == curr.x) {
                duplicate_count++;
                continue;
            }
            if (test.y == curr.y) {
                count_y_axis++;
                continue;
            }
            if (test.x == curr.x) {
                count_x_axis++;
                continue;
            }
            curr_slope = double(test.y - curr.y) / double(test.x - curr.x);
            if (m_slopes.find(curr_slope) == m_slopes.end() )
                m_slopes[curr_slope] = 1;
            else {
                m_slopes[curr_slope]++;
            }
            if (m_slopes[curr_slope] + duplicate_count > max_curr)
                max_curr = m_slopes[curr_slope] + duplicate_count;
        }
        max_curr = max(max_curr, max(count_y_axis, count_x_axis) + duplicate_count);
        if (max_ret < max_curr)
            max_ret = max_curr;
    }
    return max_ret;
}