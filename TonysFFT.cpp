#include "vector"
#include "CmplxNum.h"

//Ill try to create an fft algorithm using both integers and floating point numbers, for speed and precission respecfully.

class TonysFFT {
private:
	std::vector<std::vector<int>> matrixArray;
	std::vector<std::vector<int>> X;

	const int PI = 3;

	std::vector<std::vector<int>> CreateFourierArray(int N) {
		const double TWO_PI_OVER_N = 2 * PI / N;
		for (size_t k = 0; k < N; k++)
		{
			for (size_t n = 0; n < N; n++)
			{
				matrixArray[k][n] = TWO_PI_OVER_N * n * k;
			}
		}
		return matrixArray;
	}
public:
	TonysFFT(std::vector<int> x) {
		int N = x.size();
		matrixArray.resize(N, std::vector<int>(N));
		X.resize(N, std::vector<int>(N));
		CreateFourierArray(N);
	}
	std::vector<std::vector<int>> ReturnFourierArray(int N) {
		return CreateFourierArray(N);
	}
};