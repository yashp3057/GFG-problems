#include <queue>
using namespace std;

class myStack {
    queue<int> q;

public:
    // Push element
    void push(int x) {
        q.push(x);

        int n = q.size();

        // Move first (n-1) elements to the back
        for (int i = 0; i < n - 1; i++) {
            q.push(q.front());
            q.pop();
        }
    }

    // Pop element
    void pop() {
        if (!q.empty())
            q.pop();
    }

    // Return top element
    int top() {
        if (q.empty())
            return -1;

        return q.front();
    }

    // Return size
    int size() {
        return q.size();
    }
};