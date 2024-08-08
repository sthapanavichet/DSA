#include <iostream>
#include <limits>

int modulo(int n, int d) {
    int factor = n / d;         // 2
    return n - (factor * d);    // 2
}

// Let n represent the value for the modulo operation
// Let T(n) represent number of operations needed to find the result of the modulo operation
// T(n) = 2 + 2 = 4
// so, T(n) is O(1)
// This means that this algorithm is in constant time.


void fibonacci(int n) {
    int previous = 0, previous2 = 1; // 2
    std::cout << previous; // 1
    for(int i = 0; i < n; i++) { // 1 + n + n
        int current = previous + previous2; // 2*n
        previous2 = previous; // 1*n
        previous = current; // 1*n
        std::cout << ',' << current;
    }
}

// Let n represent the number for the fibonacci series
// Let T(n) represent number of operations needed to find the number in the fibonacci series
// T(n) = 2 + 1 + 2n + 2n + 1n + 1n
// T(n) = 6n + 3
// From this we can see that the number of operations increases linearly.
// so, T(n) is O(n)
// This means that this algorithm is in linear time.


int main() {
    char choice;
    std::cout << "Welcome! Enter M for Modulo operator or F for Fibonacci series: ";
    std::cin >> choice;
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    if(choice == 'M' or choice == 'm') {
        int number, divisor;
        std::cout << "Enter a number for the modulo operation: ";
        std::cin >> number;
        std::cin.clear();

        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Enter a divisor for the modulo operation: ";
        std::cin >> divisor;
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        std::cout << "The result of the modulo operation is: " << modulo(number, divisor) << std::endl;
    }
    else if(choice == 'F' or choice == 'f') {
        int number;
        std::cout << "Enter a number for the fibonacci series: ";
        std::cin >> number;
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        fibonacci(number);
    }
    else {
        std::cout << "Invalid choice." << std::endl;
    }
    return 0;
}



