/**
 ******************************************************************************
 *  @file SMA_filter_lib.c
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

#include "SMA_filter_lib.h"

/* Создать в main.c ----------------------------------------------------------------*/
  //uint16_t Filter_Buffer_1[SMA_FILTER_ORDER] = { 0, };
/*----------------------------------------------------------------------------------*/


/**
 ******************************************************************************
 *  @breif Функция получения отфильтрованного значения(SMA Filter)
 *  @param  *Filter_buffer - Массив, где будут лежать сырые значения 
 *  @param  *Data - Сырые данные	         
 *  @retval  Result - Значение, полученное после SMA фильтра.
 ******************************************************************************
 */
uint16_t SMA_FILTER_Get_Value(uint16_t *Filter_buffer, uint16_t *Data) {
	
	/* Создадим переменную для суммы сырых значений */
	uint32_t Result = 0;
	
	/* Начнем заполнять массив сырыми значениями с конца */
	Filter_buffer[SMA_FILTER_ORDER - 1] = *Data;
	
	/* Просуммируем все элементы массива */
	for (uint8_t i = 0; i < SMA_FILTER_ORDER; i++) {
		Result += Filter_buffer[i];
	}
	
	/*
	 * Найдем среднее арифметическое значение:
	 * Пример: SMA_FILTER_ORDER = 32;
	 * 32 = 2*2*2*2*2;
	 * Тогда Result = Result/32 будет равен, как Result = Result >> 5u;
	 *
	 */
	
	//Result = Result / SMA_FILTER_ORDER;
	Result = Result >> 5u; //32 = 2^5;
		
	/* Сдвинем все элементы массива влево на 1 */
	for (uint8_t i = 0; i < SMA_FILTER_ORDER; i++) {
		Filter_buffer[i] = Filter_buffer[i + 1];
	}
	
	return (uint16_t)Result; //Вернем среднее арифметическое значение
}
