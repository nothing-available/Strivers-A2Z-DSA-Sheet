class Queue {
    stack<int> input, output;
public:

    void enqueue(int x) {
        input.push(x);
    }

    int dequeue() {
         if (output.empty())
      while (input.size())
        output.push(input.top()), input.pop();

    int ans = output.top();
    output.pop();
    return ans;
    }
};
