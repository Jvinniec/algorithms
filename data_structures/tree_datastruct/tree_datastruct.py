

class BinaryTree:
    """
    Implementation of a Binary Tree data structure
    """

    def __init__(self, key=None):
        """ Initialize the tree data structure
        """
        self._key = key
        self._leftchild  = None
        self._rightchild = None


    def setKey(self, val):
        """ Set the value of this nodes key
        
        Parameters
        ----------
        val : object
            Any object
        """
        self._key = val

    
    def getKey(self, val):
        """ Return the value of this nodes key
        """
        return self._key


    def setLeftChild(self, val):
        """ Set the value of the left child
        
        Parameters
        ----------
        val : object
            Any object
        """
        # Initialize the new tree node
        t = BinaryTree(val)

        # Swap the old child for the new
        t.setLeftChild(self._leftchild)
        self._leftchild = t

    
    def setRightChild(self, val):
        """ Set the value of the right child
        
        Parameters
        ----------
        val : object
            Any object
        """
        # Initialize the new tree node
        t = BinaryTree(val)

        # Swap the old child for the new
        t.setRightChild(self._rightchild)
        self._rightchild = t


    def getLeftChild(self):
        """ Return the left child of this tree
        """
        return self._leftchild


    def getRightChild(self):
        """ Return the right child of this tree
        """
        return self._rightchild
        
