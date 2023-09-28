/*==================================================================================*
 * File        : ADC_CFG.h  														*
 * Description :																   	*
 * Author      : Mahmoud Gharib Embedded SW Engineer 								*		
 * Date        :																	*		
 * Git account : https://github.com/Mahmoud-Gharib									*		
 * mail        : mahmoudgharib99999@gmail.com 										*		
 *==================================================================================*/
#ifndef ADC_CFG_H_
#define ADC_CFG_H_
/* VOLTAGE_REFERENCE OPTIONS ->  [ AVCC_PIN , AREF_PIN , INTERNAL2V ]*/
#define  VOLTAGE_REFERENCE           AVCC_PIN
/* ADSUST OPTIONS ->  [ RIGHT_ADJUST , LEFT_ADJUST  ]*/
#define  ADJUST                      RIGHT_ADJUST
/* ADC_CHANNEL OPTIONS ->  [ CHANNEL_0 ..... CHANNEL_7 ]*/
#define ADC_CHANNEL                  CHANNEL_0
/* PRESCALER_DIVISION_FACTOR OPTIONS ->  [ DIVISION_BY_2 .4.8.16.32.64. DIVISION_BY_128 ]*/
#define PRESCALER_DIVISION_FACTOR    DIVISION_BY_128

#define MODE_SELECTION   AUTO_TRIGGER_MODE
#endif 