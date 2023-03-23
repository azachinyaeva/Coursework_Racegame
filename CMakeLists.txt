cmake_minimum_required(VERSION 3.1)
project(Races)
set(SOURCES_EXE RaceDetails.cpp main.cpp) 
set(HEADERS_EXE RaceDetails.h)
set (CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON)
add_library (RacesLib SHARED AllTerrainBoots.cpp AllTerrainBoots.h Camel.cpp Camel.h Broomstick.cpp Broomstick.h Centaur.cpp Centaur.h Eagle.cpp Eagle.h FlyingCarpet.cpp FlyingCarpet.h HighspeedCamel.cpp HighspeedCamel.h Vehicle.cpp Vehicle.h)
add_executable(Races_project ${SOURCES_EXE} ${HEADERS_EXE})
target_link_libraries(Races_project RacesLib)		

