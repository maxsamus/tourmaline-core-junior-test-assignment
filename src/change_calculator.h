#ifndef CHANGE_CALCULATOR_H
#define CHANGE_CALCULATOR_H

#include <vector>

bool make_change(const std::vector<int> &values,
                 const std::vector<int> &counts,
                 int target,
                 std::vector<int> &result);

#endif // CHANGE_CALCULATOR_H