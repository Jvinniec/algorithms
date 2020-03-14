
#include <iostream>
#include <random>
#include <algorithm>

#include "bubble_sort.hpp"
#include "insertion_sort.hpp"
#include "merge_sort.hpp"


/********************************************************************//**
 * Generates a vector of random numbers
 * 
 * @param[in] entries       Number of entries to generate
 * @returns Vector of random integer values
 ************************************************************************/
std::vector<int> test_data(const int &entries)
{
    // Initialize the vector with values
    std::vector<int> vals(entries, 0.0);

    std::random_device dev;
    std::mt19937       rng(dev());
    std::uniform_int_distribution<std::mt19937::result_type> dist(-1000,1000);

    // Fill with random integers
    for (int& val : vals) {
        val = dist(rng);
    }

    return vals;
}


/********************************************************************//**
 * Test whether two vectors are equal
 * 
 * @param[in] arr1          First array
 * @param[in] arr2          Second array
 * @returns True if the two arrays are equal
 ************************************************************************/
bool test_equal(const std::vector<int> &arr1,
                const std::vector<int> &arr2) 
{
    // Track whether the arrays are equal
    bool is_equal = true;
    
    // Make sure the arrays are the same size
    if (arr1.size() != arr2.size()) {
        is_equal = false;
    } else {
        // Make sure all values are equal
        for (int i=0; i<arr1.size(); i++) {
            if (arr1[i] != arr2[i]) {
                is_equal = false;
                break;
            }
        }
    }

    return is_equal;
}


/********************************************************************//**
 * Test C++ implementations of various sorthing algorithms
 ************************************************************************/
void test_sort(void) 
{
    // Get the test data
    std::vector<int> arr = test_data(1000);

    // Get the expected output using builtin c++ features
    std::vector<int> expect = arr;
    std::sort(expect.begin(), expect.end());

    // Cache the success
    bool test_success = true;

    std::cout << "TESTING: Sorting algorithms:" << std::endl;
    std::cout << "-----------+---------+-----------" << std::endl;
    std::cout << " Algo      | sorted? | time (sec)" << std::endl;
    std::cout << "-----------+---------+-----------" << std::endl;

    // Bubble sort
    std::vector<int> bubble = bubble_sort().sort(arr);
    std::cout << " Bubble    | " << test_equal(bubble, expect) << std::endl;

    // TODO: Heap sort

    // Insertion sort
    std::vector<int> insertion = insertion_sort().sort(arr);
    std::cout << " Insertion | " << test_equal(insertion, expect) << std::endl;

    // Merge sort
    std::vector<int> merge = merge_sort().sort(arr);
    std::cout << " Merge     | " << test_equal(merge, expect) << std::endl;

    // TODO: Quick sort
    // TODO: Selection sort

    // for (auto& i : arr) std::cout << i << " ";
    // std::cout << std::endl;
    // for (auto& i : merge) std::cout << i << " ";
    // std::cout << std::endl;
    // for (auto& i : expect) std::cout << i << " ";
    // std::cout << std::endl;
    

    return ;
}


/********************************************************************//**
 * Main method
 ************************************************************************/
int main() {
    // Instigate the testing procedure
    bool success = true;
    
    // Try to test sorting algorithm
    test_sort();

    return 0;
}