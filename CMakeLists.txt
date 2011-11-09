project(sayayinshell)

find_package(KDE4 REQUIRED)
include (KDE4Defaults)

if(CMAKE_BUILD_TYPE STREQUAL "debug")
	set(ENABLE_DEBUG "On")
endif()

option(ENABLE_DEBUG "Enable debugging code")
if(ENABLE_DEBUG)
	add_definitions(-DDEBUG)
endif()


include_directories( ${KDE4_INCLUDES} ${QT_INCLUDES} )

add_subdirectory( doc )
add_subdirectory( src )
add_subdirectory( icons )
