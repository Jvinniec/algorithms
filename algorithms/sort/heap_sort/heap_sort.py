import os
import sys
sys.path.append(os.path.dirname(os.path.abspath(__file__)) + '/../../../')

# Import data structures
import data_structures as ds

def sort(arr):
    """ Use the Heap Sort algorithm
    """
    # Create a heap data structure
    heap_arr = ds.heap_datastruct(arr)

    # Loop through the values
    size = len(arr)
    for i in range(size):
        # Remove the root value and put it into the array
        arr[size-1-i] = heap_arr.popMax()

    return arr
