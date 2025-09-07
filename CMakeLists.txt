cmake_minimum_required(VERSION 3.16)    # 最低版本要求
project(WindDeskTool VERSION 1.0.0 LANGUAGES CXX)   # 项目名称 版本 语言

set(CMAKE_AUTOUIC ON)    # 自动处理UI文件
set(CMAKE_AUTOMOC ON)    # 自动处理MOC文件
set(CMAKE_AUTORCC ON)    # 自动处理资源文件

set(CMAKE_CXX_STANDARD 17)    # C++标准
set(CMAKE_CXX_STANDARD_REQUIRED ON)    # 要求使用C++标准

find_package(Qt6 REQUIRED COMPONENTS Widgets)   # 查找库

set(EXEC_PATH ${CMAKE_SOURCE_DIR}/bin) # 设置可执行文件输出目录
set(LIB_PATH ${CMAKE_SOURCE_DIR}/bin)   # 设置库文件输出目录

set(EXECUTABLE_OUTPUT_PATH ${EXEC_PATH}) # 可执行文件输出目录

# 添加子目录
add_subdirectory(main)

qt_add_executable(
    ${PROJECT_NAME} # 项目名称
    MANUAL_FINALIZATION # 手动最终化
)   # 生产可执行文件

target_link_libraries(${PROJECT_NAME} PRIVATE
    # QT
    Qt6::Core
    Qt6::Widgets
    # 自定义
    main
)   # 链接库

set_target_properties(
    ${PROJECT_NAME} PROPERTIES
    # 控制台 ON不生成 OFF生成
    # WIN32_EXECUTABLE ON
    WIN32_EXECUTABLE OFF
)

qt_finalize_executable(${PROJECT_NAME}) # 手动完成
