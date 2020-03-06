

def sort(arr):
    """ Sort array of values using insertion sort algorithm
    """
    # Get length of arr
    len_arr = len(arr)

    # Loop through all entries in the list
    for i in range(1, len_arr):
        # Get value at position we care about
        val_i = arr[i]

        # Loop through the previous values to see where to insert it
        for j in range(i-1,-1, -1):
            # If current value is larger, swap it
            if val_i < arr[j]:
                arr[j+1] = arr[j]
                arr[j]   = val_i
            else:
                break

    return arr
