import os
import sys
sys.path.append(os.path.dirname(os.path.abspath(__file__)) + '/../../../')
# Import data structures
import data_structures as ds

# Import sort_algo base class
sys.path.append(os.path.dirname(os.path.abspath(__file__)) + '/../')
from sort_algo import sort_algo


class heap_sort(sort_algo):
    """ 
    Implements 'Heap Sort' sorting algorithm. Call with:
    ```
        sorted_arr = heap_sort().sort(arr)
    ```
    """

    def __init__(self):
        """ Initialize class
        """
        super(heap_sort, self).__init__()
        

    def sort(self, arr):
        """ Python implementation of Heap Sort algorithm. Note that this
        algorithm makes use of the Heap data structure.

        Parameters
        ----------
        arr : array
            Python list of sortable objects

        Returns
        -------
        Sorted Python list
        """
        # Create a heap data structure
        heap_arr = ds.BinaryHeap(arr)

        # Loop through the values
        size = len(arr)
        ret  = [0] * size
        for i in range(size):
            # Remove the root value and put it into the array
            ret[size-1-i] = heap_arr.popMax()

        return ret
