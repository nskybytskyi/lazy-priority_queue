#include "set_difference/generate_queries.hpp"

#include <gtest/gtest.h>

TEST(GenerateRandomQueriesTest, NumInsertions) {
  {  // num_insertions = 4
    const std::vector<int> expected{4, 9, 3, 0, -1, -4};
    const auto actual = generate_random_queries(4, 2, 10, 0);
    EXPECT_EQ(actual, expected);
  }

  {  // num_insertions = 5
    const std::vector<int> expected{4, 9, 3, 0, 3, -1, -4};
    const auto actual = generate_random_queries(5, 2, 10, 0);
    EXPECT_EQ(actual, expected);
  }

  {  // num_insertions = 6
    const std::vector<int> expected{4, 9, 3, 0, 3, 9, -1, -4};
    const auto actual = generate_random_queries(6, 2, 10, 0);
    EXPECT_EQ(actual, expected);
  }
}

TEST(GenerateRandomQueriesTest, NumRemovals) {
  {  // num_removals = 2
    const std::vector<int> expected{4, 9, 3, 0, 3, -1, -4};
    const auto actual = generate_random_queries(5, 2, 10, 0);
    EXPECT_EQ(actual, expected);
  }

  {  // num_removals = 3
    const std::vector<int> expected{4, 9, 3, 0, 3, -1, -4, -5};
    const auto actual = generate_random_queries(5, 3, 10, 0);
    EXPECT_EQ(actual, expected);
  }

  {  // num_removals = 4
    const std::vector<int> expected{4, 9, 3, 0, 3, -1, -4, -5, -10};
    const auto actual = generate_random_queries(5, 4, 10, 0);
    EXPECT_EQ(actual, expected);
  }
}

TEST(GenerateRandomQueriesTest, MaxValues) {
  {  // max_value == 10
    const std::vector<int> expected{4, 9, 3, 0, 3, -1, -4};
    const auto actual = generate_random_queries(5, 2, 10, 0);
    EXPECT_EQ(actual, expected);
  }

  {  // max_value == 100
    const std::vector<int> expected{44, 39, 33, 60, 63, -61, -64};
    const auto actual = generate_random_queries(5, 2, 100, 0);
    EXPECT_EQ(actual, expected);
  }

  {  // max_value == 1000
    const std::vector<int> expected{44, 239, 933, 760, 963, -761, -964};
    const auto actual = generate_random_queries(5, 2, 1000, 0);
    EXPECT_EQ(actual, expected);
  }
}

TEST(GenerateRandomQueriesTest, Seeds) {
  {  // seed == 0
    const std::vector<int> expected{4, 9, 3, 0, 3, -1, -4};
    const auto actual = generate_random_queries(5, 2, 10, 0);
    EXPECT_EQ(actual, expected);
  }

  {  // seed == 1
    const std::vector<int> expected{5, 9, 4, 8, 3, -10, -4};
    const auto actual = generate_random_queries(5, 2, 10, 1);
    EXPECT_EQ(actual, expected);
  }

  {  // seed == 2
    const std::vector<int> expected{8, 7, 1, 4, 8, -5, -9};
    const auto actual = generate_random_queries(5, 2, 10, 2);
    EXPECT_EQ(actual, expected);
  }
}