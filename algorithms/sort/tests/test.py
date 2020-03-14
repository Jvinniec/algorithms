# Make sure the sorting directories are findable
import os
import sys
sys.path.append(os.path.dirname(os.path.abspath(__file__)) + '/../')
import numpy as np
import timeit

# For generating random lists
from random import randint

# Import algorithms
import sort_algo as sorter

def test_data(entries):
    """ Generates a sample of random numbers and the expected sorted array
    """
    # Create an empty array to be filled
    vals = np.zeros(entries)
    for i in range(entries):
        vals[i] = randint(-1000,1000)

    return vals, np.sort(vals)


def print_status(name, success, time):
    """ Print the status of an algorithm
    """
    print(f' {name:9s} | {str(success):5s}   | {time:1.2e}')


def run_tests(timed_tests=100, arr_size=1000):
    """ Run tests on all Python sorting algorithm implementations
    """
    # Define the sorting algorithms to test
    sort_algos = {'Numpy'     : np,
                  'Bubble'    : sorter.bubble_sort(),
                  'Selection' : sorter.selection_sort(),
                  'Insertion' : sorter.insertion_sort(),
                  'Heap'      : sorter.heap_sort(),
                  'Merge'     : sorter.merge_sort(),
                  'Quick'     : sorter.quick_sort()}

    # Print some helpful text to tell us what's going on
    print('TESTING: Sorting algorithms:')
    print(f'-----------+---------+-----------')
    print(f' Algo      | sorted? | time (sec)')
    print(f'-----------+---------+-----------')

    # Loop over all algorithms
    for name,algo in sort_algos.items():
        # Generate random unsorted array
        test_arr, expected_arr = test_data(entries=arr_size)
        
        # Try to sort the array
        sorted_arr = algo.sort(test_arr)
        success = sorter.sort_algo().Test(sorted_arr, expected_arr)
        
        # If successfull test computation time of sorting algorithm
        time = 0
        if success:
            time = timeit.timeit('test_arr, expected=test_data(entries=arr_size); algo.sort(test_arr)', 
                                 globals={'algo':algo,'test_data':test_data,'arr_size':arr_size}, 
                                 number=timed_tests)
        
        # Print success/failure
        print_status(name, success, time)
    
    # Print a new line character
    print()


if __name__ == '__main__':
    run_tests()
    exit(0)