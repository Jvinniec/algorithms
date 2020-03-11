import os
import sys
sys.path.append(os.path.dirname(os.path.abspath(__file__)) + '/../')
from sort_algo import sort_algo


class insertion_sort(sort_algo):
    """ 
    Implements 'Insertion Sort' sorting algorithm. Call with:
    ```
        sorted_arr = insertion_sort().sort(arr)
    ```
    """

    def __init__(self):
        """ Initialize class
        """
        super(insertion_sort, self).__init__()
        

    def sort(self, arr):
        """ Python implementation of Insertion Sort algorithm.

        Parameters
        ----------
        arr : array
            Python list of sortable objects

        Returns
        -------
        Sorted Python list
        """
        # Create copy to be sorted
        ret = arr.copy()

        # Get length of arr
        len_arr = len(ret)

        # Loop through all entries in the list
        for i in range(1, len_arr):
            # Get value at position we care about
            val_i = ret[i]

            # Loop through the previous values to see where to insert it
            for j in range(i-1,-1, -1):
                # If current value is larger, swap it
                if val_i < ret[j]:
                    ret[j+1] = ret[j]
                    if j == 0:
                        ret[0] = val_i
                else:
                    ret[j+1] = val_i
                    break

        return ret
