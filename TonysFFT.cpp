//#include "fstream"
//#include "vector"
//#include "sstream"
//#include "filesystem"
//#include "Windows.h"
//
//#include "CmplxNum.h"
//
////Ill try to create an fft algorithm using both integers and floating point numbers, for speed and precission respecfully.
//
//class TonysFFT {
//public:
//	//Saving utility, saves at the same parent folder as the program is located at.
//	void SaveFourierArrayToFile(const std::vector<std::vector<CmplxNum>> matrixArray) {
//		using namespace std;
//
//		int rows = matrixArray.size();
//		int cols = matrixArray[0].size();
//
//		stringstream filename;
//		filename << "FArray(" << rows << "x" << cols << ").txt";
//
//		string directory =
//
//			ofstream file(filename);
//
//		if (!file) {
//			cerr << "Error opening file for writing!" << endl;
//		}
//
//		for (const auto& row : matrixArray) {
//			for (const auto& element : matrixArray)
//				file.write(reinterpret_cast<const char*>(&element), sizeof(CmplxNum));
//		}
//
//		file.close();
//		cout << "Fourier array saved successfully to " << filename << endl;
//	}
//
//	std::vector<std::vector<CmplxNum>> GetFourierArray(int N) {
//		using namespace std;
//		const int PI = 3;
//		vector<vector<CmplxNum>> matrixArray(N, vector<CmplxNum>(N));
//
//		const double TWO_PI_OVER_N = 2.0 * PI / double(N);
//		CmplxNum Complex_Number = CmplxNum(1, 0);
//		for (size_t k = 0; k < N; k++)
//		{
//			for (size_t n = 0; n < N; n++)
//			{
//				Complex_Number.setArgument(TWO_PI_OVER_N * n * k);
//				matrixArray[k][n] = Complex_Number;
//			}
//		}
//		return matrixArray;
//	}
//
//	void CreateDefualtFR() {
//		//creates a defualt fourier array of dimensions: 50,000 x 50,000
//
//	}
//};