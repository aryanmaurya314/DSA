#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

// Sieve of Eratosthenes
vector<bool> sieveOfEratosthenes(int num)
{
    vector<bool> isPrime(num + 1, true);
    isPrime[0] = isPrime[1] = false;

    for (int i = 2; i * i <= num; i++)
    {
        if (isPrime[i])
        {
            int index = i * i;
            while (index <= num)
            {
                isPrime[index] = false;
                index += i;
            }
        }
    }

    return isPrime;
}

// Segmented Sieve
vector<int> segmentedSieve(int L, int R)
{
    vector<bool> sieve = sieveOfEratosthenes(sqrt(R));
    vector<int> basePrimes;
    for (int i = 0; i < sieve.size(); i++)
    {
        if (sieve[i])
        {
            basePrimes.push_back(i);
        }
    }

    vector<bool> segSieve(R - L + 1, true);
    if (L == 0)
    {
        segSieve[0] = segSieve[1] = false;
    }
    else if (L == 1)
    {
        segSieve[0] = false;
    }

    for (int prime : basePrimes)
    {
        int firstMultiple = (L / prime) * prime;
        if (firstMultiple < L)
        {
            firstMultiple += prime;
        }
        int j = max(firstMultiple, prime * prime);
        while (j <= R)
        {
            segSieve[j - L] = false;
            j += prime;
        }
    }

    vector<int> primes;
    for (int i = 0; i < segSieve.size(); i++)
    {
        if (segSieve[i])
        {
            primes.push_back(L + i);
        }
    }

    return primes;
}

int main()
{
    vector<int> ans = segmentedSieve(0, 25);
    for (int a : ans)
    {
        cout << a << " ";
    }
    cout << endl;

    return 0;
}