//
// Created by sraga on 02/12/2025.
//

#include "TimeSeriesDataset.h"
#include <numeric>
#include <algorithm>
#include <cmath>
#include <stdexcept>

using namespace std;

TimeSeriesDataset::TimeSeriesDataset()
    : TimeSeriesDataset(true, true) {}

TimeSeriesDataset::TimeSeriesDataset(bool znorm, bool train)
    : znormalize(znorm), isTrain(train), maxLength(0), numberOfSamples(0) {
    seriesStartIndices.push_back(0);
}


void TimeSeriesDataset::addTimeSeries(const vector<double>& series, int label) {
    if (series.empty()) return;
    data.insert(data.end(), series.begin(), series.end());
    labels.push_back(label);
    numberOfSamples = labels.size();


    if (series.size() > maxLength) {
        maxLength = series.size();
    }
    seriesStartIndices.push_back(data.size());
}

vector<double> TimeSeriesDataset::getSeries(int index) const {
    if (index < 0 || index >= numberOfSamples) {
        return {};
    }

    int start = seriesStartIndices[index];
    int end = seriesStartIndices[index + 1];

    return vector<double>(data.begin() + start, data.begin() + end);
}


double TimeSeriesDataset::calculateMean(const vector<double>& series) {
    if (series.empty()) return 0.0;
    double sum = std::accumulate(series.begin(), series.end(), 0.0);
    return sum / series.size();
}

double TimeSeriesDataset::calculateStdDev(const vector<double>& series, double mean) {
    if (series.size() < 2) return 0.0;

    double sq_sum = 0.0;
    for (double val : series) {
        double diff = val - mean;
        sq_sum += diff * diff;
    }
    return sqrt(sq_sum / series.size());
}


void TimeSeriesDataset::normalize() {
    if (!znormalize) return;

    for (int i = 0; i < numberOfSamples; ++i) {
        int start = seriesStartIndices[i];
        int end = seriesStartIndices[i+1];

        auto beginIt = data.begin() + start;
        auto endIt = data.begin() + end;

        double sum = std::accumulate(beginIt, endIt, 0.0);
        double count = (double)(end - start);
        double mu = sum / count;

        double sq_sum = 0.0;
        for (auto it = beginIt; it != endIt; ++it) {
            double diff = *it - mu;
            sq_sum += diff * diff;
        }
        double sigma = sqrt(sq_sum / count);

        if (sigma > 1e-9) {
            std::transform(beginIt, endIt, beginIt, [mu, sigma](double val) {
                return (val - mu) / sigma;
            });
        }
    }
    cout << "Normalisation Z-score terminée." << endl;
}