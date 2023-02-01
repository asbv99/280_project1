/* stats_tests.cpp
 *
 * Unit tests for the simple statistics library
 *
 * EECS 280 Project 1
 *
 * Protip #1: Write tests for the functions BEFORE you implement them!  For
 * example, write tests for median() first, and then write median().  It sounds
 * like a pain, but it helps make sure that you are never under the illusion
 * that your code works when it's actually full of bugs.
 *
 * Protip #2: Instead of putting all your tests in main(),  put each test case
 * in a function!
 */

#include "stats.h"
#include <iostream>
#include <cassert>
#include <vector>
#include <cmath>
using namespace std;

    void test_sum_small_data_set();
 // Add prototypes for you test functions here.
    void test_summarize_data_set();
    void test_summarize_more_data_set();
    void test_summarize_edge_data_set();
    void test_count_data_set();
    void test_count_edge_data_set();
    void test_sum_negative_decimal_data_set();
    void test_mean_small_data_set();
    void test_mean_decimal_data_set();
    void test_median_decimal_data_set();
    void test_median_even_spots_data_set();
    void test_mode_decimal_data_set();
    void test_mode_negative_data_set();
    void test_mode_more_data_set();
    void test_min_data_set();
    void test_max_data_set();
    void test_stdev_data_set();
    void test_percentile_data_set();
    void test_percentile_edge_data_set();


int main()
{
    test_sum_small_data_set();
 // Call your test functions here
    test_summarize_data_set();                //PASS
    test_summarize_more_data_set();           //PASS
    test_summarize_edge_data_set();           //PASS
    test_count_data_set();                    //PASS
    test_count_edge_data_set();               //PASS
    test_sum_negative_decimal_data_set();     //PASS
    test_mean_small_data_set();               //PASS
    test_mean_decimal_data_set();             //PASS
    test_median_decimal_data_set();           //PASS
    test_median_even_spots_data_set();        //PASS
    test_mode_decimal_data_set();             //PASS
    test_mode_negative_data_set();            //PASS
    test_mode_more_data_set();                //PASS
    test_min_data_set();                      //PASS
    test_max_data_set();                      //PASS
    test_stdev_data_set();                    //PASS
    test_percentile_data_set();               //PASS
    test_percentile_edge_data_set();          //PASS
    
  return 0;
}


// Test case functions for each function written in stats.cpp
// Test Case Function: SUM #1
void test_sum_small_data_set()
{
  cout << "test_sum_small_data_set" << endl;

  vector<double> data;
  data.push_back(1);
  data.push_back(2);
  data.push_back(3);

  assert(sum(data) == 6);

  cout << "PASS!" << endl;
}

// TEST CASES CREATED FOR EVERY FUNCTION FOUND IN STATS.CPP
// Test Case Function: SUMMARIZE #1
void test_summarize_data_set()
{
    cout << "test_summarize_data_set" << endl;

    vector<double> data;
    data.push_back(1.1);
    data.push_back(2);
    data.push_back(1.1);

    vector<vector<double> > summarizeB = {{1.1,2},{2,1}};
    assert(summarizeB == summarize(data));

    cout << "PASS!" << endl;
}


// Test Case Function: SUMMARIZE #2
void test_summarize_more_data_set()
{
    cout << "test_summarize_more_data_set" << endl;

    vector<double> data;
    data.push_back(4);
    data.push_back(4);
    data.push_back(2);
    data.push_back(8);
    data.push_back(2);
    
    vector<vector<double> > summarizeB = {{2,2},{4,2},{8,1}};
    assert(summarizeB == summarize(data));
    
    cout << "PASS!" << endl;
}

// Test Case Function: SUMMARIZE #3
void test_summarize_edge_data_set()
{
    cout << "test_summarize_edge_data_set" << endl;
    
    vector<double> data;
    data.push_back(-8);
    data.push_back(-176.8);
    data.push_back(0);
    data.push_back(189246.1);
    data.push_back(189246.1);
    data.push_back(1);
    data.push_back(-8);
    data.push_back(0.8);
    
    vector<vector<double> > summarizeB = {{-176.8,1},{-8,2},{0,1},{.8,1},{1,1},{189246.1,2}};
    assert(summarizeB == summarize(data));
    
    cout << "PASS!" << endl;
}


// Test Case Function: COUNT #1
void test_count_data_set()
{
    cout << "test_count_data_set" << endl;
    
    vector<double> data;
    data.push_back(-1);
    data.push_back(3);
    data.push_back(9);
    data.push_back(0);
    
    assert(count(data) == 4);
    
    cout << "PASS!" << endl;
}


// Test Case Function: COUNT #2
void test_count_edge_data_set()
{
    cout << "test_count_edge_data_set" << endl;
    
    vector<double> data;
    data.push_back(0);
    data.push_back(1);
    data.push_back(2497);
    data.push_back(199);
    data.push_back(13867);
    data.push_back(13981);
    data.push_back(9);
    data.push_back(872169);
    data.push_back(-19387);
    data.push_back(-1317699);
    
    assert(count(data) == 10);
    
    cout << "PASS!" << endl;
}


// Test Case Function: SUM #2
void test_sum_negative_decimal_data_set()
{
    cout << "test_sum_negative_decimal_data_set" << endl;

    vector<double> data;
    data.push_back(5);
    data.push_back(-10);
    data.push_back(9);
    data.push_back(8.2);

    assert(sum(data) == 12.2);

    cout << "PASS!" << endl;
}


// Test Case Function: MEAN #1
void test_mean_small_data_set()
{
    cout << "test_mean_small_data_set" << endl;
    
    vector<double> data;
    data.push_back(0);
    data.push_back(-1);
    data.push_back(2);
    data.push_back(-3);
    
    assert(mean(data) == -0.5);
    
    cout << "PASS!" << endl;
}


// Test Case Function: MEAN #2
void test_mean_decimal_data_set()
{
    cout << "test_mean_decimal_data_set" << endl;

    vector<double> data;
    data.push_back(0.5);
    data.push_back(-1.8);
    data.push_back(2.0);
    data.push_back(-3);

    assert(mean(data) == -0.575);

    cout << "PASS!" << endl;
}


// Test Case Function: MEDIAN #1
void test_median_decimal_data_set()
{
    cout << "test_median_decimal_data_set" << endl;
    
    vector<double> data;
    data.push_back(100.56);
    data.push_back(-567.9);
    data.push_back(2.0);
    data.push_back(-3);
    data.push_back(0);
    
    assert(median(data) == 0);
    
    cout << "PASS!" << endl;
}


// Test Case Function: MEDIAN #2
void test_median_even_spots_data_set()
{
    cout << "test_median_even_spots_data_set" << endl;

    vector<double> data;
    data.push_back(100.56);
    data.push_back(-567.9);
    data.push_back(2.0);
    data.push_back(-.75);

    assert(median(data) == 0.625);

    cout << "PASS!" << endl;
}


// Test Case Function: MODE #1
void test_mode_decimal_data_set()
{
    cout << "test_mode_decimal_data_set" << endl;
    
    vector<double> data;
    data.push_back(3);
    data.push_back(0);
    data.push_back(9);
    data.push_back(2.0);
    data.push_back(2);
    
    assert(mode(data) == 2);
    
    cout << "PASS!" << endl;
}


// Test Case Function: MODE #2
void test_mode_negative_data_set()
{
    cout << "test_mode_negative_data_set" << endl;
    
    vector<double> data;
    data.push_back(-1);
    data.push_back(1);
    data.push_back(-5.70);
    data.push_back(2.0);
    data.push_back(2);
    data.push_back(-5.7);
    
    assert(mode(data) == -5.7);
    
    cout << "PASS!" << endl;
}


// Test Case Function: MODE #3
void test_mode_more_data_set()
{
    cout << "test_mode_more_data_set" << endl;
    
    vector<double> data;
    data.push_back(9);
    data.push_back(6);
    data.push_back(6);
    data.push_back(9);
    data.push_back(5);
    data.push_back(5);
    
    assert(mode(data) == 5);
    
    cout << "PASS!" << endl;
}


// Test Case Function: MIN #1
void test_min_data_set()
{
    cout << "test_min_data_set" << endl;
    
    vector<double> data;
    data.push_back(-500);
    data.push_back(0);
    data.push_back(-5.7);
    data.push_back(2.0);
    data.push_back(-67);
    data.push_back(5.7);
    
    assert(min(data) == -500);
    
    cout << "PASS!" << endl;
}


// Test Case Function: MAX #1
void test_max_data_set()
{
    cout << "test_max_data_set" << endl;
    
    vector<double> data;
    data.push_back(-507.7);
    data.push_back(0);
    data.push_back(1000);
    data.push_back(2.0);
    data.push_back(-67);
    data.push_back(5.7);
    
    assert(max(data) == 1000);
    
    cout << "PASS!" << endl;
}


// Test Case Function: STDEV #1
void test_stdev_data_set()
{
    cout << "test_stdev_data_set" << endl;

    vector<double> data;
    data.push_back(5);
    data.push_back(10);
    data.push_back(15);

    assert(stdev(data) == 5);

    cout << "PASS!" << endl;
}


// Test Case Function: PERCENTILE #1
void test_percentile_data_set()
{
    cout << "test_percentile_data_set" << endl;
    
    double p=.5;
    vector<double> data;
    data.push_back(1);
    data.push_back(2);
    data.push_back(3);
    
    assert(percentile(data,p) == 2);
    
    cout << "PASS!" << endl;
}


// Test Case Function: PERCENTILE #2
void test_percentile_edge_data_set()
{
    cout << "test_percentile_edge_data_set" << endl;
    
    double p=1;
    vector<double> data;
    data.push_back(1);
    data.push_back(2);
    data.push_back(3);
    
    assert(percentile(data,p) == 3);
    
    cout << "PASS!" << endl;
}

           
        
