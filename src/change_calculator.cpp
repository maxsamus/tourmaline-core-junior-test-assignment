#include "change_calculator.h"
#include <queue>
#include <algorithm>

bool make_change(const std::vector<int> &values,
                 const std::vector<int> &counts,
                 int target,
                 std::vector<int> &result)
{
    result.clear();

    // Input validation
    int n = (int)values.size();
    if (target < 0)
        return false;
    if (n == 0)
        return target == 0;
    if ((int)counts.size() != n)
        return false;

    // Quick check: is the total sum of all coins enough?
    long long total = 0;
    for (int i = 0; i < n; i++)
    {
        if (values[i] <= 0 || counts[i] < 0) // Invalid data
            return false;

        total += 1LL * values[i] * counts[i];
    }
    if (total < target)
        return false;
    if (target == 0)
        return true;

    std::vector<bool> used(target + 1, false); // Track visited sums
    std::queue<std::pair<int, std::vector<int>>> q;

    used[0] = true;
    q.emplace(0, std::vector<int>(n, 0));

    while (!q.empty())
    {
        auto [sum, used_coins] = q.front();
        q.pop();

        if (sum == target)
        {
            // Restore the result
            for (int i = 0; i < n; ++i)
            {
                for (int k = 0; k < used_coins[i]; ++k)
                {
                    result.push_back(values[i]);
                }
            }
            std::sort(result.rbegin(), result.rend());
            return true;
        }

        for (int i = 0; i < n; ++i)
        {
            // Try to add from 1 to counts[i] coins of denomination i
            for (int k = 1; k <= counts[i] - used_coins[i]; ++k)
            {
                int new_sum = sum + k * values[i];
                if (new_sum > target)
                    break;
                if (!used[new_sum])
                {
                    auto new_used_coins = used_coins;
                    new_used_coins[i] += k;
                    used[new_sum] = true;
                    q.emplace(new_sum, new_used_coins);
                }
            }
        }
    }

    return false;
}