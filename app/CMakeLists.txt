# CMake的编译脚本配置文件

# 1. 标注需要支持的CMake最小版本
cmake_minimum_required(VERSION 3.4.1)

# 2. add_library 定义需要编译的代码库 名称, 类型, 包含的源码
file(GLOB native_srcs "src/main/jni/*.cpp")  ## 这个配置是编译jni目录下的所有cpp文件
add_library(
        # Sets the name of the library.
        FoolTools
        # Sets the library as a shared library.
        SHARED
        ${native_srcs}
        #        src/main/jni/native-lib.cpp src/main/jni/FoolTools.cpp # 多个文件可以用空格隔开
)

# 3. find_library 定义当前代码库需要依赖的系统或者第三方库文件(可以写多个)
find_library(
        log_lib # 指定要查找的系统库, 给一个名字
        log     # 真正要查找的liblog.so或者liblog.a
)

# 4. target_link_libraries设置最终编译的目标代码库
target_link_libraries(
        FoolTools  # add_library 生成的
        ${log_lib} # find_library 找到的系统库
)
