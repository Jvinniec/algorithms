/***************************************************************************
 *  insertion_sort.hpp: JVC Algorithms                                     *
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
* @class insertion_sort
*
* C++ implementation of the Insertion Sort algorithm
********************************************************************/
class insertion_sort {
    public:
        /*****************************************************************//*
         * Implements the Insertion Sort sorting algorithm
         * 
         * @param[in] arr       Array to be sorted
         * @returns Sorted copy of @p arr
         ********************************************************************/
        template <class T>
        static std::vector<T> sort(std::vector<T> arr) {
            // Get the size of the vector
            long size = arr.size();

            // Loop over all the entries in the vector
            for (int i=0; i<size; i++) {
                // Get value at position
                T val_i = arr[i];

                // Loop through teh previous values to see where to insert it
                for (int j=i-1; j>-1; j--) {
                    
                    // If current value is larger, swap it
                    if (val_i < arr[j]) {
                        arr[j+1] = arr[j];
                        // If at the beginning, just set the value
                        if (j==0) {
                            arr[0] = val_i;
                        }
                    } else {
                        arr[j+1] = val_i;
                        break;
                    }
                }
            }

            return arr;
        };
};