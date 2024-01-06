cmake_minimum_required(VERSION 3.0.0)
project(test_20240105 VERSION 0.1.0 LANGUAGES C CXX)

include(CTest)
enable_testing()

set(CMAKE_BUILD_TYPE "Debug")
set(EXECUTABLE_OUTPUT_PATH "../bin/")

if(UNIX)

    set(OpenCV_DIR "./deps/opencv-output/")
    include_directories(${OpenCV_DIR}/include/)
    link_directories(${OpenCV_DIR}/lib/)
    set(OpenCV_LIBS libopencv_stitching.so
                    libopencv_objdetect.so
                    libopencv_superres.so
                    libopencv_dnn.so
                    libopencv_imgproc.so
                    libopencv_shape.so
                    libopencv_video.so
                    libopencv_flann.so
                    libopencv_calib3d.so
                    libopencv_core.so
                    libopencv_ml.so
                    libopencv_photo.so
                    libopencv_features2d.so
                    libopencv_highgui.so
                    libopencv_imgcodecs.so
                    libopencv_videostab.so
                    libopencv_videoio.so)

    set(spdlog_DIR "./deps/spdlog-output/")
    include_directories(${spdlog_DIR}/include/)
    link_directories(${spdlog_DIR}/lib/)
    set(spdlog_LIBS libspdlog.a)

    set(json_DIR "./deps/json-output/")
    include_directories(${json_DIR}/include/)

elseif(WIN32)

endif()

set(LIB_LIST ${OpenCV_LIBS} ${spdlog_LIBS})
set(SRC_LIST main.cpp)

add_executable(${PROJECT_NAME} ${SRC_LIST})
target_link_libraries(${PROJECT_NAME} ${LIB_LIST})

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
