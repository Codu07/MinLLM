cmake_minimum_required(VERSION 3.1...3.19)

project(MinLLM C CXX)

set(CMAKE_CXX_STANDARD 20) 
set(CMAKE_CXX_STANDARD_REQUIRED True)

include(FindProtobuf)

# look for cxxopt
find_path(CXXOPTS_INCLUDE_PATH NAMES cxxopts.hpp)
if (NOT CXXOPTS_INCLUDE_PATH)
    message(FATAL_ERROR "Failed to find cxxopts")
endif()
include_directories(${CXXOPTS_INCLUDE_PATH})

# look for fmtlib
find_path(FMTLIB_INCLUDE_PATH NAMES fmt/core.h)
find_library(FMT_LIB NAMES libfmt.a fmt)
if((NOT FMTLIB_INCLUDE_PATH) OR (NOT FMT_LIB))
    message(FATAL_ERROR "Failed to find fmtlib")
endif()
include_directories(${FMTLIB_INCLUDE_PATH})

# look for spdlog
find_path(SPDLOG_INCLUDE_PATH NAMES spdlog/spdlog.h)
find_library(SPDLOG_LIB NAMES libspdlog.a spdlog)
if((NOT SPDLOG_INCLUDE_PATH) OR (NOT SPDLOG_LIB))
    message(FATAL_ERROR "Failed to find spdlog")
endif()
include_directories(${SPDLOG_INCLUDE_PATH})

# look for yaml-cpp
find_path(YAMLCPP_INCLUDE_PATH NAMES yaml-cpp/yaml.h)
find_library(YAMLCPP_LIB NAMES libyaml-cpp.a yaml-cpp)
if((NOT YAMLCPP_INCLUDE_PATH) OR (NOT YAMLCPP_LIB))
    message(FATAL_ERROR "Failed to find spdlog")
endif()
include_directories(${YAMLCPP_INCLUDE_PATH})

# look for leveldb
find_path(LEVELDB_INCLUDE_PATH NAMES leveldb/db.h)
find_library(LEVELDB_LIB NAMES leveldb)
if ((NOT LEVELDB_INCLUDE_PATH) OR (NOT LEVELDB_LIB))
    message(FATAL_ERROR "Fail to find leveldb")
endif()
include_directories(${LEVELDB_INCLUDE_PATH})

# look for brpc
find_path(BRPC_INCLUDE_PATH NAMES brpc/server.h PATHS /usr/local/include/brpc)
if(LINK_SO)
    find_library(BRPC_LIB NAMES brpc)
else()
    find_library(BRPC_LIB NAMES libbrpc.a brpc)
endif()
if((NOT BRPC_INCLUDE_PATH) OR (NOT BRPC_LIB))
    message(FATAL_ERROR "Fail to find brpc")
endif()
include_directories(${BRPC_INCLUDE_PATH})

# look for gflags
find_path(GFLAGS_INCLUDE_PATH gflags/gflags.h)
find_library(GFLAGS_LIBRARY NAMES gflags libgflags)
if((NOT GFLAGS_INCLUDE_PATH) OR (NOT GFLAGS_LIBRARY))
    message(FATAL_ERROR "Fail to find gflags")
endif()
include_directories(${GFLAGS_INCLUDE_PATH})

# look for openssl
find_package(OpenSSL)
include_directories(${OPENSSL_INCLUDE_DIR})

set(CMAKE_CXX_FLAGS "${CMAKE_CPP_FLAGS} -O2 -std=c++2a -D__const__= -pipe -W -Wall -Wno-unused-parameter -fPIC -fno-omit-frame-pointer")

set(LIBS
    ${FMT_LIB}
    ${SPDLOG_LIB}
    ${YAMLCPP_LIB}
    ${BRPC_LIB}
    ${GFLAGS_LIBRARY}
    ${PROTOBUF_LIBRARIES}
    ${LEVELDB_LIB}
    ${OPENSSL_CRYPTO_LIBRARY}
    ${OPENSSL_SSL_LIBRARY}
    dl
    z
    )

aux_source_directory(./src DIR_SRCS)

add_executable(panda ${DIR_SRCS} ${DIR_IDLS})
target_link_libraries(panda ${LIBS})
