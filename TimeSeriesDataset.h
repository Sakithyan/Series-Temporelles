//
// Created by sraga on 02/12/2025.
//

#ifndef TIMESERIESDATASET_H
#define TIMESERIESDATASET_H

#include <vector>
#include <iostream>
#include <cmath>
#include <numeric>
#include <algorithm>

using namespace std;

class TimeSeriesDataset {
private:
    bool znormalize;
    bool isTrain;
    vector<double> data;
    vector<int> labels;
    int maxLength;
    int numberOfSamples;
    vector<int> seriesStartIndices;

public:
    TimeSeriesDataset();
    TimeSeriesDataset(bool znormalize=true, bool isTrain=true);

    void normalize();
    void addTimeSeries(const vector<double>& series, int label = 0);

    static double calculateMean(const vector<double>& series);
    static double calculateStdDev(const vector<double>& series,double mean);

    vector<double> getSeries(int index) const;

    const vector<double>& getData() const { return data; }
    const vector<int>& getLabels() const { return labels; }
    bool getZNormalize() const { return znormalize; }
    int getMaxLength() const { return maxLength; }
    int getNumberOfSamples() const { return numberOfSamples; }
};

#endif