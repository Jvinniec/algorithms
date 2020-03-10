
import os
import sys
sys.path.append(os.path.dirname(os.path.abspath(__file__)) + '/../')
from sort_algo import sort_algo

class bubble_sort(sort_algo):
    """ 
    Implements 'Bubble Sort' sorting algorithm. Call with:
    ```
        sorted_arr = bubble_sort().sort(arr)
    ```
    """

    def __init__(self):
        """ Initialize class
        """
        super(bubble_sort, self).__init__()
        

    def sort(self, arr):
        """ Python implementation of Bubble Sort algorithm

        Parameters
        ----------
        arr : array
            Python list of sortable objects

        Returns
        -------
        Sorted Python list
        """
        # Get an estimate of the length
        len_obj = len(arr)

        # Create a temporary storage object
        tmp_obj = None

        # Loop over all the entries in the list
        for i in range(len_obj-1):
            for j in range(len_obj-i-1):
                if arr[j] > arr[j+1]:
                    
                    # Swap the values
                    tmp_obj  = arr[j]
                    arr[j]   = arr[j+1]
                    arr[j+1] = tmp_obj

        return arr
