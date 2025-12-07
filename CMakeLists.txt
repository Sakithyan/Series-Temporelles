cmake_minimum_required(VERSION 4.0)
project(TD5_SeriesTemporelles)

set(CMAKE_CXX_STANDARD 20)

add_executable(TD5_SeriesTemporelles main.cpp
        TimeSeriesGenerator.cpp
        TimeSeriesGenerator.h
        GaussianGenerator.cpp
        GaussianGenerator.h
        StepGenerator.cpp
        StepGenerator.h
        SinWaveGenerator.cpp
        SinWaveGenerator.h
        TimeSeriesDataset.cpp
        TimeSeriesDataset.h
        DistanceMetrics.cpp
        DistanceMetrics.h
        KNN.cpp
        KNN.h)
