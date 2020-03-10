

import os
import sys
sys.path.append(os.path.dirname(os.path.abspath(__file__)) + '/../')

from sort_algo import sort_algo

class selection_sort(sort_algo):
    """ 
    Implements 'Selection Sort' sorting algorithm. Call with:
    ```
        sorted_arr = selection_sort().sort(arr)
    ```
    """

    def __init__(self):
        """ Initialize class
        """
        super(selection_sort, self).__init__()
        

    def sort(self, arr):
        """ Python implementation of Selection Sort algorithm

        Parameters
        ----------
        arr : array
            Python list of sortable objects

        Returns
        -------
        Sorted Python list
        """
        # Get length of the array
        len_arr = len(arr)

        # Loop through the array
        for i in range(len_arr-1):
            # Current index to swap to
            cur_ind = len_arr-1-i

            # Find the maximum in the range 0,len_arr-i
            max_val  = arr[0]
            max_indx = 0
            for j in range(1,cur_ind+1):
                if arr[j] > max_val:
                    max_val  = arr[j]
                    max_indx = j
                
            # Now swap the value with the current end
            if max_indx != cur_ind:
                tmp = arr[max_indx]
                arr[max_indx] = arr[cur_ind]
                arr[cur_ind] = tmp
        
        return arr
