//
// Created by sraga on 24/11/2025.
//

#include "TimeSeriesGenerator.h"
#include <iostream>
#include <iomanip>

using namespace std;

TimeSeriesGenerator::TimeSeriesGenerator() : seed(42) {
}
TimeSeriesGenerator::TimeSeriesGenerator(int s) : seed(s) {

}

void TimeSeriesGenerator::printTimeSeries(const vector<double>& series) {
    cout << "Time Series (Size: " << series.size() << ")" << endl;

    for (size_t i = 0; i < series.size(); ++i) {
        cout << "[" << i << "]: " << series[i];
        if (i < series.size() - 1) {
            cout << ", ";
        }
    }
    cout << endl;
    cout << "-------------------" << endl;
}