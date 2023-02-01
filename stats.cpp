//  stats.cpp
//  p1-stats
//
//  Created by Anna SanBartolome on 1/10/18.
//  Copyright © 2018 Anna San Bartolome. All rights reserved.

//  #include <stdio.h>

#include "stats.h"
#include <cassert>
#include <vector>
#include "p1_library.h"
#include <cmath>

using namespace std;

// FUNCTION #1: SUMMARIZE
// Created 3 vectors and one vector of vector. A vector for value, frequency, and vec. Then, stored each corresponding value and its frequency in vec as a pair to then store that pair ({val,freq}) into the vector of vectors.
vector<vector<double> > summarize(vector<double> v) {
//    assert(false);
    sort(v);
    vector<double> value;
    vector<double> frequency;
    vector<double> vec;
    vector<vector<double> > summarize;

    int start = 0;
    double times = 1;

    for(int i=0; i < v.size(); ++i) {
        if(v.at(i) == v.at(start)) {
            if(i==0) {
                times = 1;
            }
            else{
                times = times + 1;
            }
        }
        else if(v.at(i) != v.at(start)) {
            value.push_back(v.at(start));
            frequency.push_back(times);
            times=1;
        }
        start = i;
    }
    frequency.push_back(times);
    value.push_back(v.at(start));
    
    for(int i=0; i < value.size(); ++i) {
        vec.push_back(value.at(i));
        vec.push_back(frequency.at(i));
        summarize.push_back(vec);
        vec.clear();
    }
    return summarize;
}

// FUNCTION #2: COUNT
// Took the size of the given vector to find the number of values that were present in it.
int count(vector<double> v) {
//    assert(false);
    int count = v.size();
    return count;
}

// FUNCTION #3: SUM
// Made a for loop to go through each place of the vector and find its value. Each value is then added to the variable sum.
double sum(vector<double> v) {
//  assert(false);
    double sum = 0;
    for(int i=0; i < v.size(); ++i) {
            sum = v.at(i) + sum;
    }
    return sum;
}

// FUNCTION #4: MEAN
// Sum of all values found in the vector using the sum function created previously and then dividing this sum by the size of the given vector.
double mean(vector<double> v) {
//  assert(false);
    double sums = sum(v);
    double mean = sums/v.size();
    return mean;
}

// FUNCTION #5: MEDIAN
// Sorted the given vector from least to greatest and then found the middle spot of the vector by dividing the size of the vector by 2. if the size of the vector was an even number then we would take the average of the two middle values to find the median. If the size of the vector is an odd number then the value of the middle spot is taken to be the median.
double median(vector<double> v) {
//  assert(false);
    sort(v);
    double median;
    double location = v.size()/2;
    int locationI = v.size()/2;

    if(v.size() % 2 == 0){  //If size is even
        median = (v.at(location) + v.at(location-1))/2;
    }
    if(v.size() % 2 != 0){
        median = v.at(locationI);
    }
    return median;
}

// FUNCTION #6: MODE
// Sort the vector given from least to greatest. Created a for loop to go through each value in the vector and check how many times each value appears (frequency). This frequency value is pushed back into a vector named compare every time the next value of the given vector is different from its previous number. A vector of all frequencies for each value in the given vector is created. Then, this vector is ordered from least to greatest and the largest frequency is found as it is the last value in the vector. This value is then found in the unsorted copy of the 'compare' vector. A for loop is created to find the location of the largest frequency value. Then, in the 'compare' vector all of the frequencies are summed up until that frequency value to then find the location of the most frequent value in the given vector.
double mode(vector<double> v) {
//  assert(false);
    sort(v);
    vector<double> compare;
    double sum = 0;
    int start = 0;
    double times = 1;
    double numTimesL = 0;

    for(int i=0; i < v.size(); ++i) {
        if(v.at(i) == v.at(start)) {
            times = times + 1;
        }
        if(v.at(i) != v.at(start)) {
            compare.push_back(times);
            times = 1;
        }
        start = i;
    }

    vector<double> compare_copy = compare;
    sort(compare);
    double numTimes = compare.at(compare.size()-1);
    for(int i = 0; i < compare_copy.size(); ++i) {
        if(compare_copy.at(i) == numTimes) {
            numTimesL = i;
        }
    }
    
    for (int i = 0; i < numTimesL; ++i) {
        sum = compare.at(i) + sum;
    }
    double mode = v.at(sum);
    return mode;
}

// FUNCTION #7: MIN
// Sort the given vector and take the first value of the vector to be the min or the smallest value.
double min(vector<double> v) {
 //   assert(false);
    sort(v);
    double min = v.at(0);
    return min;
}

// FUNCTION #8: MAX
// Sort the given vector and find the greatest value by locating the last value of the sorted vector.
double max(vector<double> v) {
//    assert(false);
    sort(v);
    double max = v.at(v.size()-1);
    return max;
}

// FUNCTION #9: STANDARD DEVIATION
// Take the standard deviation of all the values found in the given vector by taking the sum of each the square of each value subtracted by the overall mean. This sum was found by creating a for loop. Then, the square root of the sum divided by the size of the vector - 1 is taken.
double stdev(vector<double> v) {
//    assert(false);
    double sumsqr = 0;
    double means = mean(v);
    for(int i=0; i < v.size(); ++i) {
        sumsqr = pow((v.at(i) - means),2) + sumsqr;
    }
    double stdev = sqrt(sumsqr/(v.size()-1));
    return stdev;
}

// FUNCTION #10: PERCENTILE
// The percentile is calculated by sorting the vector and then breaking up the decimal value found from multiplying the given p value times the size of the given vector - 1. this value is then added + 1. The number to the left of the decimal point and the numbers to the right of the decimal point are found and stored into differeent variables, as each component will be then used in the percentile equation. 
double percentile(vector<double> v, double p) {
//    assert(false);
    sort(v);
    double rank = p*(v.size()-1)+1;
    int k = rank;
    double dec = rank-k;
    if(p == 1) {
        return v.at(v.size()-1);
    }
    double percentile = v.at(k-1) + dec*(v.at(k)-v.at(k-1));    
    return percentile;
    
}







