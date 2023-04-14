file(GLOB_RECURSE INCLUDES CONFIGURE_DEPENDS ${CMAKE_CURRENT_SOURCE_DIR}/*.h)
file(GLOB_RECURSE SOURCES CONFIGURE_DEPENDS ${CMAKE_CURRENT_SOURCE_DIR}/*.cpp)

target_include_directories(
        mini-java
        PUBLIC
        .
)

target_sources(
        mini-java
        PRIVATE
        ${SOURCES}
        PUBLIC
        ${INCLUDES}
)