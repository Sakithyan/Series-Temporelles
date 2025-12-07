//
// Created by sraga on 07/12/2025.
//

#include "KNN.h"
#include "DistanceMetrics.h"
#include <algorithm>
#include <map>

using namespace std;


KNN::KNN(int k_val, string measure) : k(k_val), similarity_measure(measure) {}


struct Neighbor {
    double distance;
    int label;

    bool operator<(const Neighbor& other) const {
        return distance < other.distance;
    }
};


int KNN::predict(const vector<double>& querySeries, const TimeSeriesDataset& trainData) {
    vector<Neighbor> distances;

    int trainSamples = trainData.getNumberOfSamples();
    const vector<int>& trainLabels = trainData.getLabels();

    // 1. Calcul de toutes les distances
    for (int i = 0; i < trainSamples; ++i) {
        vector<double> trainSeries = trainData.getSeries(i);

        double dist = 0.0;
        if (similarity_measure == "dtw") {
            dist = DistanceMetrics::dtw(querySeries, trainSeries);
        } else {
            // Par défaut : distance euclidienne
            dist = DistanceMetrics::euclidean_distance(querySeries, trainSeries);
        }

        distances.push_back({dist, trainLabels[i]});
    }

    sort(distances.begin(), distances.end());


    map<int, int> classVotes;
    for (int i = 0; i < k && i < distances.size(); ++i) {
        int label = distances[i].label;
        classVotes[label]++;
    }
    int bestLabel = -1;
    int maxVotes = -1;

    for (auto const& [label, count] : classVotes) {
        if (count > maxVotes) {
            maxVotes = count;
            bestLabel = label;
        }
    }

    return bestLabel;
}

double KNN::evaluate(const TimeSeriesDataset& trainData,
                     const TimeSeriesDataset& testData,
                     const vector<int>& ground_truth) {

    int correct = 0;
    int testSamples = testData.getNumberOfSamples();
    for (int i = 0; i < testSamples; ++i) {
        vector<double> testSeries = testData.getSeries(i);

        int prediction = predict(testSeries, trainData);

        if (prediction == ground_truth[i]) {
            correct++;
        }
    }

    if (testSamples == 0) return 0.0;

    return (double)correct / testSamples;
}