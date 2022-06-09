/**
 ******************************************************************************
 *  @file SMA_filter_lib.h
 *  @brief Простое скользящее среднее, или арифметическое скользящее среднее 
 *  (англ. simple moving average, англ. SMA)
 *  @author Волков Олег
 *  @date 09.06.2022
 *
  ******************************************************************************
 * @attention
 * 
 *  Библиотека помогает отфильтровать данные с 12 битного АЦП микроконтроллера, 
 *  приведя показания к более устойчивым.
 *  
 *  YouTube: https://www.youtube.com/channel/UCzZKTNVpcMSALU57G1THoVw
 *  GitHub: https://github.com/Solderingironspb/Lessons-Stm32/blob/master/README.md
 *  Группа ВК: https://vk.com/solderingiron.stm32
 *
 ******************************************************************************
 */

#ifndef __SMA_FILTER_LIB_H
#define __SMA_FILTER_LIB_H

#ifdef __cplusplus
extern "C" {
#endif
	
#include "main.h"

#define SMA_FILTER_ORDER 32 /* Порядок SMA фильтра */

uint16_t SMA_FILTER_Get_Value(uint16_t *Filter_buffer, uint16_t *Data);

#ifdef __cplusplus
}
#endif

#endif /* __SMA_FILTER_LIB_H */
