
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
        

    def sort(self, arr):
        """ Python implementation of Merge Sort algorithm

        Parameters
        ----------
        arr : array
            Python list of sortable objects

        Returns
        -------
        Sorted Python list
        """
        # Define a return object (will be a sorted array)
        ret = []

        # Get the size of the passed array
        size = len(arr)

        # Handle based on the size
        if size == 1:
            ret = [arr[0]]
        elif size == 2:
            ret.append(min(*arr))
            ret.append(max(*arr))
        else:
            # Split the array in half and sort
            mid  = int(size/2)
            arr1 = self.sort(arr[:mid ])
            arr2 = self.sort(arr[ mid:])

            # Merge the two sorted arrays
            ind1 = 0
            ind2 = 0

            # Append the entries to the return list
            for i in range(size):

                # Check if we're finished adding arr1 values
                if (ind1 == len(arr1)):
                    # Just add all the remaining values from arr2
                    ret.extend(arr2[ind2:])
                    break
                # Check if we're finished adding arr2 values
                elif (ind2 == len(arr2)):
                    # Just add all the remaining values from arr1
                    ret.extend(arr1[ind1:])
                    break
                
                # Check if next arr1 value is larger than next arr2 value
                elif (arr1[ind1] < arr2[ind2]):
                    ret.append(arr1[ind1])
                    ind1 += 1
                else :
                    ret.append(arr2[ind2])
                    ind2 += 1
        
        return ret