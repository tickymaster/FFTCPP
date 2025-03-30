#include "TonysFFT.h"
#include "fstream"
#include "vector"
#include "sstream"
#include "filesystem"
#include "Windows.h"
#include "CmplxNum.h"
#include "iostream"
#include "string"

//Ill try to create an fft algorithm using both integers and floating point numbers, for speed and precission respecfully.

void TonysFFT::SaveFourierArrayToFile(std::vector<std::vector<CmplxNum>>& matrixArray) {
	using namespace std;

	int rows = matrixArray.size();
	int cols = matrixArray[0].size();

	if (rows != cols) {
		throw invalid_argument("The matrix array's dimensions are not equal.");
	}

	stringstream filename;
	filename << "FArray(" << rows << "x" << cols << ").bin";
	string name = filename.str();

	ofstream file(name, ios::out | ios::binary);

	if (!file.is_open()) {
		cerr << "Error opening file for writing: " << name << endl;
		return;
	}

	// Write the dimensions of the matrix
	file.write(reinterpret_cast<const char*>(&rows), sizeof(rows));
	file.write(reinterpret_cast<const char*>(&cols), sizeof(cols));

	for (size_t i = 0; i < rows; i++) {
		for (size_t j = 0; j < cols; j++) {
			double real = matrixArray[i][j].getReal();
			double imag = matrixArray[i][j].getImag();
			file.write(reinterpret_cast<const char*>(&real), sizeof(real));
			file.write(reinterpret_cast<const char*>(&imag), sizeof(imag));
		}
		// Clear the row from memory after writing it to the file
		vector<CmplxNum>().swap(matrixArray[i]);
	}

	file.close();

	cout << "File successfully saved to " + name << endl;
}


std::vector<std::vector<CmplxNum>> TonysFFT::LoadFourierArrayFromFile(std::string filename) {
	using namespace std;
	ifstream file(filename, ios::in | ios::binary);

	if (!file.is_open()) {
		cerr << "Error opening file for reading: " << filename << endl;
		return {};
	}

	int rows, cols;
	file.read(reinterpret_cast<char*>(&rows), sizeof(rows));
	file.read(reinterpret_cast<char*>(&cols), sizeof(cols));

	vector<vector<CmplxNum>> fourierArray(rows, vector<CmplxNum>(cols));

	for (size_t i = 0; i < rows; i++) {
		for (size_t j = 0; j < cols; j++) {
			double real, imag;
			file.read(reinterpret_cast<char*>(&real), sizeof(real));
			file.read(reinterpret_cast<char*>(&imag), sizeof(imag));
			fourierArray[i][j] = CmplxNum(real, imag);
		}
	}

	file.close();

	return fourierArray;
}



std::vector<std::vector<CmplxNum>> TonysFFT::CreateFourierArray(int N) {
	using namespace std;
	CmplxNum obj;
	const int PI = 3;
	vector<vector<CmplxNum>> matrixArray(N, vector<CmplxNum>(N));

	const double TWO_PI_OVER_N = 2.0 * PI / double(N);

	CmplxNum W = CmplxNum(1, 0);
	W.setArgument(TWO_PI_OVER_N);

	for (size_t i = 0; i < N; i++)
	{
		matrixArray[0][i] = CmplxNum(1, 0);
		matrixArray[i][0] = CmplxNum(1, 0);
	}

	W.setReal(1);
	W.setImag(0);
	W.setArgument(TWO_PI_OVER_N);

	for (size_t n = 1; n < N; n++)
	{
		for (size_t k = 1; k < N; k++)
		{
			matrixArray[n][k] = obj.Pow(W, n * k);
		}
	}

	return matrixArray;
}

bool TonysFFT::VerifyFourierArray(std::vector <std::vector<CmplxNum>> inputArray) {
	using namespace std;

	TonysFFT fft;
	int size = inputArray.size();

	vector<vector<CmplxNum>> correctArray = fft.LoadFourierArrayFromFile("CorrectFArray.csv");

	for (size_t i = 0; i < size; i++)
	{
		for (size_t j = 0; j < size; j++)
		{
			if (!(inputArray[i][j] == correctArray[i][j]))
			{
				cerr << "The 2 arrays are not the same";
				cout << i, j;
				return false;
			}
			cout << i, j;
		}
	}
	return true;

}

void TonysFFT::CreateDefaultFR() {
	//creates a default fourier array with dimenssions 48k x 48k
	using namespace std;
	int N = 48000;
	CmplxNum obj;
	const int PI = 3;

	stringstream filename;
	filename << "FArray(" << N << "x" << N << ").bin";
	string name = filename.str();

	ofstream file(name);

	if (!file.is_open()) {
		cerr << "Error opening file for writing: " << name << endl;
		return;
	}

	// Write the dimensions of the matrix
	file.write(reinterpret_cast<const char*>(&N), sizeof(N));
	file.write(reinterpret_cast<const char*>(&N), sizeof(N));

	const double TWO_PI_OVER_N = 2.0 * PI / double(N);

	CmplxNum W = CmplxNum(1, 0);
	W.setArgument(TWO_PI_OVER_N);

	for (size_t i = 0; i < N; i++) {
		double real = 1.0;
		double imag = 0.0;
		file.write(reinterpret_cast<const char*>(&real), sizeof(real));
		file.write(reinterpret_cast<const char*>(&imag), sizeof(imag));
	}

	for (size_t i = 1; i < N; i++) {
		double real = 1.0;
		double imag = 0.0;
		for (size_t j = 1; j < N; j++) {
			CmplxNum value = CmplxNum::Pow(W, i * j);
			double real = value.getReal();
			double imag = value.getImag();
			file.write(reinterpret_cast<const char*>(&real), sizeof(real));
			file.write(reinterpret_cast<const char*>(&imag), sizeof(imag));
		}
	}

	file.close();

	cout << "File successfully saved to " + name << endl;
}


std::vector<CmplxNum> TonysFFT::FFT(std::vector<int>) {
	std::vector<CmplxNum> outputArray;
	return outputArray;
}

std::vector<CmplxNum> TonysFFT::DFT(std::vector<int>) {
	using namespace std;
	vector<CmplxNum> outputArray;
	vector<vector<CmplxNum>> fourierArray = LoadFourierArrayFromFile("");
	return outputArray;
}
