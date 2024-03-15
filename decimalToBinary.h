#include <vector>
std::vector<int> decimalToBinary(int decimal) {
    std::vector<int> binary;
    while (decimal > 0) {
        binary.insert(binary.begin(), decimal % 2);
        decimal /= 2;
    }
    return binary;
}