#ifndef TONYSFFT_H
#define TONYSFFT_H

#include <vector>
#include "CmplxNum.h"

class TonysFFT {
public:
	void SaveFourierArrayToFile(const std::vector<std::vector<CmplxNum>> matrixArray);
	std::vector<std::vector<CmplxNum>> CreateFourierArray(int N);
	void CreateDefaultFR();
};

#endif // TONYSFFT_H