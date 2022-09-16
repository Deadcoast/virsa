# getSystemEndianness.cmake
#
# Gets the endianness of the system and creates definitions for the project

include(TestBigEndian)

TEST_BIG_ENDIAN(IS_BIG_ENDIAN)

if (IS_BIG_ENDIAN)
    message(STATUS "system byte order: BIG ENDIAN")
    add_compile_definitions("BIG_ENDIAN_BYTE_ORDER")
else()
    message(STATUS "system byte order: LITTLE ENDIAN")
    add_compile_definitions("LITTLE_ENDIAN_BYTE_ORDER")
endif()
