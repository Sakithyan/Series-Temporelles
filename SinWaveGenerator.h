//
// Created by sraga on 01/12/2025.
//

#ifndef SINWAVEGENERATOR_H
#define SINWAVEGENERATOR_H

#include "TimeSeriesGenerator.h"
#include <vector>
#include <cmath>
using namespace std;

class SinWaveGenerator : public TimeSeriesGenerator {
private:
    double amplitude;
    double frequency;
    double phase;

public:
    SinWaveGenerator();
    SinWaveGenerator(int s, double A, double w, double p);
    vector<double> generateTimeSeries(int size) override;
};

#endif