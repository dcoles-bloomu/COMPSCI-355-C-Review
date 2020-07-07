/*
 * For a specified number of balls tossed at random into a specified number
 * of bins, calculates the probability that there will be at least one bin
 * with two or more balls. For 23 balls and 365 bins, this illustrates the
 * classic Birthday Paradox.
 *
 * The numbers of balls and bins are given by command-line arguments.
 *
 * Points of discussion: documentation, function prototypes, command-line 
 * arguments, static casting, stream manipulators, and dynamic allocation 
 * of linear arrays.
 *
 * Execution snapshot (with command-line arguments 23 365):
 *
 *      23 balls are tossed at random into 365 bins.
 *      Probability of a bin with two or more balls: 50.7%
 *
 * Author: Drue Coles
 */

#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <ctime>
using namespace std;

// Simulates tossing a sequence of balls into bins at random, and returns the
// maximum load (the maximum number of balls in any bin).
int max_load(int num_balls, int num_bins);

int main(int argc, char** argv) {
   // Validate and process command-line arguments.
   if (argc != 3) {
      cout << "Invalid command-line arguments.\n";
      cout << "Expecting " << argv[0] <<  " " << "[num balls] [num bins].\n";
      return 0;
   }
   int num_balls = atoi(argv[1]);
   int num_bins = atoi(argv[2]);

   // Repeat randomized experiment many times and record the number of times
   // there is at least one bin with two or more balls.
   const int TRIALS = 1000000;
   srand(time(0));
   int success = 0;
   for (int i = 0; i < TRIALS; i++) {
      if (max_load(num_balls, num_bins) > 1) {
         success++;
      }
   }

   // Calculate probability as a fraction of successful trials.
   double prob = static_cast<double>(success) / TRIALS * 100;
   cout << num_balls << " balls are tossed at random into " << num_bins
        << " bins." << endl;
   cout << "Probability of a bin with two or more balls: "
        << setprecision(3) << prob << "%" << endl;
   return 0;
}

int max_load(int num_balls, int num_bins) {
    // bins[i] = number of balls in the i-th bin
    int* bins = new int[num_bins];
    for (int i = 0; i < num_bins; i++) {
        bins[i] = 0;
    }

    // throw each ball into a randomly selected bin
    int max_load = 0;
    for (int i = 0; i < num_balls; i++) {
        int j = rand() % num_bins;
        bins[j]++;
        max_load = bins[j] > max_load ? bins[j] : max_load;
    }

    delete[] bins;
    return max_load;
}