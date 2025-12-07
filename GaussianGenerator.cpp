//
// Created by sraga on 24/11/2025.
//

#include "GaussianGenerator.h"
#include <cstdlib>
#include <cmath>
#include <stdexcept>

using namespace std;

GaussianGenerator::GaussianGenerator()
    : TimeSeriesGenerator(), mean(0.0), stdDev(1.0) {
    srand(seed);
}

GaussianGenerator::GaussianGenerator(int s, double mu, double sigma)
    : TimeSeriesGenerator(s), mean(mu), stdDev(sigma) {

    if (stdDev < 0.0) {
        throw std::invalid_argument("Standard deviation (sigma) cannot be negative.");
    }
    srand(seed);
}
double GaussianGenerator::boxMuller() {
    double u1 = (rand() + 1.0) / (RAND_MAX + 2.0);
    double u2 = (rand() + 1.0) / (RAND_MAX + 2.0);

    double z = sqrt(-2.0 * log(u1)) * cos(2.0 * M_PI * u2);
    return mean + z * stdDev;
}
vector<double> GaussianGenerator::generateTimeSeries(int size) {
    if (size <= 0) return {};

    vector<double> series;
    for (int i = 0; i < size; ++i) {
        series.push_back(boxMuller());
    }

    return series;
}