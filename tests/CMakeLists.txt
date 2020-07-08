
FILE(GLOB SOURCES "*.cpp*")
FILE(GLOB HEADERS "*.h*")

add_executable(RBTreeTest ${SOURCES} ${HEADERS})
target_link_libraries(RBTreeTest RBTree gtest_main gtest gmock)
