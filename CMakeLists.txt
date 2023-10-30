#
# Copyright (c) 2014, 2020 CNRS Authors: Joseph Mirabel, Guilhem Saurel
#
# This file is part of hpp-statistics hpp-statistics is free software: you can
# redistribute it and/or modify it under the terms of the GNU Lesser General
# Public License as published by the Free Software Foundation, either version 3
# of the License, or (at your option) any later version.
#
# hpp-statistics is distributed in the hope that it will be useful, but WITHOUT
# ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
# FOR A PARTICULAR PURPOSE.  See the GNU General Lesser Public License for more
# details.  You should have received a copy of the GNU Lesser General Public
# License along with hpp-statistics  If not, see <http://www.gnu.org/licenses/>.

cmake_minimum_required(VERSION 3.10)

set(PROJECT_NAME hpp-statistics)
set(PROJECT_DESCRIPTION "Classes for doing statistics.")

set(PROJECT_USE_CMAKE_EXPORT TRUE)

include(cmake/hpp.cmake)

compute_project_args(PROJECT_ARGS LANGUAGES CXX)
project(${PROJECT_NAME} ${PROJECT_ARGS})

# Activate hpp-util logging if requested
set(HPP_DEBUG
    FALSE
    CACHE BOOL "trigger hpp-util debug output")
if(HPP_DEBUG)
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -DHPP_DEBUG")
endif()

add_project_dependency(hpp-util REQUIRED)

set(${PROJECT_NAME}_HEADERS
    include/hpp/statistics/fwd.hh include/hpp/statistics/bin.hh
    include/hpp/statistics/success-bin.hh
    include/hpp/statistics/distribution.hh)

set(${PROJECT_NAME}_SOURCES src/success-bin.cc)

add_library(${PROJECT_NAME} SHARED ${${PROJECT_NAME}_SOURCES}
                                   ${${PROJECT_NAME}_HEADERS})
target_include_directories(${PROJECT_NAME} PUBLIC $<INSTALL_INTERFACE:include>)
target_link_libraries(${PROJECT_NAME} hpp-util::hpp-util)

install(
  TARGETS ${PROJECT_NAME}
  EXPORT ${TARGETS_EXPORT_NAME}
  DESTINATION lib)

add_subdirectory(tests)

# Add dependency toward hpp-statistics library in pkg-config file.
pkg_config_append_libs("hpp-statistics")

install(FILES package.xml DESTINATION share/${PROJECT_NAME})
