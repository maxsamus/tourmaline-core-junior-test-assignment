#include <gtest/gtest.h>
#include "../src/change_calculator.h"

TEST(ChangeCalculatorTests, CanMakeChange)
{
    std::vector<int> result;

    std::vector<int> values = {5, 3, 1};
    std::vector<int> counts = {1, 1, 1};
    int target = 4;

    bool success = make_change(values, counts, target, result);
    EXPECT_TRUE(success);
    EXPECT_EQ(result, std::vector<int>({3, 1}));
}

TEST(ChangeCalculatorTests, CannotMakeChange)
{
    std::vector<int> result;

    std::vector<int> values = {5, 3, 1};
    std::vector<int> counts = {1, 1, 1};
    int target = 10;

    bool success = make_change(values, counts, target, result);
    EXPECT_FALSE(success);
}

TEST(ChangeCalculatorTests, ExactChangeWithAllCoins)
{
    std::vector<int> result;

    std::vector<int> values = {5, 3, 1};
    std::vector<int> counts = {1, 1, 1};
    int target = 9;

    bool success = make_change(values, counts, target, result);
    EXPECT_TRUE(success);
    EXPECT_EQ(result, std::vector<int>({5, 3, 1}));
}

TEST(ChangeCalculatorTests, ZeroTarget)
{
    std::vector<int> result;

    std::vector<int> values = {5, 3, 1};
    std::vector<int> counts = {1, 1, 1};
    int target = 0;

    bool success = make_change(values, counts, target, result);
    EXPECT_TRUE(success);
    EXPECT_TRUE(result.empty());
}

TEST(ChangeCalculatorTests, EmptyInputs)
{
    std::vector<int> result;

    std::vector<int> values = {};
    std::vector<int> counts = {};
    int target = 0;

    bool success = make_change(values, counts, target, result);
    EXPECT_TRUE(success);
    EXPECT_TRUE(result.empty());
}

TEST(ChangeCalculatorTests, NegativeTarget)
{
    std::vector<int> result;

    std::vector<int> values = {5, 3, 1};
    std::vector<int> counts = {1, 1, 1};
    int target = -5;

    bool success = make_change(values, counts, target, result);
    EXPECT_FALSE(success);
}

TEST(ChangeCalculatorTests, NegativeValues)
{
    std::vector<int> result;

    std::vector<int> values = {-5, 3, 1};
    std::vector<int> counts = {1, 1, 1};
    int target = 4;

    bool success = make_change(values, counts, target, result);
    EXPECT_FALSE(success);
}

TEST(ChangeCalculatorTests, NegativeCounts)
{
    std::vector<int> result;

    std::vector<int> values = {5, 3, 1};
    std::vector<int> counts = {1, -1, 1};
    int target = 4;

    bool success = make_change(values, counts, target, result);
    EXPECT_FALSE(success);
}

TEST(ChangeCalculatorTests, LargeNumberOfCoins)
{
    std::vector<int> result;

    std::vector<int> values = {1};
    std::vector<int> counts = {100};
    int target = 99;

    bool success = make_change(values, counts, target, result);
    EXPECT_TRUE(success);
    EXPECT_EQ(result.size(), 99);
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}