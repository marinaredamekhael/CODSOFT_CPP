#include <iostream>
using namespace std;

int main()
{
    // Variables to store user input
    double num1, num2, result;
    char operation;
    int choice;

    while (true)
    {
        cout << "Press 1 to continue or -1 to exit: ";
        cin >> choice;

        if (choice == -1)
        {
            break; // Exit the loop and terminate the program
        }

        // Input two numbers
        cout << "Enter the first number: ";
        cin >> num1;
        cout << "Enter the second number: ";
        cin >> num2;

        // Input the operation
        cout << "Enter the operation (+, -, *, /): ";
        cin >> operation;

        // Perform the arithmetic based on the operation
        switch (operation)
        {
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
            if (num2 == 0)
            {
                cout << "Error: Division by zero!" << endl;
                continue; // skip to the next iteration of the loop
            }
            result = num1 / num2;
            break;
        default:
            cout << "Error: Invalid operation!" << endl;
            continue; // skip to the next iteration of the loop
        }

        // Display the result
        cout << num1 << " " << operation << " " << num2 << " = " << result << endl;
    }

    cout << "Thank you for using the calculator. Goodbye!" << endl;

    return 0;
}
