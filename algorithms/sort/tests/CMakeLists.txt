#**************************************************************************
#  algorithms/sort/CMakeLists.txt: JVC Algorithms                         *
# ----------------------------------------------------------------------- *
#  Copyright © 2020 JCardenzana                                           *
# ----------------------------------------------------------------------- *
#                                                                         *
#  This program is free software: you can redistribute it and/or modify   *
#  it under the terms of the GNU General Public License as published by   *
#  the Free Software Foundation, either version 3 of the License, or      *
#  (at your option) any later version.                                    *
#                                                                         *
#  This program is distributed in the hope that it will be useful,        *
#  but WITHOUT ANY WARRANTY; without even the implied warranty of         *
#  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the          *
#  GNU General Public License for more details.                           *
#                                                                         *
#  You should have received a copy of the GNU General Public License      *
#  along with this program.  If not, see <http://www.gnu.org/licenses/>.  *
#                                                                         *
#**************************************************************************

#------------------------------------------
# Define include directories
#------------------------------------------
include_directories (${CMAKE_CURRENT_SOURCE_DIR}/../bubble_sort
                     ${CMAKE_CURRENT_SOURCE_DIR}/../heap_sort
                     ${CMAKE_CURRENT_SOURCE_DIR}/../insertion_sort
                     ${CMAKE_CURRENT_SOURCE_DIR}/../merge_sort
                     ${CMAKE_CURRENT_SOURCE_DIR}/../selection_sort
                     ${CMAKE_SOURCE_DIR}/data_structures/heap_datastruct)


#------------------------------------------
# Define tests
#------------------------------------------
jvcalgo_test (test_sort_cpp test.cpp)
add_test (NAME test_sort_py COMMAND python test.py WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR})
