cmake_minimum_required(VERSION 3.13.1)

Message("")
Message( STATUS "CMAKE_BINARY_DIR: " ${CMAKE_BINARY_DIR} )
Message( STATUS "CMAKE_SOURCE_DIR: " ${CMAKE_SOURCE_DIR} )
Message( STATUS "CMAKE_COMMAND: " ${CMAKE_COMMAND} )
Message( STATUS "CMAKE_VERSION: " ${CMAKE_VERSION} )
Message( STATUS "CMAKE_C_COMPILER: " ${CMAKE_C_COMPILER} )
Message( STATUS "CMAKE_PROJECT_NAME: " ${CMAKE_PROJECT_NAME} )
Message( STATUS "CMAKE_FINDCMAKE: " ${CMAKE_SOURCE_DIR}/CMAKE )

project(SortingVisualizer)

# ------- Set Vars ------- #

set(CMAKE_C_STANDARD 11)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/CMAKE")
set(SOURCE_FILES include/Common.h source/Screen.cpp include/Screen.h source/NumberGenerator.cpp include/NumberGenerator.h source/Main.cpp source/Visualizer.cpp include/Visualizer.h include/SortingStrategy.h source/SortingAlgorithm.cpp include/SortingAlgorithm.h source/BubbleSort.cpp include/BubbleSort.h source/SelectionSort.cpp include/SelectionSort.h source/InsertionSort.cpp include/InsertionSort.h source/QuickSort.cpp include/QuickSort.h source/MergeSort.cpp include/MergeSort.h source/BogusSort.cpp include/BogusSort.h source/CocktailSort.cpp include/CocktailSort.h source/ShellSort.cpp include/ShellSort.h source/RadixSort.cpp include/RadixSort.h)

# ------- End Set Vars --- #

# ------- Executable ----- #

ADD_EXECUTABLE(SortingVisualizer ${SOURCE_FILES})

# ------- End Executable - #

# ------- Finds ---------- #

FIND_PACKAGE(SDL2 REQUIRED)
FIND_PACKAGE(SDL2_IMAGE)
FIND_PACKAGE(SDL2TTF)
FIND_PACKAGE(SDL2Mixer)

# ------- End Finds ------ #

# ------- Inc & Link ---- #

INCLUDE_DIRECTORIES(${SDL2_INCLUDE_DIR} ${SDL2TTF_INCLUDE_DIR} ${SDL2_IMAGE_INCLUDE_DIR} ${SDL2Mixer_INCLUDE_DIR})
TARGET_LINK_LIBRARIES(${PROJECT_NAME} ${SDL2_LIBRARY} ${SDL2TTF_LIBRARY} ${SDL2_IMAGE_LIBRARY} ${SDL2Mixer_LIBRARY} )

# ------- End ----------- #



