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
 * @file      main.c
 * @brief     main source file
 * @version   1.0.0
 * @author    Shifeng Li
 * @date      2021-04-15
 *
 * <h3>history</h3>
 * <table>
 * <tr><th>Date        <th>Version  <th>Author      <th>Description
 * <tr><td>2021/04/15  <td>1.0      <td>Shifeng Li  <td>first upload
 * </table>
 */

#include "driver_hcsr04_basic.h"
#include "driver_hcsr04_read_test.h"
#include <stdlib.h>

/**
 * @brief     hcsr04 full function
 * @param[in] argc is arg numbers
 * @param[in] **argv is the arg address
 * @return    status code
 *             - 0 success
 *             - 1 run failed
 *             - 5 param is invalid
 * @note      none
 */
uint8_t hcsr04(uint8_t argc, char **argv)
{
    if (argc == 1)
    {
        goto help;
    }
    else if (argc == 2)
    {
        if (strcmp("-i", argv[1]) == 0)
        {
            hcsr04_info_t info;
            
            /* print hcsr04 information */
            hcsr04_info(&info);
            hcsr04_interface_debug_print("hcsr04: chip is %s.\n", info.chip_name);
            hcsr04_interface_debug_print("hcsr04: manufacturer is %s.\n", info.manufacturer_name);
            hcsr04_interface_debug_print("hcsr04: interface is %s.\n", info.interface);
            hcsr04_interface_debug_print("hcsr04: driver version is %d.%d.\n", info.driver_version/1000, (info.driver_version%1000)/100);
            hcsr04_interface_debug_print("hcsr04: min supply voltage is %0.1fV.\n", info.supply_voltage_min_v);
            hcsr04_interface_debug_print("hcsr04: max supply voltage is %0.1fV.\n", info.supply_voltage_max_v);
            hcsr04_interface_debug_print("hcsr04: max current is %0.2fmA.\n", info.max_current_ma);
            hcsr04_interface_debug_print("hcsr04: max temperature is %0.1fC.\n", info.temperature_max);
            hcsr04_interface_debug_print("hcsr04: min temperature is %0.1fC.\n", info.temperature_min);
            
            return 0;
        }
        else if (strcmp("-p", argv[1]) == 0)
        {
            /* print pin connection */
            hcsr04_interface_debug_print("hcsr04: trig pin connected to GPIO27(BCM).\n");
            hcsr04_interface_debug_print("hcsr04: echo pin connected to GPIO17(BCM).\n");
            
            return 0;
        }
        else if (strcmp("-h", argv[1]) == 0)
        {
            help:
            
            hcsr04_interface_debug_print("hcsr04 -h\n\tshow hcsr04 help.\n");
            hcsr04_interface_debug_print("hcsr04 -i\n\tshow hcsr04 chip and driver information.\n");
            hcsr04_interface_debug_print("hcsr04 -p\n\tshow hcsr04 pin connections of the current board.\n");
            hcsr04_interface_debug_print("hcsr04 -t read <times>\n\trun hcsr04 read test.times means the test times.\n");
            hcsr04_interface_debug_print("hcsr04 -c read <times>\n\trun hcsr04 read function.times means the read times.\n");
            
            return 0;
        }
        /* param is invalid */
        else
        {
            return 5;
        }
    }
    else if (argc == 4)
    {
        /* run test */
        if (strcmp("-t", argv[1]) == 0)
        {
            /* read test */
            if (strcmp("read", argv[2]) == 0)
            {
                /* run read test */
                if (hcsr04_read_test(atoi(argv[3])) != 0)
                {
                    return 1;
                }
                else
                {
                    return 0;
                }
            }
            /* param is invalid */
            else
            {
                return 5;
            }
        }
        /* run common function */
        else if (strcmp("-c", argv[1]) == 0)
        {
            /* function read */
            if (strcmp("read", argv[2]) == 0)
            {
                uint8_t res;
                uint32_t times;
                uint32_t i;
                float m;
                
                res = hcsr04_basic_init();
                if (res != 0)
                {
                    return 1;
                }
                times = atoi(argv[3]);
                for (i = 0; i < times; i++)
                {
                    res = hcsr04_basic_read((float *)&m);
                    if (res != 0)
                    {
                        (void)hcsr04_basic_deinit();
                        
                        return 1;
                    }
                    hcsr04_interface_delay_ms(1000);
                    hcsr04_interface_debug_print("hcsr04: %d/%d.\n", (uint32_t)(i+1), (uint32_t)times);
                    hcsr04_interface_debug_print("hcsr04: distance is %0.4fm.\n", m); 
                }
                (void)hcsr04_basic_deinit();
                
                return 0;
            }
            /* param is invalid */
            else
            {
                return 5;
            }
        }
        /* param is invalid */
        else
        {
            return 5;
        }
    }
    /* param is invalid */
    else
    {
        return 5;
    }
}

/**
 * @brief     main function
 * @param[in] argc is arg numbers
 * @param[in] **argv is the arg address
 * @return    status code
 *             - 0 success
 * @note      none
 */
int main(uint8_t argc, char **argv)
{
    uint8_t res;

    res = hcsr04(argc, argv);
    if (res == 0)
    {
        /* run success */
    }
    else if (res == 1)
    {
        hcsr04_interface_debug_print("hcsr04: run failed.\n");
    }
    else if (res == 5)
    {
        hcsr04_interface_debug_print("hcsr04: param is invalid.\n");
    }
    else
    {
        hcsr04_interface_debug_print("hcsr04: unknow status code.\n");
    }

    return 0;
}
