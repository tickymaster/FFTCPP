#ifndef TONYSFFT_H
#define TONYSFFT_H

#include <vector>
#include "CmplxNum.h"

class TonysFFT {
public:
	void SaveFourierArrayToFile(std::vector<std::vector<CmplxNum>>& matrixArray);
	std::vector<std::vector<CmplxNum>> LoadFourierArrayFromFile(std::string filename);
	std::vector<std::vector<CmplxNum>> CreateFourierArray(int N);
	bool VerifyFourierArray(std::vector <std::vector<CmplxNum>> inputArray);
	void CreateDefaultFR();
	//fourier transforms

	std::vector<CmplxNum> FFT(std::vector<int>);
private:
	std::vector<CmplxNum> DFT(std::vector<int>);
};

#endif // TONYSFFT_H