
class sort_algo:
    """ Base class for sorting algorithms
    """


    def __init__(self):
        """ Initialize sorting algorithm
        """
        pass


    def sort(self, arr):
        """ Python implementation of Sort algorithm

        Parameters
        ----------
        `arr` : array
            Python list of sortable objects

        Returns
        -------
        Input `arr` or Sorted Python list in inherited implementations
        """
        return arr

    
    def Test(self, arr, expected):
        """ Method for testing a given sorting algorithm

        Parameters
        ----------
        `arr` : list
            Python list or array like object
        `expected` : list
            Python array like object representing the sorted version of `arr`

        Returns
        -------
        True if sorting method works, otherwise false
        """
        # Make sure inputs are valid
        if len(arr) != len(expected):
            raise ValueError(f'arr length {len(arr)} not equal to expected \
                               length {len(expected)}')

        # Actually sort the array
        sorted = self.sort(arr)

        # Make sure the elements match
        is_sorted = True
        for i,val in enumerate(sorted):
            if val != expected[i]:
                is_sorted = False
                break
        
        return is_sorted


# Import the sorting algorithms
from bubble_sort.bubble_sort       import bubble_sort
from heap_sort.heap_sort           import heap_sort
from insertion_sort.insertion_sort import insertion_sort
from merge_sort.merge_sort         import merge_sort
from selection_sort.selection_sort import selection_sort
from quick_sort.quick_sort         import quick_sort
