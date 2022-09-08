# config/CMakeLists.txt

file(COPY virsaConfig.json DESTINATION ${CMAKE_BINARY_DIR})
message(STATUS "Copied virsaConfig.json to ${CMAKE_SOURCE_DIR}/build/${CMAKE_BUILD_TYPE}")
