/***************************************************************************
 *  selection_sort.hpp: JVC Algorithms                                     *
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


#include <vector>

/*****************************************************************//*
* @class selection_sort
*
* C++ implementation of the Selection Sort algorithm
********************************************************************/
class selection_sort {
    public:
        /*****************************************************************//*
         * Implements the Selection Sort sorting algorithm
         * 
         * @param[in] arr       Array to be sorted
         * @returns Sorted copy of @p arr
         ********************************************************************/
        template <class T>
        std::vector<T> sort(std::vector<T> arr) {
            // Get the length of the array
            long size = arr.size();

            // Loop through the array
            for (int i=0; i<size-1; i++) {
                // Current index to swap to
                long cur_ind = size - i - 1;

                // Find the maximum in the range 0,size-i
                T    max_val  = arr[0];
                long max_indx = 0;
                for (int j=1; j<cur_ind+1; j++) {
                    if (arr[j] > max_val) {
                        max_val  = arr[j];
                        max_indx = j;
                    }
                }

                // Now swap the value with the current end
                if (max_indx != cur_ind) {
                    T tmp = arr[max_indx];
                    arr[max_indx] = arr[cur_ind];
                    arr[cur_ind]  = tmp;
                }
            }

            return arr;
        }
};