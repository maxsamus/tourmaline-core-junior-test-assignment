#include "change_calculator.h"
#include <algorithm>

bool make_change(const std::vector<int> &values,
                 const std::vector<int> &counts,
                 int target,
                 std::vector<int> &result)
{
    result.clear();

    // Проверка входных данных
    int n = (int)values.size();
    if (target < 0)
        return false;
    if (n == 0)
        return target == 0;
    if ((int)counts.size() != n)
        return false;

    // Быстрая проверка: достаточно ли суммы всех монет
    long long total = 0;
    for (int i = 0; i < n; i++)
    {
        if (values[i] <= 0 || counts[i] < 0) // некорректные данные
            return false;

        total += 1LL * values[i] * counts[i];
    }
    if (total < target)
        return false;
    if (target == 0)
        return true;

    std::vector<int> dp(target + 1, -1);  // dp[s] хранит минимальное количество монет для суммы s
    std::vector<int> used(target + 1, 0); // used[s] хранит количество использованных монет для суммы s
    dp[0] = 0;

    for (int i = 0; i < n; i++)
    {
        for (int s = target; s >= 0; s--)
        {
            if (dp[s] != -1) // Если сумма s достижима
            {
                for (int k = 1; k <= counts[i] && s + k * values[i] <= target; k++)
                {
                    int ns = s + k * values[i];
                    if (dp[ns] == -1 || dp[ns] > dp[s] + k)
                    {
                        dp[ns] = dp[s] + k;
                        used[ns] = i; // Запоминаем индекс монеты
                    }
                }
            }
        }
    }

    if (dp[target] == -1)
        return false;

    // Восстановление результата
    int s = target;
    std::vector<int> used_count(n, 0);
    while (s > 0)
    {
        int coin_index = used[s];
        used_count[coin_index]++;
        s -= values[coin_index];
    }

    for (int i = 0; i < n; ++i)
    {
        for (int k = 0; k < used_count[i]; ++k)
        {
            result.push_back(values[i]);
        }
    }

    std::sort(result.rbegin(), result.rend());
    return true;
}