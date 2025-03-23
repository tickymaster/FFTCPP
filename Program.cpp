#include "iostream"
#include "CmplxNum.h"
#include "TonysFFT.h"
int main() {
    using namespace std;
    TonysFFT fft;
    cout << "TonysFFT defined as fft, calling the CreateDefaultFR";
    std::vector<std::vector<CmplxNum>> fourier_array = fft.CreateFourierArray(2000);
    cout << "Saving to file: ";
    fft.SaveFourierArrayToFile(fourier_array);
    return 0;
}