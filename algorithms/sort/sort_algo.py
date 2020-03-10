
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
        arr : array
            Python list of sortable objects

        Returns
        -------
        Sorted Python list
        """
        return arr


# Import the sorting algorithms
from bubble_sort.bubble_sort       import bubble_sort
from selection_sort.selection_sort import selection_sort
from insertion_sort import insertion_sort
from merge_sort.merge_sort         import merge_sort
from heap_sort.heap_sort           import heap_sort
