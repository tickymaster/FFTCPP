#include "TonysSPGRAM.h"
#include <algorithm>
#include <cmath>

void TonysSPGRAM::GenerateSpectogram(const std::vector<int16_t>& audioData, int binSize) {
    N = binSize;

    numBins = (audioData.size() + N - 1) / N;

    SpectogramMatrix.resize(numBins, std::vector<CmplxNum>(N));

    for (size_t i = 0; i < numBins; i++)
    {
        size_t start = N * i;
        size_t end = std::min(start + N, audioData.size());
        std::vector<int16_t> bin(audioData.begin() + start, audioData.begin() + end);

        bin.resize(N, 0);

        TonysFFT fft;
        SpectogramMatrix[i] = fft.FFT(bin);
    }
}

const std::vector<std::vector<CmplxNum>>& TonysSPGRAM::GetSpectogramMatrix() const {
    return SpectogramMatrix;
}

std::vector<std::vector<int16_t>>& TonysSPGRAM::GetMagnitudeSpectogramMatrix() {
    MagnitudeSpectogramMatrix.resize(numBins, std::vector<int16_t>(N));
    for (size_t i = 0; i < numBins; i++)
    {
        for (size_t j = 0; j < N; j++)
        {
            MagnitudeSpectogramMatrix[i][j] = SpectogramMatrix[i][j].getModulus();
        }
    }
}
