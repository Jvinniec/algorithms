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

#include "heap_datastruct.hpp"

class heap_sort {
    public:
        template <class T>
        /*****************************************************************//*
         * Implements the Heap Sort sorting algorithm
         * 
         * @param[in] arr       Array to be sorted
         * @returns Sorted copy of @p arr
         ********************************************************************/
        std::vector<T> sort(std::vector<T> arr) {
            // Create a heap data structure
            BinaryHeap<T> heap_arr = BinaryHeap<T>(arr);

            // Re-add the values back to the array
            for (int i=arr.size()-1; i>-1; i--) {
                arr[i] = heap_arr.popMax();
            }

            return arr;
        }
};