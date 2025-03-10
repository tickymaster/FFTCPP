#include "iostream"
#include "CmplxNum.h"
#include "TonysFFT.cpp"
//Test-file, may be ignored to implement the CmplxNum class in a different project.

void main() {

    using namespace std;

    CmplxNum Num1(0,0);
    CmplxNum Num2(0,0);

    Num1.setModulus(3);
    Num1.setArgument(4);
    
	Num2.setModulus(4);
	Num2.setArgument(7);

    CmplxNum quot = Num1 / Num2;
    std::cout << "Quotient: " << quot.ToString() << std::endl;

    std::vector<int> x = { 1, 2, 3, 4, 5, 5, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6 };

    int size = x.size();

    TonysFFT fft(x);

    std::vector<std::vector<int>> fourierArray = fft.ReturnFourierArray(size);

    for (size_t k = 0; k < size; k++)
    {
        for (size_t n = 0; n < size; n++)
        {
            cout << fourierArray[k][n] << " ";
        }
    }
}