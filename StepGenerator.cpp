//
// Created by sraga on 24/11/2025.
//

#include "StepGenerator.h"
#include <cstdlib>

using namespace std;

StepGenerator::StepGenerator()
    : TimeSeriesGenerator() {
    srand(seed);
}

StepGenerator::StepGenerator(int s)
    : TimeSeriesGenerator(s) {
    srand(seed);
}

double StepGenerator::rand_uniform_0_1() const {
    return (rand() + 1.0) / (RAND_MAX + 2.0);
}

double StepGenerator::rand_uniform_0_100() const {
    return 100.0 * rand_uniform_0_1();
}

vector<double> StepGenerator::generateTimeSeries(int size) {
    if (size <= 0) return {};

    vector<double> series;

    double currentValue = 0.0;

    for (int i = 0; i < size; ++i) {
        if (rand_uniform_0_1() >= 0.5) {
            currentValue = rand_uniform_0_100();
        }
        series.push_back(currentValue);
    }
    return series;
}