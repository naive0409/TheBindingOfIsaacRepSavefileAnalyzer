#include "necessaryInclude.h"

// int main()
// {
//     s = vector<bool>({true, false,true,false});

// }


// #include <iostream>
// #include <vector>

std::vector<int> findFalsePositions(const std::vector<bool>& challenges) {
    std::vector<int> falsePositions;

    for (int i = 0; i < challenges.size(); ++i) {
        if (!challenges[i]) {
            falsePositions.push_back(i);
        }
    }

    return falsePositions;
}

int main() {
    std::vector<bool> challenges = {true, false, true, false, false, true};
    std::vector<int> falsePositions = findFalsePositions(challenges);

    std::cout << "False positions: ";
    for (int position : falsePositions) {
        std::cout << position << " ";
    }
    std::cout << std::endl;

    return 0;
}
