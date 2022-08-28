#include <iostream>
#include "include/seqStack.h"

using namespace std;
int main() {
    SeqStack<int> S1 = (10);
    S1.push(5);
    S1.push(3);
    cout << S1.top() << endl;
    S1.pop();
    cout << S1.top() << endl;
    return 0;
}