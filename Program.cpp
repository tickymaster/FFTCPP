#include "iostream"
#include "CmplxNum.h"
#include "TonysFFT.h"
int main() {
    using namespace std;
    TonysFFT fft;
    //cout << "Creating array...";
    //vector<vector<CmplxNum>> array = fft.CreateFourierArray(44000);
    //cout << "\n";
    //cout << "Array created: saving...";
    //fft.SaveFourierArrayToFile(array);
    //fft.CreateDefaultFR();

    cout << "loading...";
    vector<vector<CmplxNum>> array = fft.LoadFourierArrayFromFile("FArray(48000x48000).bin");
    cout << "Loaded: Printing...";
    for (size_t i = 0; i < array.size(); i++)
    {
        for (size_t j = 0; j < array.size(); j++)
        {
            cout << array[i][j];
        }
    }

    return 0;
}