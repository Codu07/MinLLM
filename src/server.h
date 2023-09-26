/***************************************************************************
 * 
 * Copyright (c) 2023 Wang Tao. All Rights Reserved
 * $Id$ 
 * 
 **************************************************************************/
 
 /**
 * @file server.h
 * @author wangtao(wtzhuque@163.com)
 * @date 2023/09/04 21:36:24
 * @version $Revision$ 
 * @brief 
 *  
 **/
#ifndef MINLLM_SERVER_H
#define MINLLM_SERVER_H

#include "conf.h"
#include "service_impl.h"

namespace minllm {

class Server {
public:
    Server();

    ~Server();

    int init(Configure* conf);

    int destroy();

    int start_on_port(int port);

    int wait_to_exit();

private:
    ServiceImpl* _impl {nullptr};
}; // class Server

} // namespace minllm

#endif  //MINLLM_SERVER_H

/* vim: set ts=4 sw=4 sts=4 tw=100 */
