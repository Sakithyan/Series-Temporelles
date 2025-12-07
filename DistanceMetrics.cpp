//
// Created by sraga on 02/12/2025.
//

#include "DistanceMetrics.h"
#include <stdexcept>
#include <cmath>
#include <numeric>
#include <algorithm>
using namespace std;

double DistanceMetrics::euclidean_distance(const vector<double>& series1,
                                           const vector<double>& series2) {

    int L = series1.size();
    if (L == 0) return 0.0;

    double squared_sum = 0.0;
    for (int i = 0; i < L; ++i) {
        double difference = series1[i] - series2[i];
        squared_sum += difference * difference;
    }
    return std::sqrt(squared_sum);
}

double DistanceMetrics::dtw(const vector<double>& series1, const vector<double>& series2) {
    int L1 = series1.size();
    int L2 = series2.size();
    if (L1 == 0 && L2 == 0) return 0.0;
    if (L1 == 0 || L2 == 0) return numeric_limits<double>::infinity();
    vector<vector<double>> D(L1 + 1, vector<double>(L2 + 1));
    const double INF = numeric_limits<double>::infinity();

    D[0][0] = 0.0;
    for (int i = 1; i <= L1; ++i) D[i][0] = INF;
    for (int j = 1; j <= L2; ++j) D[0][j] = INF;
    for (int i = 1; i <= L1; ++i) {
        for (int j = 1; j <= L2; ++j) {
            double dist = series1[i - 1] - series2[j - 1];
            double cost = dist * dist;
            // D[i, j-1] -> insert
            // D[i-1, j] -> delete
            // D[i-1, j-1] -> match/move

            double insertion = D[i][j - 1];
            double deletion = D[i - 1][j];
            double match = D[i - 1][j - 1];

            // D[i][j] = d + min(...)
            D[i][j] = cost + std::min({insertion, deletion, match});
        }
    }
    return sqrt(D[L1][L2]);
}