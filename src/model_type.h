/***************************************************************************
 * 
 * Copyright (c) 2023 Wang Tao. All Rights Reserved
 * $Id$ 
 * 
 **************************************************************************/
 
 /**
 * @file model_type.h
 * @author wangtao(wtzhuque@163.com)
 * @date 2023/09/04 13:38:41
 * @version $Revision$ 
 * @brief 
 *  
 **/
#ifndef MINLLM_MODEL_TYPE_H
#define MINLLM_MODEL_TYPE_H

namespace minllm {

using model_type_t = int;

const model_type_t MODEL_TYPE_UNKNOWN = -1;
const model_type_t MODEL_TYPE_LLAMA = 1;

} // namespace minllm

#endif  //MINLLM_MODEL_TYPE_H

/* vim: set ts=4 sw=4 sts=4 tw=100 */
