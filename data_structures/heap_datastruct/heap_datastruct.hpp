/***************************************************************************
 *  heap_datastruct.hpp: JVC Algorithms                                    *
 * ----------------------------------------------------------------------- *
 *  Copyright © 2020 JCardenzana                                           *
 * ----------------------------------------------------------------------- *
 *                                                                         *
 *  This program is free software: you can redistribute it and/or modify   *
 *  it under the terms of the GNU General Public License as published by   *
 *  the Free Software Foundation, either version 3 of the License, or      *
 *  (at your option) any later version.                                    *
 *                                                                         *
 *  This program is distributed in the hope that it will be useful,        *
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of         *
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the          *
 *  GNU General Public License for more details.                           *
 *                                                                         *
 *  You should have received a copy of the GNU General Public License      *
 *  along with this program.  If not, see <http://www.gnu.org/licenses/>.  *
 *                                                                         *
 ***************************************************************************/

#ifndef HEAP_DATASTRUCT_HPP
#define HEAP_DATASTRUCT_HPP

#include <vector>
#include <string>
#include <exception>

template <class T>
class BinaryHeap {
    public:
        /***************************************************************//**
         * Constructor from a vector of values
         * 
         * @param[in] arr       Array of values used to construct Heap
         *******************************************************************/
        BinaryHeap(const std::vector<T>& arr) : m_items(std::vector<T>(0)) {
            // Loop through all the entries in arr
            for (const T& val : arr) {
                insert(val);
            }
        }


        /***************************************************************//**
         * Get the parent index for a given position
         * 
         * @param[in] indx      Index to get the parent of
         * @returns Index of parent for @p indx
         *******************************************************************/
        int parent_indx(const int& indx) const {
            // Storage of parent index
            int parent_indx(0);

            // Make sure index is valid
            if ((indx > 0) && (indx < m_items.size())) {
                // Compute the parent index
                parent_indx = (indx-1)/2;
            } else {
                // Throw exception
                throw std::invalid_argument(std::string() +
                        "[ERROR] BinaryHeap::parent_indx(int&) :" +
                        " Supplied 'indx' value is invalid");
            }

            return parent_indx;
        }


        /***************************************************************//**
         * Get the index of the first child associated with a given index
         * 
         * @param[in] indx      Index to get the child of
         * @returns Index of child for @p indx
         *******************************************************************/
        int first_child(const int& indx) const {
            // Initialize return index
            int child_indx(0);

            // Compute child index if indx is valid
            if ((indx >= 0) && (indx < m_items.size())) {
                child_indx = 2*indx + 1;
                if (child_indx >= m_items.size()) {
                    child_indx = -1;
                }
            } else {
                throw std::invalid_argument(std::string() +
                        "[ERROR] BinaryHeap::first_child(int&) :" +
                        " Supplied 'indx' value is invalid"); 
            }

            return child_indx;
        }


        /***************************************************************//**
         * Get the index of the first child associated with a given index
         * 
         * @param[in] indx      Index to get the child of
         * @returns Index of child for @p indx
         *******************************************************************/
        int second_child(const int& indx) const {
            // Initialize return index
            int child_indx(0);

            // Compute child index if indx is valid
            if ((indx >= 0) && (indx < m_items.size())) {
                child_indx = 2*indx + 2;
                if (child_indx >= m_items.size()) {
                    child_indx = -1;
                }
            } else {
                throw std::invalid_argument(std::string() +
                        "[ERROR] BinaryHeap::first_child(int&) :" +
                        " Supplied 'indx' value is invalid"); 
            }

            return child_indx;
        }


        /***************************************************************//**
         * Add new element to the Heap
         * 
         * @param[in] val       Value to add to the Heap
         *******************************************************************/
        void insert(const T& val) {
            // First add the element to the end of the list
            m_items.push_back(val);

            // Now see if we need to move the element up the tree
            int curIndx = m_items.size() - 1;

            while (curIndx > 0) {
                // Get index of parent
                int parIndx = this->parent_indx(curIndx);

                // Swap if the parent value is less
                if (m_items[parIndx] < m_items[curIndx]) {
                    T tmp_val = m_items[parIndx];
                    m_items[parIndx] = m_items[curIndx];
                    m_items[curIndx] = tmp_val;
                    curIndx = parIndx;
                } 
                // Otherwise break the loop
                else {
                    break;
                }
            }

            return;
        }


        /***************************************************************//**
         * Remove the value at a given index in the Heap and return it.
         * This will require restructure the heap once the value is removed.
         * 
         * @param[in] indx          Index at which to remove a value
         * @returns Value at @p indx
         *******************************************************************/
        T popAt(const int& indx) {
            // Raise exception if index is out of bounds
            if (indx >= m_items.size()) {
                throw std::invalid_argument(std::string() +
                        "[ERROR] BinaryHeap::popAt(int&) :" +
                        " Supplied 'indx' value is invalid"); 
            }

            // Get the value we want to return
            T ret_value = m_items[indx];
            T new_root  = m_items.back();
            m_items.pop_back();

            // Only sift values if there are values left to be shifted
            if (m_items.size() > 0) {
                m_items[indx] = new_root;

                // Setup some preliminary variables
                int cur_indx  = indx;
                int next_indx = 0;
                int child_1   = first_child(indx);
                int child_2   = second_child(indx);

                // Sift new_root down the Heap
                while (child_1 > -1) {
                    // Get the largest child
                    next_indx = child_1;

                    if (child_2 > -1) {
                        // Check which child is larger
                        if (m_items[child_2] > m_items[child_1]) {
                            next_indx = child_2;
                        }
                    }

                    // Shift up the child if necessary
                    if (m_items[next_indx] > new_root) {
                        m_items[cur_indx]  = m_items[next_indx];
                        m_items[next_indx] = new_root;

                        // Update variables
                        cur_indx = next_indx;
                        child_1 = first_child(next_indx);
                        child_2 = second_child(next_indx);
                    } 
                    // Otherwise we're finished
                    else {
                        child_1 = -1;
                        child_2 = -1;
                    }
                }

            }

            // Return the value
            return ret_value;
        }


        /***************************************************************//**
         * Remove the largest value and restructure the Heap.
         * 
         * @returns Largest value in the Heap
         *******************************************************************/
        T popMax(void) {
            return this->popAt(0);
        }

    private:
        std::vector<T> m_items;
};

#endif /* HEAP_DATASTRUCT_HPP */
