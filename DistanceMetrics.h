//
// Created by sraga on 02/12/2025.
//

#ifndef DISTANCEMETRICS_H
#define DISTANCEMETRICS_H

#include <vector>
#include <cmath>
#include <stdexcept>

using namespace std;

class DistanceMetrics {
public:
    static double euclidean_distance(const vector<double>& series1,
                                     const vector<double>& series2);

    // Question 7 : Dynamic Time Warping
    static double dtw(const vector<double>& series1,
                               const vector<double>& series2);
};

#endif