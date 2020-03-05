
# This file implements a Bubble sort algorithm

def sort(obj):
    """
    """

    # Get an estimate of the length
    len_obj = len(obj)

    # Create a temporary storage object
    tmp_obj = None

    # Loop over all the entries in the list
    for i in range(len_obj-1):
        for j in range(len_obj-i-1):
            if obj[j] > obj[j+1]:
                
                # Swap the values
                tmp_obj  = obj[j]
                obj[j]   = obj[j+1]
                obj[j+1] = tmp_obj

    return obj
