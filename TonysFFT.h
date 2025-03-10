#ifndef TONYSFFT_H
#define TONYSFFT_H

#include <vector>

class TonysFFT {
public:
    TonysFFT(); // Constructor
    std::vector<std::vector<int>> CreateFourierArray();

private:
    std::vector<int> x;
    std::vector<std::vector<int>> matrixArray;
    std::vector<int> X;
    const int PI = 3;
};

#endif // TONYSFFT_H