/***************************************************************************
 *  quick_sort.hpp: JVC Algorithms                                         *
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

#ifndef QUICK_SORT_HPP
#define QUICK_SORT_HPP

#include <vector>

/*****************************************************************//*
* @class quick_sort
*
* C++ implementation of the Quick Sort algorithm
********************************************************************/
class quick_sort {
    public:
        /*****************************************************************//*
         * Implements the Quick Sort sorting algorithm
         * 
         * @param[in] arr       Array to be sorted
         * @returns Sorted copy of @p arr
         ********************************************************************/
        template <class T>
        std::vector<T> sort(std::vector<T> arr) {
            this->recursive_sort(arr, 0, arr.size());
            return arr;
        }

    private:
        /*****************************************************************//*
         * Implements the Quick Sort sorting algorithm recursively.
         * 
         * @param[in] arr       Array to be sorted (inplace)
         * @param[in] start     Starting index
         * @param[in] stop      Stoping index
         * @returns @p arr with indexes between [start,stop) sorted
         ********************************************************************/
        template <class T>
        void recursive_sort(std::vector<T>& arr,
                            const long& start,
                            const long& stop) {
            // Get the length
            int size = stop - start;

            // Only process if the array is sizeable
            if (size > 1) {
                int left  = start + 1;
                int right = stop - 1;

                // Caceht eh pivot value
                T pivot = arr[start];

                while (right >= left) {
                    
                    // Move the left index
                    while ((left <= right) && (arr[left] < pivot))
                        left += 1;

                    // Move the right index
                    while ((arr[right] >= pivot) && (right >= left))
                        right -= 1;

                    // Swap the values if right and left have crossed
                    if (left < right) {
                        T tmp = arr[right];
                        arr[right] = arr[left];
                        arr[left]  = tmp;
                    }
                }

                // Swap the pivot to new position
                if (start != right) {
                    arr[start] = arr[right];
                    arr[right] = pivot;
                }

                // Sort the values on the left/right of the pivot
                this->recursive_sort(arr, start, right);
                this->recursive_sort(arr, left, stop);
            }

            return;
        }
};

#endif /* QUICK_SORT_HPP */