#include <gtest/gtest.h>
#include "../src/change_calculator.h"

TEST(ChangeCalculatorTests, CanMakeChange1)
{
    std::vector<int> result;

    std::vector<int> values = {5, 3, 1};
    std::vector<int> counts = {1, 1, 1};
    int target = 4;

    bool success = make_change(values, counts, target, result);
    EXPECT_TRUE(success);
    EXPECT_EQ(result, std::vector<int>({3, 1}));
}

TEST(ChangeCalculatorTests, CanMakeChange2)
{
    std::vector<int> result;

    std::vector<int> values = {2};
    std::vector<int> counts = {2};
    int target = 4;

    bool success = make_change(values, counts, target, result);
    EXPECT_TRUE(success);
    EXPECT_EQ(result, std::vector<int>({2, 2}));
}

TEST(ChangeCalculatorTests, CanMakeChange3)
{
    std::vector<int> result;

    std::vector<int> values = {2, 3};
    std::vector<int> counts = {3, 1};
    int target = 6;

    bool success = make_change(values, counts, target, result);
    EXPECT_TRUE(success);
    EXPECT_EQ(result, std::vector<int>({2, 2, 2}));
}

TEST(ChangeCalculatorTests, CanMakeChange4)
{
    std::vector<int> result;

    std::vector<int> values = {1, 3, 4, 5};
    std::vector<int> counts = {2, 1, 2, 1};
    int target = 10;

    bool success = make_change(values, counts, target, result);
    EXPECT_TRUE(success);
    EXPECT_EQ(result, std::vector<int>({4, 4, 1, 1}));
}

TEST(ChangeCalculatorTests, CanMakeChange5)
{
    std::vector<int> result;

    std::vector<int> values = {1, 7, 10};
    std::vector<int> counts = {3, 1, 1};
    int target = 20;

    bool success = make_change(values, counts, target, result);
    EXPECT_TRUE(success);
    EXPECT_EQ(result, std::vector<int>({10, 7, 1, 1, 1}));
}

TEST(ChangeCalculatorTests, CanMakeChange6)
{
    std::vector<int> result;

    std::vector<int> values = {1, 17, 23, 29, 41, 50};
    std::vector<int> counts = {2, 1, 3, 0, 1, 1};
    int target = 112;

    bool success = make_change(values, counts, target, result);
    EXPECT_TRUE(success);
    EXPECT_EQ(result, std::vector<int>({41, 23, 23, 23, 1, 1}));
}

TEST(ChangeCalculatorTests, CanMakeChange7)
{
    std::vector<int> result;

    std::vector<int> values = {1, 5, 13, 27, 44, 61};
    std::vector<int> counts = {10, 1, 2, 3, 3, 1};
    int target = 116;

    bool success = make_change(values, counts, target, result);
    EXPECT_TRUE(success);
    EXPECT_EQ(result, std::vector<int>({44, 44, 27, 1}));
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