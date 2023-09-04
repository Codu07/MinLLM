/***************************************************************************
 * 
 * Copyright (c) 2023 Wang Tao. All Rights Reserved
 * $Id$ 
 * 
 **************************************************************************/
 
 /**
 * @file predictor.h
 * @author wangtao(wtzhuque@163.com)
 * @date 2023/09/04 13:34:56
 * @version $Revision$ 
 * @brief 
 *  
 **/
#ifndef MINLLM_PREDICTOR_H
#define MINLLM_PREDICTOR_H

namespace minllm {

class Predictor {
public:
    Predictor() {}

    virtual ~Predictor() {}
}; // class Predictor

} // namespace minllm

#endif  //MINLLM_PREDICTOR_H

/* vim: set ts=4 sw=4 sts=4 tw=100 */
