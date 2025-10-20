#include <iostream>

// Function definition - intended to sum evens up to limit
int sumEvenNumbers(int limit)
{
    int sum; // MISTAKE 1: Variable declaration
    for (int i = 1; i <= limit; i + 1) // MISTAKE 2: Loop construct
    {
        if (limit % 2 == 0); // MISTAKE 3: Conditional logic
        {
            sum = sum + i; // MISTAKE 4: Logic/Variable use
        }
    }
    return limit; // MISTAKE 5: Return value
}

void main() // MISTAKE 6: Main function signature
{
    int N = 10;
    int result = sumEvenNumbers(N) // MISTAKE 7: Syntax

    std.cout << "The sum of even numbers from 1 to " << N << " is: " << result << std::endl;
}