//
// Created by sraga on 01/12/2025.
//

#include "SinWaveGenerator.h"
#include <cmath>
#include <stdexcept>

using namespace std;

SinWaveGenerator::SinWaveGenerator()
    : TimeSeriesGenerator(), amplitude(1.0), frequency(1.0), phase(0.0) {}
SinWaveGenerator::SinWaveGenerator(int s, double A, double w, double p)
    : TimeSeriesGenerator(s), amplitude(A), frequency(w), phase(p) {

}

vector<double> SinWaveGenerator::generateTimeSeries(int size) {
    if (size <= 0) return {};

    vector<double> series;
    for (int i = 0; i < size; ++i) {
        double value = amplitude * std::sin(frequency * i + phase);

        series.push_back(value);
    }
    return series;
}