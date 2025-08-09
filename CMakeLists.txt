set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
cmake_minimum_required(VERSION 3.16...3.27)

project(Geant_Kurzus)

# Keresd meg a geantot
find_package(Geant4 REQUIRED ui_all vis_all)

#keresd meg az src és include fileokat a projekten belül
file(GLOB sources ${PROJECT_SOURCE_DIR}/src/*.cc)
# Keresd meg a header fileokat
file(GLOB headers ${PROJECT_SOURCE_DIR}/include/*.hh)

#file(GLOB MACRO_FILES "${PROJECT_SOURCE_DIR}/Macros/*.mac")
#copying all macro files into build folder and then deleting them from the source dir
#file(COPY ${MACRO_FILES} DESTINATION "${PROJECT_BINARY_DIR}/Macros")

if(MACRO_FILES)  
  message(STATUS "Moving ${MACRO_FILES} to build/Macros/")
  file(REMOVE ${MACRO_FILES})
endif()

add_executable(main main.cc ${sources} ${headers})
target_include_directories(main PRIVATE include)

target_link_libraries(main PRIVATE ${Geant4_LIBRARIES})


