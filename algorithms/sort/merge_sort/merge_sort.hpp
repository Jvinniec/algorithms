/***************************************************************************
 *  merge_sort.hpp: JVC Algorithms                                         *
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

#ifndef MERGE_SORT_HPP
#define MERGE_SORT_HPP

#include <vector>

/*****************************************************************//*
* @class merge_sort
*
* C++ implementation of the Merge Sort algorithm
********************************************************************/
class merge_sort {
    public:
        /*****************************************************************//*
         * Implements the Merge Sort sorting algorithm
         * 
         * @param[in] arr       Array to be sorted
         * @returns Sorted copy of @p arr
         ********************************************************************/
        template <class T>
        std::vector<T> sort(std::vector<T> arr) {
            return this->recursive_sort(arr, 0, arr.size());
        }

    private:
        template <class T>
        std::vector<T> recursive_sort(std::vector<T>& arr,
                                      const long& start,
                                      const long& stop) {
            // Get the size of the vector to be sorted
            long size = stop - start;

            // Handle based on the size
            if (size == 2) {
                // Swap the values if necessary
                if (arr[start] > arr[start+1]) {
                    T tmp        = arr[start];
                    arr[start]   = arr[start+1];
                    arr[start+1] = tmp;
                }
            } else if (size > 2) {
                // Split the array in half and sort
                long mid = start + size/2;
                this->recursive_sort(arr, start, mid);
                this->recursive_sort(arr, mid, stop);

                // Copy the first half
                std::vector<T> cpy = std::vector<T>(arr.begin()+start,
                                                    arr.begin()+mid);

                // Merge the two sorted arrays
                long ind1 = 0;
                long ind2 = mid;
                long len_cpy = mid-start;

                // Append the entries to the return list
                for (int i=start; i<stop; i++) {
                    // We can consider being all done once we've inserted the
                    // entries from the left
                    if (ind1 == len_cpy) {
                        break;
                    } else if ((ind2 == stop) || (arr[ind2] > cpy[ind1])) {
                        arr[i] = cpy[ind1];
                        ind1 += 1;
                    } else {
                        arr[i] = arr[ind2];
                        ind2 += 1;
                    }
                }
            }

            return arr;
        }
};

#endif /* MERGE_SORT_HPP */
