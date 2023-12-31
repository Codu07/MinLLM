/***************************************************************************
 * 
 * Copyright (c) 2023 Wang Tao. All Rights Reserved
 * $Id$ 
 * 
 **************************************************************************/
 
 /**
 * @file server.cpp
 * @author wangtao(wtzhuque@163.com)
 * @date 2023/09/04 21:36:29
 * @version $Revision$ 
 * @brief 
 *  
 **/

#include "server.h"

namespace minllm {

Server::Server()
    : _impl(new ServiceImpl()) {
}

Server::~Server() {
    delete _impl;
    _impl = nullptr;
}

int Server::init(Configure* conf) {
    return 0;
}

int Server::destroy() {
    return 0;
}

int Server::start_on_port(int port) {
    return 0;
}

int Server::wait_to_exit() {
    return 0;
}

} // namespace minllm

/* vim: set ts=4 sw=4 sts=4 tw=100 */
