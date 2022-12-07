#include <iostream>
#include <vector>

#include "include/primegenerator.h"
#include "include/timer.h"
#include "include/argumentparser.h"

void output(Result &result)
{
    std::cout << "number of primes: " << result.primes.size() << "\n";
    std::cout << "time: " << result.time << "\n";
}

int main(int argc, char *argv[])
{
    Timer timer = Timer();
    ArgumentParser argumentParser = ArgumentParser(argc, argv);
    argumentParser.printHelp();
    PrimeGenerator primeGenerator = PrimeGenerator();
    Result result = timer.time(primeGenerator.trailDivision, 2, 10000000);
    output(result);

}