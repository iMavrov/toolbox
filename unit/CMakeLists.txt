project(unit)

add_library(${PROJECT_NAME} STATIC src/quantity.cpp)

target_include_directories(${PROJECT_NAME} PUBLIC include)
target_link_libraries(${PROJECT_NAME} PUBLIC core)
