/***************************************************************************
 * 
 * Copyright (c) 2023 Wang Tao. All Rights Reserved
 * $Id$ 
 * 
 **************************************************************************/
 
 /**
 * @file error.h
 * @author wangtao(wtzhuque@163.com)
 * @date 2023/09/04 13:17:50
 * @version $Revision$ 
 * @brief 
 *  
 **/
#ifndef MINLLM_ERROR_H
#define MINLLM_ERROR_H

namespace minllm {

using error_type_t = int;

const error_type_t ERROR_SUCC = 0;

// ERROR defines
const error_type_t ERROR_UNKNOWN = -1;
const error_type_t ERROR_NOT_IMPL = -2;
const error_type_t ERROR_CONFIG_ERROR = -3;

// SUCC defines

} // namespace minllm

#endif  //MINLLM_ERROR_H

/* vim: set ts=4 sw=4 sts=4 tw=100 */
