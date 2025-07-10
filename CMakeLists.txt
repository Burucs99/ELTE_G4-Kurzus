cmake_minimum_required(VERSION 3.16...3.27)

project(Geant_Kurzus)

# Keresd meg a geantot
find_package(Geant4 REQUIRED ui_all vis_all)

#keresd meg az src és include fileokat a projekten belül
file(GLOB sources ${PROJECT_SOURCE_DIR}/src/*.cc)
# Keresd meg a header fileokat
file(GLOB headers ${PROJECT_SOURCE_DIR}/include/*.hh)

add_executable(main main.cc ${sources} ${headers})
target_include_directories(main PRIVATE include)

target_link_libraries(main PRIVATE ${Geant4_LIBRARIES})


