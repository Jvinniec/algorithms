# Make sure the sorting directories are findable
import os
import sys
sys.path.append(os.path.dirname(os.path.abspath(__file__)))

# For generating random lists
from random import randint

# Import the sorting algorithms
from bubble_sort    import bubble_sort
from selection_sort import selection_sort
from insertion_sort import insertion_sort

def test_data():
    """ Generates a sample of random numbers
    """
    entries = 100
    vals = [0] * entries
    for i in range(entries):
        vals[i] = randint(-1000,1000)

    return vals


def is_sorted(arr):
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
    for i in range(len(arr)-1):
        # Check if value is less than next value
        if arr[i] > arr[i+1]:
            is_sorted = False
            break
    
    return is_sorted


if __name__ == '__main__':

    sort_algos = {'Bubble'    : bubble_sort,
                  'Selection' : selection_sort,
                  'Insertion' : insertion_sort}

    print()
    print(f' Algo      | sorted?')
    print(f'-----------+---------')

    # Loop over all algorithms
    for key,algo in sort_algos.items():
        # Generate random unsorted array
        test_arr = test_data()
        
        # Attemp to sort
        sorted_arr = algo.sort(test_arr)
        
        # Print success/failure
        print(f' {key:9s} | {is_sorted(sorted_arr)}')
        
    print()
