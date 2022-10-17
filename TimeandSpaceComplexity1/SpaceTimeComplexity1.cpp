/*TIME COMPLEXITY
Big 0 (Asymptotic Time)
This is the language and metric used to describe the efficiency of algorithms
O(s) is electronic transfer and increases linearly
O() is physical delivery and is a constant
O(big O) describes the upper bound in time
Expected case for runtime => O(N logN)

SPACE COMPLEXITY
Space Complexity is a parallel concept to time complexity
An array of size 'n' will require O(n)
AP Formula = (N(N-1))/2
*/
#include <iostream>
#include <string>

class myStack {
private:
    float* bottom;
    float* top;
    int size;
public:
    myStack(int size = 20);
    void push(float val);
    int num_items() const;
    float pop();
    int full() const;
    int empty() const;
    void print() const;
    float topElement() const;
    ~myStack();
};

myStack::myStack(int N) {
    bottom = new float[N];
    top = bottom;
    size = N;
}
myStack::~myStack() {
    delete[] bottom;
}
int myStack::num_items() const {
    return (top - bottom);
}
void myStack::push(float val) {
    *top = val;
    top++;
}
float myStack::pop() {
    top --;
    return *top;
}
int myStack::full() const {
    return (num_items() >= size);
}
int myStack::empty() const {
    return (num_items() <= 0);
}
void myStack::print() const {
    std::cout << "Stack currently holds " << num_items() << " items: ";
    for (float* element = bottom; element < top; element++) {
        std::cout << " " << *element;
    }
    std::cout << "\n";
}
float myStack::topElement() const {
    return *(top - 1);
}

int main() {
    myStack S(4);
    S.print();
    std::cout << "\n";
    S.push(2.31);
    S.push(1.19);
    S.push(6.78);
    S.push(0.54);
    S.print();
    std::cout << "\n";
    if (!S.full()) S.push(6.7);         // this should do nothing, as
          // stack is already full.
    std::cout << "The top element in the stack is " << S.topElement() << std::endl;
    S.print();
    std::cout << "\n";
    std::cout << "Popped value is: " << S.pop() << "\n";
    S.print();
    std::cout << "\n";
    S.push(S.pop() + S.pop());
    std::cout << "Replace top two items with their sum: \n";
    S.print();
    std::cout << "\n";
    S.pop();
    S.pop();
    S.print();
    std::cout << "\n";
    if (!S.empty()) S.pop();          // this should also do nothing,
                // as stack is already empty.
    if (S.num_items() != 0)
    {
        std::cout << "Error: Stack is corrupt!\n";
    }
    // destructor for S automatically called
    getchar(); 

    return EXIT_SUCCESS;
}