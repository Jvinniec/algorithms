#**************************************************************************
#  CMakeLists.txt: jvc_algorithms                                             *
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
cmake_minimum_required (VERSION 3.0)
project (jvc_algorithms)
set(CMAKE_BUILD_TYPE Release)
#set(CMAKE_VERBOSE_MAKEFILE ON)     # This enables verbose printing during build

# Add Version number
set (JVCALGO_VERSION_MAJOR 0)
set (JVCALGO_VERSION_MINOR 1)
set (JVCALGO_VERSION_PATCH 0)
set (jvcalgo_version "${JVCALGO_VERSION_MAJOR}.${JVCALGO_VERSION_MINOR}.${JVCALGO_VERSION_PATCH}")
message ("\nCOMPILING JVCALGO VERSION ${JVCALGO_version}\n")

# Set SWIG policies
cmake_policy(SET CMP0086 NEW)
cmake_policy(SET CMP0078 NEW)

# Set some flags necessary for the MAC OS builds
if (CMAKE_SYSTEM_NAME MATCHES Darwin)
   set(CMAKE_MACOSX_RPATH 1)
endif()

# If the user supplied a prefix, set it
if (prefix)
   set (CMAKE_INSTALL_PREFIX ${prefix})
endif()

# Define where we want to put things
set (CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/build/lib)
set (CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/build/lib)
set (CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/build/bin)
set (HEADER_OUTPUT_PATH ${CMAKE_BINARY_DIR}/build/include)

# Define the default compile flags
set (JVCALGO_TEST_CXX_FLAGS "")
set (CODECOV "none")
if (coverage)
    include(CodeCoverage.cmake)
    message (STATUS "Testing flags set to ${JVCALGO_TEST_CXX_FLAGS} (coverage = ${CODECOV})")
endif()

set (JVCALGO_CXX_FLAGS "${JVCALGO_CXX_FLAGS} -std=c++14 -Wall")
set (CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} ${JVCALGO_CXX_FLAGS}")
set (CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} ${JVCALGO_TEST_CXX_FLAGS}")

# Define a macro for test compilation
# so that we dont have to specify multiple lines
# EVERY SINGLE TIME!
function (jvcalgo_test _name _source)
    add_executable(${_name} ${_source})
    add_test(NAME ${_name} COMMAND ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/${_name} ${ARGN})
endfunction (jvcalgo_test)

#-------------------------------------------

# Define the sub-directories for building in
enable_testing ()
add_subdirectory (algorithms)
#add_subdirectory (data_structures)

#-------------------------------------------
