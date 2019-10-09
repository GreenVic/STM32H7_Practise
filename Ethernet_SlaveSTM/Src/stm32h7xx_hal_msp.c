#include <config.h>

void HAL_MspInit(void){
	__HAL_RCC_SYSCFG_CLK_ENABLE();
}
void HAL_ETH_MspInit(ETH_HandleTypeDef* heth){
	GPIO_InitTypeDef GPIO_InitStruct = {0};
	if(heth->Instance==ETH){
		__HAL_RCC_ETH1MAC_CLK_ENABLE();
		__HAL_RCC_ETH1TX_CLK_ENABLE();
		__HAL_RCC_ETH1RX_CLK_ENABLE();
  
		__HAL_RCC_GPIOC_CLK_ENABLE();
		__HAL_RCC_GPIOA_CLK_ENABLE();
		__HAL_RCC_GPIOB_CLK_ENABLE();
		__HAL_RCC_GPIOG_CLK_ENABLE();
		/**ETH GPIO Configuration
    	PC1     ------> ETH_MDC
    	PA1     ------> ETH_REF_CLK
    	PA2     ------> ETH_MDIO
    	PA7     ------> ETH_CRS_DV
    	PC4     ------> ETH_RXD0
    	PC5     ------> ETH_RXD1
    	PB13     ------> ETH_TXD1
    	PG11     ------> ETH_TX_EN
    	PG13     ------> ETH_TXD0
		 */
		GPIO_InitStruct.Pin = GPIO_PIN_1|GPIO_PIN_4|GPIO_PIN_5;
		GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
		GPIO_InitStruct.Pull = GPIO_NOPULL;
		GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
		GPIO_InitStruct.Alternate = GPIO_AF11_ETH;
		HAL_GPIO_Init(GPIOC, &GPIO_InitStruct);

		GPIO_InitStruct.Pin = GPIO_PIN_1|GPIO_PIN_2|GPIO_PIN_7;
		GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
		GPIO_InitStruct.Pull = GPIO_NOPULL;
		GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
		GPIO_InitStruct.Alternate = GPIO_AF11_ETH;
		HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

		GPIO_InitStruct.Pin = GPIO_PIN_13;
		GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
		GPIO_InitStruct.Pull = GPIO_NOPULL;
		GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
		GPIO_InitStruct.Alternate = GPIO_AF11_ETH;
		HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

		GPIO_InitStruct.Pin = GPIO_PIN_11|GPIO_PIN_13;
		GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
		GPIO_InitStruct.Pull = GPIO_NOPULL;
		GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
		GPIO_InitStruct.Alternate = GPIO_AF11_ETH;
		HAL_GPIO_Init(GPIOG, &GPIO_InitStruct);
	}
}
void HAL_ETH_MspDeInit(ETH_HandleTypeDef* heth){
	if(heth->Instance==ETH){
		__HAL_RCC_ETH1MAC_CLK_DISABLE();
		__HAL_RCC_ETH1TX_CLK_DISABLE();
		__HAL_RCC_ETH1RX_CLK_DISABLE();
  
		/**ETH GPIO Configuration
    	PC1     ------> ETH_MDC
    	PA1     ------> ETH_REF_CLK
    	PA2     ------> ETH_MDIO
    	PA7     ------> ETH_CRS_DV
    	PC4     ------> ETH_RXD0
    	PC5     ------> ETH_RXD1
    	PB13     ------> ETH_TXD1
    	PG11     ------> ETH_TX_EN
    	PG13     ------> ETH_TXD0
		 */
		HAL_GPIO_DeInit(GPIOC, GPIO_PIN_1|GPIO_PIN_4|GPIO_PIN_5);
		HAL_GPIO_DeInit(GPIOA, GPIO_PIN_1|GPIO_PIN_2|GPIO_PIN_7);
		HAL_GPIO_DeInit(GPIOB, GPIO_PIN_13);
		HAL_GPIO_DeInit(GPIOG, GPIO_PIN_11|GPIO_PIN_13);
	}
}
void HAL_UART_MspInit(UART_HandleTypeDef* huart){
	GPIO_InitTypeDef GPIO_InitStruct = {0};
	if(huart->Instance==USART3){
		__HAL_RCC_USART3_CLK_ENABLE();
		__HAL_RCC_GPIOD_CLK_ENABLE();
		/**USART3 GPIO Configuration
    	PD8     ------> USART3_TX
    	PD9     ------> USART3_RX
		 */
		GPIO_InitStruct.Pin = STLINK_RX_Pin|STLINK_TX_Pin;
		GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
		GPIO_InitStruct.Pull = GPIO_NOPULL;
		GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
		GPIO_InitStruct.Alternate = GPIO_AF7_USART3;
		HAL_GPIO_Init(GPIOD, &GPIO_InitStruct);
	}
}
void HAL_UART_MspDeInit(UART_HandleTypeDef* huart){
	if(huart->Instance==USART3){
		__HAL_RCC_USART3_CLK_DISABLE();
		/**USART3 GPIO Configuration
    	PD8     ------> USART3_TX
    	PD9     ------> USART3_RX
		 */
		HAL_GPIO_DeInit(GPIOD, STLINK_RX_Pin|STLINK_TX_Pin);
	}
}
void HAL_PCD_MspInit(PCD_HandleTypeDef* hpcd){
	GPIO_InitTypeDef GPIO_InitStruct = {0};
	if(hpcd->Instance==USB_OTG_FS){
		__HAL_RCC_GPIOA_CLK_ENABLE();
		/**USB_OTG_FS GPIO Configuration
    	PA8     ------> USB_OTG_FS_SOF
    	PA9     ------> USB_OTG_FS_VBUS
    	PA11     ------> USB_OTG_FS_DM
    	PA12     ------> USB_OTG_FS_DP
		 */
		GPIO_InitStruct.Pin = GPIO_PIN_8|GPIO_PIN_11|GPIO_PIN_12;
		GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
		GPIO_InitStruct.Pull = GPIO_NOPULL;
		GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
		GPIO_InitStruct.Alternate = GPIO_AF10_OTG1_FS;
		HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

		GPIO_InitStruct.Pin = GPIO_PIN_9;
		GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
		GPIO_InitStruct.Pull = GPIO_NOPULL;
		HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

		/* Peripheral clock enable */
		__HAL_RCC_USB_OTG_FS_CLK_ENABLE();
	}
}
void HAL_PCD_MspDeInit(PCD_HandleTypeDef* hpcd){
	if(hpcd->Instance==USB_OTG_FS){
		__HAL_RCC_USB_OTG_FS_CLK_DISABLE();
		/**USB_OTG_FS GPIO Configuration
    	PA8     ------> USB_OTG_FS_SOF
    	PA9     ------> USB_OTG_FS_VBUS
    	PA11     ------> USB_OTG_FS_DM
    	PA12     ------> USB_OTG_FS_DP
		 */
		HAL_GPIO_DeInit(GPIOA, GPIO_PIN_8|GPIO_PIN_9|GPIO_PIN_11|GPIO_PIN_12);
	}
}
