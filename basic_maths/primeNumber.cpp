#include <iostream>
#include <math.h>
#include <vector>
using namespace std;

// 1. Naive Approach
bool naiveApproach(int num)
{
    if (num < 2)
    {
        return false;
    }

    for (int i = 2; i < num; i++)
    {
        if (num % i == 0)
        {
            return false;
        }
    }

    return true;
}

// 2. Sqrt Approach
bool sqrtApproach(int num)
{
    if (num < 2)
    {
        return false;
    }
    cout << sqrt(num) << endl;
    for (int i = 2; i <= sqrt(num); i++)
    {
        if (num % i == 0)
        {
            return false;
        }
    }

    return true;
}

// 3. Sieve of Eratosthenes
int sieveOfEratosthenes(int num)
{
    // step 1: mark all numbers from n = 2 to n - 1 as prime
    vector<bool> isPrime(num, true);
    isPrime[0] = isPrime[1] = false;
    // step 2: start from i = 2, if prime, increase count and mark all the multiples of i as non prime
    int count = 0;
    // for (int i = 2; i < num; i++)
    for (int i = 2; i < sqrt(num); i++) // optimization 2: we are starting inner loop from i*i
    {
        if (isPrime[i])
        {
            // int index = i * 2;
            int index = i * i; // optimization 1: (2 to i - 1 has been already marked by previous numbers)
            while (index < num)
            {
                isPrime[index] = false;
                index += i;
            }
        }
    }

    for (auto p : isPrime)
    {
        if (p)
        {
            count++;
        }
    }

    return count;
}

// 4. Segmented Sieve
bool segmentedSieve(int left, int right)
{
    vector<bool> sieve(right - left + 1, true);
    for (int i = left; i <= sqrt(right); i++)
    {
        int j = i * i;
        if (sieve[j])
        {
            while (j <= right)
            {
            }
        }
    }
}

int main()
{
    cout << "Enter a number : ";
    int n;
    cin >> n;

    // bool isPrime;
    // isPrime = naiveApproach(n);
    // isPrime = sqrtApproach(n);
    // if (isPrime)
    // {
    //     cout << n << " is a prime number." << endl;
    // }
    // else
    // {
    //     cout << n << " is not a prime number." << endl;
    // }

    // count prime numbers between 0 to n - 1 | Leetcode 204;
    int countPrimes;
    countPrimes = sieveOfEratosthenes(n);
    // isPrime = segmentedSieve(n);
    cout << "Answer: " << countPrimes << endl;

    return 0;
}