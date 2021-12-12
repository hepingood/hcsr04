/**
 * Copyright (c) 2015 - present LibDriver All rights reserved
 * 
 * The MIT License (MIT)
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE. 
 *
 * @file      driver_hcsr04_basic.h
 * @brief     driver hcsr04 basic header file
 * @version   2.0.0
 * @author    Shifeng Li
 * @date      2021-04-15
 *
 * <h3>history</h3>
 * <table>
 * <tr><th>Date        <th>Version  <th>Author      <th>Description
 * <tr><td>2021/04/15  <td>2.0      <td>Shifeng Li  <td>format the code
 * <tr><td>2020/12/21  <td>1.0      <td>Shifeng Li  <td>first upload
 * </table>
 */

#ifndef _DRIVER_HCSR04_BASIC_H_
#define _DRIVER_HCSR04_BASIC_H_

#include "driver_hcsr04_interface.h"

#ifdef __cplusplus
extern "C"{
#endif

/**
 * @defgroup hcsr04_example_driver hcsr04 example driver function
 * @brief    hcsr04 example driver modules
 * @ingroup  hcsr04_driver
 * @{
 */

/**
 * @brief  basic example init
 * @return status code
 *         - 0 success
 *         - 1 init failed
 * @note   none
 */
uint8_t hcsr04_basic_init(void);

/**
 * @brief  basic example deinit
 * @return status code
 *         - 0 success
 *         - 1 deinit failed
 * @note   none
 */
uint8_t hcsr04_basic_deinit(void);

/**
 * @brief      basic example read
 * @param[out] *m points to a distance buffer
 * @return     status code
 *             - 0 success
 *             - 1 read failed
 * @note       none
 */
uint8_t hcsr04_basic_read(float *m);

/**
 * @}
 */

#ifdef __cplusplus
}
#endif

#endif
