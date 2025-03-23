#include "TonysFFT.h"
#include "fstream"
#include "vector"
#include "sstream"
#include "filesystem"
#include "Windows.h"
#include "CmplxNum.h"

//Ill try to create an fft algorithm using both integers and floating point numbers, for speed and precission respecfully.

void TonysFFT::SaveFourierArrayToFile(const std::vector<std::vector<CmplxNum>> matrixArray) {
	//Saving utility, saves at the same parent folder as the program is located at.
	using namespace std;

	int rows = matrixArray.size();
	int cols = matrixArray[0].size();

	if (rows != cols) {
		throw invalid_argument("The matrix array's dimenssions are not equal.");
	}

	stringstream filename;
	filename << "FArray(" << rows << "x" << cols << ").csv";
	string name = filename.str();

	ofstream file(name);

	for (size_t i = 0; i < rows; i++)
	{
		for (size_t j = 0; j < cols; j++)
		{
			file << matrixArray[i][j];
		}
	}

	file.close();

	cout << "File succesfully saved to " + name + ". Dimenssions = {", rows + " " +  cols, "}";
}

std::vector<std::vector<CmplxNum>> TonysFFT::CreateFourierArray(int N) {
	using namespace std;
	const int PI = 3;
	vector<vector<CmplxNum>> matrixArray(N, vector<CmplxNum>(N));

	const double TWO_PI_OVER_N = 2.0 * PI / double(N);
	CmplxNum Complex_Number = CmplxNum(1, 0);
		for (size_t k = 0; k < N; k++)
		{
			for (size_t n = 0; n < N; n++)
			{
			Complex_Number.setArgument(TWO_PI_OVER_N * n * k);
			matrixArray[k][n] = Complex_Number;
			}
		}
		return matrixArray;
	}
void TonysFFT::CreateDefaultFR() {
	//creates a default fourier array with dimenssions 55k x 55k
	SaveFourierArrayToFile(CreateFourierArray(55000));
	}
};