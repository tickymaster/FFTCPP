#include "iostream"
#include "CmplxNum.h"
#include "TonysFFT.h"
#include "TonysWAV.h"
#include "chrono"
//#include "matplotlibcpp.h"

//namespace plt = matplotlibcpp;

int main() {
    using namespace std;
    using namespace std::chrono;

    TonysFFT fft;
    TonysWAV wav;
    std::string fname = "Vowel-A.wav";
    std::vector<int16_t> hi = wav.get_wav_raw_data(fname);
    cout << "Size: " << hi.size();

    // Start measuring time
    auto start = high_resolution_clock::now();

    std::vector<CmplxNum> fftResult = fft.FFT(hi);

    // Stop measuring time
    auto stop = high_resolution_clock::now();

    // Calculate the duration
    auto duration = duration_cast<milliseconds>(stop - start);

    std::vector<double> magnitudes = fft.GetMagnitudes(fftResult);

    int i = 0;

    for (auto& x : magnitudes)
    {
        cout << x << '\n';
        i++;
    }
    int j = 0;
    
    cout << "FFT algo: " << "\n";

    for (auto& x: hi)
    {
        cout << x << '\n';
        j++;
    }

    if (j==i)
    {
        cout << "All good" << "\n";
    }
    else {
        cout << "oh oh" << "\n";
    }

    cout << i;
    // Plot the magnitudes
    //plt::plot(magnitudes);

    // Print the duration
    cout << "Time taken by FFT: " << duration.count() << " milliseconds" << endl;

    return 0;
}
