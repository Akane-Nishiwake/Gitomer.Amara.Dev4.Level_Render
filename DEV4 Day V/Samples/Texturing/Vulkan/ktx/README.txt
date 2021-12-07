If you are adding this to a CMake Vulkan project:

In C++:

// must be defined if ktx libraries are built statically (the ones in this folder are)
#define KHRONOS_STATIC 
#include <ktxvulkan.h>

In CMake:

# add support for ktx texture loading
include_directories(${CMAKE_SOURCE_DIR}/ktx/include)

if (WIN32)
	# Find the libraries
	find_library(KTX_LIB_D NAMES ktx PATHS ${CMAKE_SOURCE_DIR}/ktx/lib/win32/Debug)
	find_library(KTX_READ_LIB_D NAMES ktx_read PATHS ${CMAKE_SOURCE_DIR}/ktx/lib/win32/Debug)
	find_library(OBJUTIL_LIB_D NAMES objUtil PATHS ${CMAKE_SOURCE_DIR}/ktx/lib/win32/Debug)
	
	find_library(KTX_LIB_R NAMES ktx PATHS ${CMAKE_SOURCE_DIR}/ktx/lib/win32/Release)
	find_library(KTX_READ_LIB_R NAMES ktx_read PATHS ${CMAKE_SOURCE_DIR}/ktx/lib/win32/Release)
	find_library(OBJUTIL_LIB_R NAMES objUtil PATHS ${CMAKE_SOURCE_DIR}/ktx/lib/win32/Release)
	
	target_link_libraries(MyProject debug ${KTX_LIB_D} optimized ${KTX_LIB_R})
	target_link_libraries(MyProject debug ${KTX_READ_LIB_D} optimized ${KTX_READ_LIB_R})
	target_link_libraries(MyProject debug ${OBJUTIL_LIB_D} optimized ${OBJUTIL_LIB_R})
endif(WIN32)

# TODO: other platforms here



 