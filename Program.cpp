#include "iostream"
#include "CmplxNum.h"
#include "TonysFFT.h"
#include "TonysWAV.h"

int main() {
    using namespace std;
    TonysFFT fft;
    TonysWAV wav;
    
    wav.read_wav_file("Vowel-A.wav");
}