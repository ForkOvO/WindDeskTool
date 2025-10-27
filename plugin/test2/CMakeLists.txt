cmake_minimum_required(VERSION 3.16) # 最低版本要求
project(test2) # 项目名称

set(LIBRARY_OUTPUT_PATH ${PLUGIN_PATH}) # 动态库输出目录

aux_source_directory(. TEST2_SRC) # 源文件目录
add_library(${PROJECT_NAME} SHARED ${TEST2_SRC}) # 生成动态库

target_link_libraries(${PROJECT_NAME}
    Qt6::Core
    Qt6::Widgets
) # 链接Qt库
