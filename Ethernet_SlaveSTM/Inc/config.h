#ifndef __CONFIG_H__
#define __CONFIG_H__

#ifdef __cplusplus
extern "C" {
#endif

#include "stm32h7xx_hal.h"
#include "string.h"

UART_HandleTypeDef 							UartHandle1;
PCD_HandleTypeDef 							PcdHandle;
ETH_TxPacketConfig 							TxPackConfig;
ETH_HandleTypeDef 							EthHandle;

void Error_Handler(void);
void SystemClock_Config(void);
void GpioConfig(void);
void UartConfig(void);
void UsbOtgFsPcdConfig(void);
void EthConfig(void);

/* Push-Buttons & Leds */
#define B1_Pin 								GPIO_PIN_13
#define B1_GPIO_Port 						GPIOC
#define LD1_Pin 							GPIO_PIN_0
#define LD1_GPIO_Port 						GPIOB
#define LD2_Pin 							GPIO_PIN_1
#define LD2_GPIO_Port 						GPIOE
#define LD3_Pin 							GPIO_PIN_14
#define LD3_GPIO_Port 						GPIOB

/* STLink Pins - USART3 */
#define STLINK_RX_Pin 						GPIO_PIN_8
#define STLINK_RX_GPIO_Port 				GPIOD
#define STLINK_TX_Pin 						GPIO_PIN_9
#define STLINK_TX_GPIO_Port 				GPIOD

/* USB OTG Pins */
#define USB_OTG_FS_PWR_EN_Pin 				GPIO_PIN_10
#define USB_OTG_FS_PWR_EN_GPIO_Port 		GPIOD
#define USB_OTG_FS_OVCR_Pin 				GPIO_PIN_7
#define USB_OTG_FS_OVCR_GPIO_Port 			GPIOG



#ifdef __cplusplus
}
#endif

#endif /* __CONFIG_H__ */

