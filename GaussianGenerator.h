//
// Created by sraga on 24/11/2025.
//

#ifndef GAUSSIANGENERATOR_H
#define GAUSSIANGENERATOR_H

#include "TimeSeriesGenerator.h"
#include <vector>
#include <cmath>
using namespace std;

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

class GaussianGenerator : public TimeSeriesGenerator {
private:
    double mean;
    double stdDev;
    double boxMuller();

public:
    GaussianGenerator();
    GaussianGenerator(int s, double mu, double sigma);
    vector<double> generateTimeSeries(int size) override;
};

#endif