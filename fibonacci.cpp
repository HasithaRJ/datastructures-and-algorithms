#include <iostream>
#include <vector>

using namespace std;

typedef unsigned int UInt;
constexpr UInt FiboNotCalculated = 4; //We will be using this to mark not calculated fibonacci numbers (further 4 is not a fibonacci number).

UInt fibTopDown(const UInt n, vector<UInt>& mem)
{
    if (mem[n] != FiboNotCalculated)
        return mem[n];

    mem[n] = fibTopDown(n - 1, mem) + fibTopDown(n - 2, mem);

    return mem[n];
}

UInt fib(const UInt n)
{
    if (n < 2)
        return n;

    vector<UInt> memCache(n + 1, FiboNotCalculated); // for memoization
    memCache[0] = 0U; //Adding the base case
    memCache[1] = 1U; //Adding the base case

    return fibTopDown(n, memCache);
}

void printFibos(const UInt n)
{
    for (UInt i = 0; i <= n; ++i)
    {
        cout << i << "th fibo => " << fib(i) << endl;
    }
}

int main()
{
    printFibos(30U); //Printing the fibos up to given number
    return 0;
}

