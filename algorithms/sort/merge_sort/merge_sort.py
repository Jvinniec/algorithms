
import os
import sys
sys.path.append(os.path.dirname(os.path.abspath(__file__)) + '/../')

from sort_algo import sort_algo

class merge_sort(sort_algo):
    """ 
    Implements 'Merge Sort' sorting algorithm. Call with:
    ```
        sorted_arr = merge_sort().sort(arr)
    ```
    """

    def __init__(self):
        """ Initialize merge sort class
        """
        super(merge_sort, self).__init__()
        

    def sort(self, arr, start=0, stop=-1):
        """ Python implementation of Merge Sort algorithm

        Parameters
        ----------
        arr : array
            Python list of sortable objects

        Returns
        -------
        Sorted Python list
        """
        # Create a copy to be returned
        if start == 0 and stop == -1:
            ret = arr.copy()
        else:
            ret = arr
        
        # If this is the first pass, then we want to sort all the elements
        if stop == -1:
            stop = len(ret)
        
        # Get the size of the passed array
        size = stop - start

        # Handle based on the size
        if size == 2:
            if ret[start] > ret[start+1]:
                tmp = ret[start]
                ret[start] = ret[start+1]
                ret[start+1] = tmp
        elif size > 2:
            # Split the array in half and sort
            mid  = start+int(size/2)
            cpy_arr1 = self.sort(ret, start, mid)[start:mid].copy()
            self.sort(ret, mid, stop)

            # Merge the two sorted arrays
            ind1 = 0
            ind2 = mid
            len_cpy = mid-start

            # Append the entries to the return list
            for i in range(start, stop):

                # We can consider being all done once we've inserted the 
                # entries from the left
                if ind1 == len_cpy:
                    break
                elif (ind2 == stop) or (ret[ind2] > cpy_arr1[ind1]):
                    ret[i] = cpy_arr1[ind1]
                    ind1 += 1
                # Check if we're finished adding first section values
                else:
                    ret[i] = ret[ind2]
                    ind2 += 1
                
        return ret