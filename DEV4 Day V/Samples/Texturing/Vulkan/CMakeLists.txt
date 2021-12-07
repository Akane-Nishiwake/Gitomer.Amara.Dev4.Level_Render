cmake_minimum_required(VERSION 3.12)

project(VulkanTextureSample)

# currently using unicode in some libraries on win32 but will change soon
ADD_DEFINITIONS(-DUNICODE)
ADD_DEFINITIONS(-D_UNICODE)

if (WIN32)
	# shaderc_combined.lib in Vulkan requires this for debug & release (runtime shader compiling)
	set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} /MD")
	add_executable (VulkanTextureSample main.cpp renderer.h)
	target_include_directories(VulkanTextureSample PUBLIC $ENV{VULKAN_SDK}/Include/)
	target_link_directories(VulkanTextureSample PUBLIC $ENV{VULKAN_SDK}/Lib/)
	#target_link_directories(VulkanTextureSample PUBLIC ${CMAKE_SOURCE_DIR}/ktx/lib/win32/Debug)
endif(WIN32)

if(UNIX AND NOT APPLE)
	# libshaderc_combined.a is required for runtime shader compiling
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pthread -lX11 -lshaderc_combined")
    find_package(X11)
	find_package(Vulkan REQUIRED)
    link_libraries(${X11_LIBRARIES})
    include_directories(${X11_INCLUDE_DIR})
    include_directories(${Vulkan_INCLUDE_DIR}) 
	#link_directories(${Vulkan_LIBRARY}) this is currently not working
	link_libraries(${Vulkan_LIBRARIES})
	# the path is (properly)hardcoded because "${Vulkan_LIBRARY}" currently does not 
	# return a proper path on MacOS (it has the .dynlib appended)
    link_libraries(/usr/lib/x86_64-linux-gnu/libshaderc_combined.a)
    add_executable (VulkanTextureSample main.cpp renderer.h)
endif(UNIX AND NOT APPLE)

if(APPLE)
	set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -fmodules -fcxx-modules")
	set(Architecture ${CMAKE_OSX_ARCHITECTURES})
	find_package(Vulkan REQUIRED)
	include_directories(${Vulkan_INCLUDE_DIR}) 
	#link_directories(${Vulkan_LIBRARY}) this is currently not working
	link_libraries(${Vulkan_LIBRARIES})
	# libshaderc_combined.a is required for runtime shader compiling
	# the path is (properly)hardcoded because "${Vulkan_LIBRARY}" currently does not 
	# return a proper path on MacOS (it has the .dynlib appended)
	link_libraries(/usr/local/lib/libshaderc_combined.a)
	add_executable (VulkanTextureSample main.mm)
endif(APPLE)


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
	
	target_link_libraries(VulkanTextureSample debug ${KTX_LIB_D} optimized ${KTX_LIB_R})
	target_link_libraries(VulkanTextureSample debug ${KTX_READ_LIB_D} optimized ${KTX_READ_LIB_R})
	target_link_libraries(VulkanTextureSample debug ${OBJUTIL_LIB_D} optimized ${OBJUTIL_LIB_R})
endif(WIN32)

# TODO: other platforms here
