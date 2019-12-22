#include <iostream>
#include <iterator>
#include <vector>
#include <algorithm>

#include <deque>

using namespace std;

struct Operation {
    char type = 0;
    int number = 0;
};

bool NeedBrackets(char last, char current) {
    return (last == '+' || last == '-') && (current == '*' || current == '/');
}

int main() {
    int num;
    cin >> num;

    int number_operations;
    cin >> number_operations;
    vector<Operation> operations(number_operations);  // (*)
    for (int i = 0; i < number_operations; ++i) {
        cin >> operations[i].type;
        cin >> operations[i].number;
    }

    deque<string> deq;
    deq.push_back(to_string(num));

    char symbol = '*';
    for (const auto& operation : operations) {
        // Если условия удовлетворены, обрамляем последовательность скобками
        if (NeedBrackets(symbol, operation.type)) {
            deq.push_front("(");
            deq.push_back(")");
        }
        deq.push_back(" ");
        deq.push_back(string(1, operation.type));
        deq.push_back(" ");
        deq.push_back(to_string(operation.number));

        symbol = operation.type;
    }

    for (const auto& w : deq) {
        cout << w;
    }

    return 0;
}