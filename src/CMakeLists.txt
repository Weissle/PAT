cmake_minimum_required (VERSION 3.2)

project (PAT)

set_property(GLOBAL PROPERTY USE_FOLDERS On)


set (CMAKE_CXX_STANDARD 11)
add_executable(1021.exe 1021.cpp)	
add_executable(1065.exe 1065.cpp)
add_executable(1078.exe 1078.cpp)
add_executable(1121.exe 1121.cpp)
add_executable(1032.exe 1032.cpp)
add_executable(1067.exe 1067.cpp)
add_executable(1105.exe 1105.cpp)
add_executable(1063.exe 1063.cpp)
add_executable(1140.exe 1140.cpp)
add_executable(1120.exe 1120.cpp)
add_executable(1068.exe 1068.cpp)

add_executable(1059.exe 1059.cpp)
add_executable(NoUse test.cpp)
set_target_properties(NoUse PROPERTIES FOLDER "Test")




