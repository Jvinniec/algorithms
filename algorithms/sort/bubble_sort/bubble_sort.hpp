/***************************************************************************
 *  bubble_sort.hpp: JVC Algorithms                                        *
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

#ifndef BUBBLE_SORT_HPP
#define BUBBLE_SORT_HPP

#include <vector>

/*****************************************************************//*
* @class bubble_sort
*
* C++ implementation of the Bubble Sort algorithm
********************************************************************/
class bubble_sort {
    public:
        /*****************************************************************//*
         * Implements the Bubble Sort sorting algorithm
         * 
         * @param[in] arr       Array to be sorted
         ********************************************************************/
        template <class T>
        std::vector<T> sort(std::vector<T> arr) {
            // Get the size of the vector
            long size = arr.size();

            // Create a temporary storage object
            T tmp_obj;

            // Loop over all the entries in the vector
            for (int i=0; i<size-1; i++) {
                for (int j=0; j<size-i-1; j++) {
                    
                    // Swap the values if the next one on smaller
                    if (arr[j] > arr[j+1]) {
                        tmp_obj = arr[j];
                        arr[j]  = arr[j+1];
                        arr[j+1] = tmp_obj;
                    }
                }
            }

            return arr;
        };
};

#endif /* BUBBLE_SORT_HPP */