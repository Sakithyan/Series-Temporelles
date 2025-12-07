//
// Created by sraga on 24/11/2025.
//

#ifndef TIMESERIESGENERATOR_H
#define TIMESERIESGENERATOR_H
#include <vector>
using namespace std;
#include <string>
#include <iostream>


class TimeSeriesGenerator {
protected:
    int seed;

public:
    TimeSeriesGenerator();
    TimeSeriesGenerator(int seed);
    virtual ~TimeSeriesGenerator()=default;
    virtual vector<double> generateTimeSeries(int size)=0;
    static void printTimeSeries(const vector<double>& series);
};
#endif
