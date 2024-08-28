#include "KeyUtil.h"
#include <string>

bool hasExactlyOnePairOfConsecutiveDigits(const uint256_t& num) {
    std::string hexString = num.toString(16);
    int pairCount = 0;
    for (size_t i = 0; i < hexString.length() - 1; i++) {
        if (hexString[i] == hexString[i+1]) {
            pairCount++;
            i++; // Skip next digit as it's part of the pair
        }
        if (pairCount > 1) {
            return false;
        }
    }
    return pairCount == 1;
}
