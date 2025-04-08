#include "iostream"
#include "CmplxNum.h"
#include "TonysFFT.h"
#include "WavFile.h"
#include "TonysSPGRAM.h"
#include "chrono"
//#include "matplotlibcpp.h"

//namespace plt = matplotlibcpp;

int main() {
    using namespace std;

    TonysFFT fft;
    WavFile wav;
    std::string fname = "waveform.wav";
    wav.load(fname);
    std::vector<int16_t> hi = wav.getAudioData();

    std::cout << "Size: " << hi.size();

    TonysSPGRAM obj;
    obj.GenerateSpectogram(hi,1024);
    vector<vector<CmplxNum>> ComplexSpectogram =  obj.GetSpectogramMatrix();
    
    cout << '\n' << "done" << '\n';
    cout << "Matrix size: " << ComplexSpectogram.size() << '\n';
    cout << "Matrix size(1): " << ComplexSpectogram[1].size() << '\n';
    cout << "Debug done." << endl;

    return 0;
}
