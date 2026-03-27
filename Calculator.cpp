#include <iostream> 
using namespace std; 

int main() {
    double a;
    double b;

    cout << "Pick your first number" << endl;
    cin >> a;

    cout << "Pick your second number" << endl;
    cin >> b; 

    cout << "Addition: " << a + b << endl;
    cout << "Subtraction: " << a - b << endl; 
    cout << "Multiplication: " << a * b << endl; 

    if (b != 0)
        cout << "Division (a/b): " << a / b << endl; 
    else 
        cout << "Error: cannot divide by zero" << endl;

    return 0;
}

