/***************************************************************************
 *  test.cpp: JVC Algorithms                                               *
 * ----------------------------------------------------------------------- *
 *  Copyright © 2020 JCardenzana                                           *
 * ----------------------------------------------------------------------- *
 *                                                                         *
 *  This program is free software: you can redistribute it and/or modify   *
 *  it under the terms of the GNU General Public License as published by   *
 *  the Free Software Foundation, either version 3 of the License, or      *
 *  (at your option) any later version.                                    *
 *                                                                         *
 *  This program is distributed in the hope that it will be useful,        *
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of         *
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the          *
 *  GNU General Public License for more details.                           *
 *                                                                         *
 *  You should have received a copy of the GNU General Public License      *
 *  along with this program.  If not, see <http://www.gnu.org/licenses/>.  *
 *                                                                         *
 ***************************************************************************/

/* @file test.cpp
 * Runs tests on c++ sorting algorithms
 * 
 * Compile and run with the following command:
 * ```
 * clang++ -I./ -I../bubble_sort -I../insertion_sort -I../merge_sort test.cpp \
 *         -I../heap_sort -I../selection_sort -I../../../data_structures/heap_datastruct \
 *         -I../quick_sort -o test_cpp && ./test_cpp
 * ```
 */

#include <iostream>
#include <random>
#include <algorithm>

#include "bubble_sort.hpp"
#include "heap_sort.hpp"
#include "insertion_sort.hpp"
#include "merge_sort.hpp"
#include "selection_sort.hpp"
#include "quick_sort.hpp"


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
bool test_sort(void) 
{
    // Get the test data
    std::vector<int> arr = test_data(1000);

    // Get the expected output using builtin c++ features
    std::vector<int> expect = arr;
    std::sort(expect.begin(), expect.end());

    // Print out status as we go
    std::cout << "TESTING: Sorting algorithms:" << std::endl;
    std::cout << "-----------+---------+-----------" << std::endl;
    std::cout << " Algo      | sorted? | time (sec)" << std::endl;
    std::cout << "-----------+---------+-----------" << std::endl;

    // Bubble sort
    std::vector<int> bubble = bubble_sort().sort(arr);
    bool bubble_success = test_equal(bubble, expect);
    std::cout << " Bubble    | " << bubble_success << std::endl;

    // Heap sort
    std::vector<int> heap = heap_sort().sort(arr);
    bool heap_success = test_equal(heap, expect);
    std::cout << " Heap      | " << heap_success << std::endl;

    // Insertion sort
    std::vector<int> insertion = insertion_sort().sort(arr);
    bool insertion_success = test_equal(insertion, expect);
    std::cout << " Insertion | " << insertion_success << std::endl;

    // Merge sort
    std::vector<int> merge = merge_sort().sort(arr);
    bool merge_success = test_equal(merge, expect);
    std::cout << " Merge     | " << merge_success << std::endl;

    // Quick sort
    std::vector<int> quick = quick_sort().sort(arr);
    bool quick_success = test_equal(quick, expect);
    std::cout << " Quick     | " << quick_success << std::endl;

    // Selection sort
    std::vector<int> selection = selection_sort().sort(arr);
    bool selection_success = test_equal(selection, expect);
    std::cout << " Selection | " << selection_success << std::endl;

    // Get the overall status
    bool success = true;
    if (!bubble_success || !heap_success || !insertion_success ||
        !merge_success || !quick_success || !selection_success) {
        success = false;
    }

    return success;
}


/********************************************************************//**
 * Main method
 ************************************************************************/
int main() {
    // Instigate the testing procedure
    bool success = test_sort();

    return int(!success);
}