/***************************************************************************
 * 
 * Copyright (c) 2023 Wang Tao. All Rights Reserved
 * $Id$ 
 * 
 **************************************************************************/
 
 /**
 * @file service_impl.h
 * @author wangtao(wtzhuque@163.com)
 * @date 2023/09/06 11:33:03
 * @version $Revision$ 
 * @brief 
 *  
 **/
#ifndef MINLLM_SERVICE_IMPL_H
#define MINLLM_SERVICE_IMPL_H

#include "../idl/panda.pb.h"

namespace minllm {

class ServiceImpl : public Panda {
public:
    virtual void chat(::google::protobuf::RpcController* controller,
                      const ::minllm::ChatRequest* request,
                      ::minllm::ChatResponse* response,
                      ::google::protobuf::Closure* done);
}; // class ServiceImpl

} // namespace minllm

#endif  //MINLLM_SERVICE_IMPL_H

/* vim: set ts=4 sw=4 sts=4 tw=100 */
