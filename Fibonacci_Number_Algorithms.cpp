#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

long long SlowFibonacciNumbers(int n)
{
    if (n <= 1)
    {
        return n;
    }

    else
    {
        return SlowFibonacciNumbers(n - 1) + SlowFibonacciNumbers(n - 2);
    }

}

long long FastFibonacciNumbers(int n)
{
    vector<long long> numbers;

    numbers.push_back(0);
    numbers.push_back(1);

    for (int i = 2; i < n + 1; i++)
    {
        numbers.push_back(numbers[i - 2] + numbers[i - 1]);
    }

    return numbers[n];

}

long long FastSpaceEfficientFibonacciNumbers(int n)
{
    if (n <= 1)
    {
        return n;
    }

    long long a = 0, b = 1;

    for (int i = 2; i <= n; ++i) 
    {
        long long c = a + b;
        a = b;
        b = c;
    }

    return b;
}



int main() {
    int n;
    std::cin >> n;

    std::cout << "Slow Algorithm: " << SlowFibonacciNumbers(n) << "\n";
    std::cout << "Fast Algorithm: " << FastFibonacciNumbers(n) << "\n";
    std::cout << "Faster & Space Efficient Algorithm: " << FastSpaceEfficientFibonacciNumbers(n) << "\n";
    return 0;
}
