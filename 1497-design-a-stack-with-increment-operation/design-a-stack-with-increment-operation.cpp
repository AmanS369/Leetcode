class CustomStack {
public:
    vector<int> stack;
    int mx=0;
    int top=-1;

    CustomStack(int maxSize) {
        mx = maxSize;
        stack.resize(maxSize);

    }

    void push(int x) {
    
        if (top < (mx - 1) || top == -1) {
            top = top + 1;
            stack[top] = x;
        }
    }

    int pop() {
        if (top != -1) {
            
            return stack[top--];
        }
        return -1;
    }

    void increment(int k, int val) {
        for (int i = 0; i < min(k, top + 1); i++) {
            stack[i] += val;
        }
    }
};