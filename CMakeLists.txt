cmake_minimum_required(VERSION 3.20)
project(mp2_lab2_matrix_master_2)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)
include_directories(gtest)
include_directories(include)
include_directories(samples)
include_directories(test)

add_executable(mp2_lab2_matrix_master_2
        gtest/gtest-all.cc
        gtest/gtest.h
        include/utmatrix.h
        samples/sample_matrix.cpp
        sln/vc10/gtest.vcxproj
        sln/vc10/gtest.vcxproj.filters
        sln/vc10/sample_utmatrix.vcxproj
        sln/vc10/sample_utmatrix.vcxproj.filters
        sln/vc10/test_utmatrix.vcxproj
        sln/vc10/test_utmatrix.vcxproj.filters
        sln/vc10/utmatrix.sln
        sln/vc9/gtest.vcproj
        sln/vc9/sample_utmatrix.vcproj
        sln/vc9/test_utmatrix.vcproj
        sln/vc9/utmatrix.sln
        test/test_main.cpp
        test/test_tmatrix.cpp
        test/test_tvector.cpp)
