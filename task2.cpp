#include <iostream>

using namespace std;

int main() {
    double num1, num2;
    char operation;

    cout << "Enter first number: ";
    cin >> num1;

    cout << "Enter second number: ";
    cin >> num2;

    cout << "Choose operation (+, -, *, /): ";
    cin >> operation;

    double result;

    switch(operation) {
        case '+':
            result = num1 + num2;
            break;
        case '-':
            result = num1 - num2;
            break;
        case '*':
            result = num1 * num2;
            break;
        case '/':
            if (num2 == 0) {
                cout << "Error! Division by zero is not allowed.";
                return 1;
            }
            result = num1 / num2;
            break;
        default:
            cout << "Invalid operation!";
            return 1;
    }

    cout << "Result: " << result << endl;

    return 0;
}
