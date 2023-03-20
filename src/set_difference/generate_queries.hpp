#include <algorithm>
#include <cassert>
#include <iterator>
#include <random>
#include <vector>

/// @brief Generates insertion and removal queries.
/// @param num_insertions the number of insertion queries to generate
/// @param num_removals the number of removal queries to generate
/// @param max_value a maximum value that could appear is queries, inclusive
/// @param seed a seed to use for random number generation
/// @return a list of random queries where nonnegative values represent
/// insertions and negative ones represent removals, with ~x removing a
/// previously inserted value of x
std::vector<int> generate_random_queries(int num_insertions, int num_removals,
                                         int max_value, int seed) {
  assert(0 <= num_removals && num_removals <= num_insertions &&
         num_insertions <= 100'000'000);
  assert(0 <= max_value);

  std::mt19937 gen(seed);
  std::uniform_int_distribution<int> dist(0, max_value);

  std::vector<int> insertions(num_insertions);
  for (auto& insertion : insertions) {
    insertion = dist(gen);
  }

  // Note: for heavy structs use a subset of indices instead
  std::vector<int> removals = insertions;
  for (auto& removal : removals) {
    removal = ~removal;
  }

  std::shuffle(removals.begin(), removals.end(), gen);
  copy(removals.cbegin(), next(removals.cbegin(), num_removals),
       std::back_inserter(insertions));
  return insertions;
}