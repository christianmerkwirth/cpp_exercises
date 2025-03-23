// Let’s tackle this problem by writing a C++ simulation for the amoeba population. 
// The problem describes a branching process where each amoeba, after every minute, 
// can either die, stay the same, split into two, or split into three, each with equal probability. 
// We need to simulate this process for a given number of time steps ( T ), 
// repeat the simulation ( N ) times, and report the distribution of the
// resulting number of amoebas. Both ( N ) (number of simulations)
// and ( T ) (time steps) will be provided as command-line arguments.
//
// Compile with: g++ -std=c++17 -Wall -Wextra -Wpedantic -O3 -o amoeba_sim amoeba_sim.cpp

#include <iostream>
#include <random>
#include <map>
#include <cstdlib>

int main(int argc, char* argv[]) {
    // Check for correct number of command-line arguments
    if (argc != 3) {
        std::cerr << "Usage: " << argv[0] << " <N> <T>\n";
        std::cerr << "N: Number of simulations\nT: Number of time steps\n";
        return 1;
    }

    // Parse command-line arguments
    int N = std::atoi(argv[1]); // Number of simulations
    int T = std::atoi(argv[2]); // Number of time steps

    if (N <= 0 || T < 0) {
        std::cerr << "N must be positive, and T must be non-negative.\n";
        return 1;
    }

    // Set up random number generation
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(0, 3); // For outcomes 0, 1, 2, 3

    // Map to store the distribution of final population sizes
    std::map<long long, long long> population_distribution;

    // Run N simulations
    for (int sim = 0; sim < N; ++sim) {
        // Start with 1 amoeba
        long long current_count = 1;

        // Simulate for T time steps
        for (int t = 0; t < T; ++t) {
            long long new_count = 0;
            // Process each amoeba in the current population
            for (long long i = 0; i < current_count; ++i) {
                const int outcome = dis(gen); // Random outcome: 0 (die), 1 (stay), 2 (split into 2), 3 (split into 3)
                new_count += outcome; // Add the number of new amoebas
            }
            // Update the population count for the next time step
            current_count = new_count;
            if ((current_count == 0) || (current_count >= 100)) {
                break; // No need to continue, either the population is extinct or so large it has vanishing probability to die out
            }
        }

        // Record the final population
        population_distribution[current_count]++;
    }

    // Output the distribution
    std::cout << "Distribution of amoeba population sizes after " << T << " time steps (" << N << " simulations):\n";
    std::cout << "Population Size\tCount\tProbability\n";

    for (const auto& entry : population_distribution) {
        long long pop_size = entry.first;
        long long count = entry.second;
        double probability = static_cast<double>(count) / N;
        std::cout << pop_size << "\t\t" << count << "\t" << probability << "\n";
    }

    return 0;
}
