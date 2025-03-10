#ifndef TONYSFFT_H
#define TONYSFFT_H

#include <vector>
#include "CmplxNum.h"

class TonysFFT {
public:
	std::vector<std::vector<int>> CreateFourierArray();
	std::vector<std::vector<CmplxNum>> ReturnFourierArray(int N)
};

#endif // TONYSFFT_H