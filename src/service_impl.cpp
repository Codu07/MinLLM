/***************************************************************************
 * 
 * Copyright (c) 2023 Wang Tao. All Rights Reserved
 * $Id$ 
 * 
 **************************************************************************/
 
 /**
 * @file service_impl.cpp
 * @author wangtao(wtzhuque@163.com)
 * @date 2023/09/06 11:33:10
 * @version $Revision$ 
 * @brief 
 *  
 **/

#include "service_impl.h"

namespace minllm {

void ServiceImpl::chat(::google::protobuf::RpcController* controller,
                       const ::minllm::ChatRequest* request,
                       ::minllm::ChatResponse* response,
                       ::google::protobuf::Closure* done) {

}

} // namespace minllm

/* vim: set ts=4 sw=4 sts=4 tw=100 */
