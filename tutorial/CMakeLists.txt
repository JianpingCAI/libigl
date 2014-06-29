cmake_minimum_required(VERSION 2.6)
project(libigl_tutorials)

SET(CMAKE_RUNTIME_OUTPUT_DIRECTORY ../)
SET(CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake)

## Check for CoMiSo, if not available skip the examples that depends on it
find_package(LIBCOMISO QUIET)

## Check for MATLAB, if not available skip the examples that depends on it
find_package(LIBMATLAB QUIET)

## Check for EMBREE, if not available skip the examples that depends on it
find_package(LIBEMBREE QUIET)

# Chapter 1
add_subdirectory("101_FileIO")
add_subdirectory("102_DrawMesh")
add_subdirectory("103_Events")
add_subdirectory("104_Colors")
add_subdirectory("105_Overlays")
if(EMBREE_FOUND)
add_subdirectory("106_Picking")
endif(EMBREE_FOUND)

# Chapter 2
add_subdirectory("201_Normals")
add_subdirectory("202_GaussianCurvature")
add_subdirectory("203_CurvatureDirections")
add_subdirectory("204_Gradient")
add_subdirectory("205_Laplacian")

# Chapter 3
add_subdirectory("301_Slice")
add_subdirectory("302_Sort")
add_subdirectory("303_LaplaceEquation")
add_subdirectory("304_LinearEqualityConstraints")
add_subdirectory("305_QuadraticProgramming")

# Chapter 4
add_subdirectory("401_BiharmonicDeformation")
add_subdirectory("402_PolyharmonicDeformation")
add_subdirectory("403_BoundedBiharmonicWeights")

# Chapter 5
add_subdirectory("501_HarmonicParam")
add_subdirectory("502_LSCMParam")
add_subdirectory("503_ARAPParam")

if(LIBCOMISO_FOUND)
add_subdirectory("504_NRosyDesign")
add_subdirectory("505_MIQ")
add_subdirectory("506_FrameField")
endif(LIBCOMISO_FOUND)

# Chapter 6
add_subdirectory("601_Serialization")
if(MATLAB_FOUND)
add_subdirectory("602_Matlab")
endif(MATLAB_FOUND)
add_subdirectory("604_Triangle")
add_subdirectory("605_Tetgen")
if(EMBREE_FOUND)
add_subdirectory("606_AmbientOcclusion")
endif(EMBREE_FOUND)