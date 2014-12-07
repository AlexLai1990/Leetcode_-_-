class Solution {
public:
    int trap(int A[], int n) {
        if (A == NULL || n < 3)
            return 0;
        int water = 0;
        // pair (value, position)
        stack<pair<int,int> > m_stack;
        int height = 0;
        for (int i = 0; i < n; i++) {
            // each time the top element in the stack is the element of previous index of i
            while (!m_stack.empty()) {
                int bar = m_stack.top().first;
                int pos = m_stack.top().second;
                int width = i - pos - 1;
                water += (min(bar, A[i]) - height) * width;
                height = bar;
                if (A[i] < bar)
                    break;
                else
                    m_stack.pop();
            }
            // because it push here
            m_stack.push(make_pair(A[i],i));
        }
        return water;
    }
};

 // way1 use two arrays to store the left max and right max 
 /*
        if (n <= 2)
            return 0;
        int * max_left = new int[n];
        int * max_right = new int[n];
        int m_ret = 0;
        max_left[0] = -1;
        max_right[n-1] = -1;
        for (int i = 1; i < n; i++) {
            max_left[i] = max(max_left[i-1], A[i-1]); 
        }
        for (int i = n-2; i >= 0; i--) { 
            max_right[i] = max(max_right[i+1], A[i+1]);
        }
        int temp;
        for (int i = 0; i < n; i++) {
            temp = min(max_left[i], max_right[i]);
            m_ret += temp > A[i] ? temp - A[i] : 0; 
        }
        delete max_left;
        delete max_right;
        return m_ret;
*/