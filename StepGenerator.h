//
// Created by sraga on 24/11/2025.
//

#ifndef STEPGENERATOR_H
#define STEPGENERATOR_H

#include "TimeSeriesGenerator.h"
#include <vector>
#include <cstdlib> // Pour rand() et RAND_MAX
using namespace std;

class StepGenerator : public TimeSeriesGenerator {
public:
    StepGenerator();
    StepGenerator(int s);
    vector<double> generateTimeSeries(int size) override;

private:
    double rand_uniform_0_1() const;
    double rand_uniform_0_100() const;
};

#endif