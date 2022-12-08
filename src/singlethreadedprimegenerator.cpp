#include <bits/stdc++.h>
#include <algorithm>

#include "../include/utils.h"
#include "../include/singlethreadedprimegenerator.h"

SingleThreadedPrimeGenerator::SingleThreadedPrimeGenerator() {}

std::vector<unsigned int> &SingleThreadedPrimeGenerator::trialDivision(unsigned int start, unsigned int end)
{
    if (start == 2)
        primes.push_back(2);

    for (unsigned int n = start; n <= end; ++n)
    {
        bool isPrime = true;
        unsigned int k = ceil(sqrt(n));

        for (unsigned int j = 2; j <= k; ++j)
        {
            if (n % j == 0)
            {
                isPrime = false;
                break;
            }
        }
        if (isPrime)
        {
            primes.push_back(n);
        }
    }

    return primes;
}

std::vector<unsigned int> &SingleThreadedPrimeGenerator::sieveOfEratosthenes(unsigned int start, unsigned int end)
{
    bool *prime = new bool[end + 1];
    memset(prime, 1, sizeof(bool) * (end + 1));

    for (unsigned int p = 2; p * p <= end; p++)
    {
        if (prime[p] == true)
        {
            for (unsigned int i = p * 2; i <= end; i += p)
                prime[i] = false;
        }
    }

    for (unsigned int p = start; p <= end; p++)
        if (prime[p])
        {
            primes.push_back(p);
        }

    delete[] prime;

    return primes;
}