# setupBoost.cmake
#
# Finds, includes, and links boost to build system

if (WIN32)
    set(Boost_INCLUDE_DIR "lib/boost_1_78_0/")
endif()

find_package(Boost 1.78.0 REQUIRED)

if (${Boost_FOUND})
    message(STATUS "Boost ${Boost_VERSION} has been found.")
    add_compile_definitions("__HAS_BOOST__")
    include_directories(lib/boost_1_78_0)
    link_directories(lib/boost_1_78_0/stage/lib)
endif()
