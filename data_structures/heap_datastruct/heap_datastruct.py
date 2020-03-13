

class BinaryHeap:
    """
    Implementation of a Binary Heap data structure
    """

    def __init__(self, arr=None):
        """
        Initialize Binary Heap data structure
        """
        # Initialize the container to store the values
        self._items = []

        # If array is not None add values to this object
        if arr is not None:
            for val in arr:
                self.insert(val)


    def parent_indx(self, indx):
        """
        Return the parent index of the supplied index.
        
        Parameters
        ----------
        indx : int
            index to find the parent of
        
        Returns
        -------
        Index of parent node
        """
        # Storage of parent index
        parent_indx = 0

        # Make sure index is valid
        if (indx > 0) and (indx < len(self._items)):
            # Compute the parent index
            parent_indx = int((indx-1)/2)
        
        else:
            # Throw exception
            raise ValueError

        return parent_indx

    
    def first_child(self, indx):
        """
        Returns the first child index of the associated node. If no child index
        exists, returns -1

        Parameters
        ----------
        indx : int
            Index of node to find the child of
        
        Returns
        -------
        Index of the first child node, or -1 if no child exists
        """
        # Initialize return index
        child_indx = NotImplementedError

        # Compute child index if indx is valid
        if (indx >= 0) and (indx < len(self._items)):
            child_indx = int((2*indx) + 1)
            if (child_indx >= len(self._items)):
                child_indx = None
        # Otherwise raise exception
        else:
            raise ValueError(f'indx parameter out of bounds (indx={indx})')

        return child_indx


    def second_child(self, indx):
        """
        Returns the second child index of the associated node

        Parameters
        ----------
        indx : int
            Index of node to find the child of
        
        Returns
        -------
        Index of the second child node
        """
        # Get the first child index
        child = self.first_child(indx)

        # Make sure the returned first child is valid
        if (child is not None) and (child < len(self._items)-1):
            child += 1
        else:
            child = None

        return child


    def insert(self, val):
        """
        Add new element to object

        Parameters
        ----------
        val : int or float
            new object to add to structure
        """
        # First add the element to the end of the list
        self._items.append(val)

        # Now see if we need to move the element up the tree
        curIndx = len(self._items) - 1

        while curIndx > 0:
            # Get index of parent
            parIndx = self.parent_indx(curIndx)
            
            # Swap if the parent value is less
            if self._items[parIndx] < self._items[curIndx]:
                tmp_val = self._items[parIndx]
                self._items[parIndx] = self._items[curIndx]
                self._items[curIndx] = tmp_val
                curIndx = parIndx
            
            # Otherwise break the loop
            else:
                break
        

    def popAt(self, indx):
        """
        Remove the largest value in the Heap and return it. This requires
        restructuring the Heap once the root is removed.

        Parameters
        ----------
        indx : int
            Index from which to remove

        Returns
        -------
        Largest value in the Heap
        """
        # Raise exception if index is out of bounds
        if indx >= len(self._items):
            raise ValueError(f'indx of ({indx}) out of bounds')

        # Get the value that we want to return
        ret_value = self._items[indx]
        new_root  = self._items.pop()

        # Only sift values if there values left to be shifted
        if len(self._items) > 0:
            self._items[indx] = new_root

            # Setup some preliminary variables
            cur_indx  = indx
            next_indx = 0
            c1 = self.first_child(indx)
            c2 = self.second_child(indx)

            # Sift new_root down the heap
            while c1 is not None:
                # Get the largest child
                next_indx = c1
                if c2 is not None:
                    # Check which child is larger
                    if self._items[c2] > self._items[c1]:
                        next_indx = c2

                # Shift up the child if necessary
                if self._items[next_indx] > new_root:
                    self._items[cur_indx]  = self._items[next_indx]
                    self._items[next_indx] = new_root
                
                    # Update variables
                    cur_indx = next_indx
                    c1 = self.first_child(next_indx)
                    c2 = self.second_child(next_indx)
                else:
                    c1 = None
                    c2 = None

        # Return the value
        return ret_value


    def popMax(self):
        """
        Remove the largest value in the Heap and return it

        Returns
        -------
        Largest value in the Heap
        """
        return self.popAt(0)
