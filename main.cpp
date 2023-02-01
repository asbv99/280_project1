//  main.cpp
//  p1-stats
//
//  Created by Anna SanBartolome on 1/10/18.
//  Copyright © 2018 Anna San Bartolome. All rights reserved.
//

//#include <stdio.h>

#include "stats.h"
#include "p1_library.h"
#include <iostream>
using namespace std;

int main() {

    string filename;
    string column_name;
    
    // Ask the user for the name of the file and the name of the column that will be used in this program.
    cout << "enter a filename" << endl;
    cin >> filename;
    
    cout << "enter a column name" << endl;
    cin >> column_name;
    
    cout << "reading column " << column_name << " from " << filename << endl;
    
    // Extract the column from the file given by the user and create a vector from the values found in the column.
    vector<double> column = extract_column(filename, column_name);
    
    
    // Output all information about the values found in the specific column that was extracted from the file given to the program through the use of functions found in stats.cpp.
    cout << "Summary (value: frequency)" << endl;
    
    vector<vector<double> > S = summarize(column);
        for(int i=0; i < S.size(); ++i) {
        cout << S.at(i).at(0) << ": " << S.at(i).at(1) << endl;
    }
    
    cout << endl;
    cout << "count = " << count(column) << endl;
    cout << "sum = " << sum(column) << endl;
    cout << "mean = " << mean(column) << endl;
    cout << "stdev = " << stdev(column) << endl;
    cout << "median = " << median(column) << endl;
    cout << "mode = " << mode(column) << endl;
    cout << "min = " << min(column) << endl;
    cout << "max = " << max(column) << endl;
    cout << "  0th percentile = " << percentile(column,0) << endl;
    cout << " 25th percentile = " << percentile(column,0.25) << endl;
    cout << " 50th percentile = " << percentile(column,0.5) << endl;
    cout << " 75th percentile = " << percentile(column,0.75) << endl;
    cout << "100th percentile = " << percentile(column,1.0) << endl;
    
}













