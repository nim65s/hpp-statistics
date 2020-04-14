#
# Copyright (c) 2014, 2020 CNRS
# Authors: Joseph Mirabel, Guilhem Saurel
#
#
# This file is part of hpp-statistics
# hpp-statistics is free software: you can redistribute it
# and/or modify it under the terms of the GNU Lesser General Public
# License as published by the Free Software Foundation, either version
# 3 of the License, or (at your option) any later version.
#
# hpp-statistics is distributed in the hope that it will be
# useful, but WITHOUT ANY WARRANTY; without even the implied warranty
# of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
# General Lesser Public License for more details.  You should have
# received a copy of the GNU Lesser General Public License along with
# hpp-statistics  If not, see
# <http://www.gnu.org/licenses/>.

CMAKE_MINIMUM_REQUIRED(VERSION 3.1)

SET(PROJECT_NAME hpp-statistics)
SET(PROJECT_DESCRIPTION "Classes for doing statistics.")

SET(PROJECT_USE_CMAKE_EXPORT TRUE)

INCLUDE(cmake/hpp.cmake)

COMPUTE_PROJECT_ARGS(PROJECT_ARGS LANGUAGES CXX)
PROJECT(${PROJECT_NAME} ${PROJECT_ARGS})

# Activate hpp-util logging if requested
SET (HPP_DEBUG FALSE CACHE BOOL "trigger hpp-util debug output")
IF (HPP_DEBUG)
  SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -DHPP_DEBUG")
ENDIF()

ADD_PROJECT_DEPENDENCY(hpp-util REQUIRED)

SET(${PROJECT_NAME}_HEADERS
  include/hpp/statistics/fwd.hh
  include/hpp/statistics/bin.hh
  include/hpp/statistics/success-bin.hh
  include/hpp/statistics/distribution.hh
  )

SET(${PROJECT_NAME}_SOURCES
  src/success-bin.cc
  )

ADD_LIBRARY(${PROJECT_NAME} SHARED
  ${${PROJECT_NAME}_SOURCES} ${${PROJECT_NAME}_HEADERS})
TARGET_INCLUDE_DIRECTORIES(${PROJECT_NAME} PUBLIC $<INSTALL_INTERFACE:include>)
TARGET_LINK_LIBRARIES(${PROJECT_NAME} hpp-util::hpp-util)

INSTALL(TARGETS ${PROJECT_NAME} EXPORT ${TARGETS_EXPORT_NAME} DESTINATION lib)

ADD_SUBDIRECTORY(tests)

# Add dependency toward hpp-statistics library in pkg-config file.
PKG_CONFIG_APPEND_LIBS("hpp-statistics")
