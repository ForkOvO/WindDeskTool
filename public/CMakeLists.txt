cmake_minimum_required(VERSION 3.16) # 最低版本要求
project(public) # 项目名称

set(LIBRARY_OUTPUT_PATH ${LIB_PATH}) # 可执行文件输出目录

aux_source_directory(. PUBLIC_SRC) # 源文件目录
add_library(${PROJECT_NAME} SHARED ${PUBLIC_SRC}) # 生成动态库

target_link_libraries(${PROJECT_NAME} Qt6::Core) # 链接Qt库
