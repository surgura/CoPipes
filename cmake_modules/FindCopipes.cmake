# Author: Aart Stuurman 09 sep 2018
# Sources used for writing this file are FindSFML.cmake and FindEigen3.cmake

# - Try to find CoPipes lib
#
#
# Once done this will define
#
#  COPIPES_FOUND - system has eigen lib with correct version
#  COPIPES_INCLUDE_DIR - the eigen include directory
#
# and the following imported target:
#
# This module reads hints about search locations from
# the following enviroment variables:
#
# COPIPES_INCLUDEDIR
# COPIPES_LIBRARYDIR

if (NOT DEFINED COPIPES_INCLUDEDIR)
    set(COPIPES_FOUND FALSE)
    message(FATAL_ERROR "Cannot find COPIPES. Provide COPIPES_INCLUDEDIR")
endif()
set(COPIPES_INCLUDE_DIR ${COPIPES_INCLUDEDIR})
set(COPIPES_FOUND TRUE)
