//
// Created by sraga on 07/12/2025.
//

#ifndef KNN_H
#define KNN_H
#include "TimeSeriesDataset.h"
#include <string>
#include <vector>
using namespace std;



class KNN {
private:
    int k;
    string similarity_measure;

public:
    KNN(int k, string similarity_measure);
    double evaluate(const TimeSeriesDataset& trainData,
                    const TimeSeriesDataset& testData,
                    const vector<int>& ground_truth);

    int predict(const vector<double>& querySeries, const TimeSeriesDataset& trainData);
};

#endif