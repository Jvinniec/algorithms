import os
import sys
sys.path.append(os.path.dirname(os.path.abspath(__file__)) + '/../')
from sort_algo import sort_algo


class quick_sort(sort_algo):
    """ 
    Implements 'Quick Sort' sorting algorithm. Call with:
    ```
        sorted_arr = quick_sort().sort(arr)
    ```
    """

    def __init__(self):
        """ Initialize class
        """
        super(quick_sort, self).__init__()
        

    def sort(self, arr):
        """ Python implementation of Quick Sort algorithm

        Parameters
        ----------
        arr : array
            Python list of sortable objects

        Returns
        -------
        Sorted Python list
        """
        # Create a copy of the input array
        ret = arr.copy()

        # Sort the copy
        self._sort(ret, 0, len(ret)-1)

        return ret
        

    def _sort(self, ret, start, stop):
        """ Internal method for sorting `ret` in place

        Parameters
        ----------
        ret : array
            Python array object to be sorted
        start : int
            Index to start from for sorting
        stop : int
            Index to stop at for sorting
        """
        # Get the length
        size = stop - start + 1
        
        # Only process if the array is sizeable
        if size > 1:
            left  = start + 1
            right = stop

            # Cache the pivot value
            pivot = ret[start]

            while right >= left:

                # Move the left index
                while (left <= right) and (ret[left] < pivot):
                    left += 1

                # Move the right index
                while (ret[right] >= pivot) and (right >= left):
                    right -= 1

                if left < right:
                    # Swap the left and right
                    tmp = ret[right]
                    ret[right] = ret[left]
                    ret[left]  = tmp

            # Swap the pivot to this position
            if start != right:
                ret[start] = ret[right]
                ret[right] = pivot

            # Sort values on left/right of pivot
            self._sort(ret, start, right-1)
            self._sort(ret, left, stop)

        return
