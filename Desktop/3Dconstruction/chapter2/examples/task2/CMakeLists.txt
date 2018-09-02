project(task2)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS "-fPIC")

include_directories("../..")

set(VISUAL_HEADER visualizer.h)
set(VISUAL_SOURCE visualizer.cc)

# test homography
set(HOMOGRAPHY_FILE
        class2_test_homography.cc)
add_executable(task2_test_homography ${HOMOGRAPHY_FILE} ${VISUAL_HEADER} ${VISUAL_SOURCE})
target_link_libraries(task2_test_homography sfm util core features )


set(TRIANGLE_FILE
        class2_test_triangle.cc)
add_executable(task2_test_triangle ${TRIANGLE_FILE})
target_link_libraries(task2_test_triangle sfm util core)


set(P3P_FILE
        class2_test_p3p.cc)
add_executable(task2_test_p3p ${P3P_FILE})
target_link_libraries(task2_test_p3p sfm util core features)

# test bundle adjustment
set(BA_FILES
        class2_test_bundle_adjustment.cc)
add_executable(task2_test_ba ${BA_FILES})
target_link_libraries(task2_test_ba sfm util core features)




