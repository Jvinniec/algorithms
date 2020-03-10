# Make sure the sorting directories are findable
import os
import sys
sys.path.append(os.path.dirname(os.path.abspath(__file__)) + '/../')
import numpy as np

# For generating random lists
from random import randint

# Import algorithms
import sort_algo as sorter

def test_data():
    """ Generates a sample of random numbers and the expected sorted array
    """
    entries = 100
    vals = np.zeros(entries)
    for i in range(entries):
        vals[i] = randint(-1000,1000)

    return vals, np.sort(vals)


def is_sorted(arr, expected):
    """ Test if array is sorted
    Parameters
    ----------
    arr : list
        list of values
    Returns
    -------
    Boolean if list is sorted
    """
    is_sorted = True
    
    # Loop over all entries
    for i in range(len(arr)):
        # Check if value is the expected value
        if arr[i] != expected[i]:
            is_sorted = False
            break
    
    return is_sorted


if __name__ == '__main__':

    sort_algos = {'Bubble'    : sorter.bubble_sort,
                  'Selection' : sorter.selection_sort,
                  'Insertion' : sorter.insertion_sort,
                  'Heap'      : sorter.heap_sort,
                  'Merge'     : sorter.merge_sort()}

    print()
    print(f' Algo      | sorted?')
    print(f'-----------+---------')

    # Loop over all algorithms
    for name,algo in sort_algos.items():
        # Generate random unsorted array
        test_arr, expected_arr = test_data()
        
        # Attemp to sort
        sorted_arr = algo.sort(test_arr)
        
        # Print success/failure
        print(f' {name:9s} | {is_sorted(sorted_arr,expected_arr)}')
        
    print()
