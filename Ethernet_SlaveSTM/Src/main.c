#include "config.h"

int main(void){
	HAL_Init();
	SystemClock_Config();
	GpioConfig();
	UartConfig();
	UsbOtgFsPcdConfig();
	EthConfig();
	while (1){
	}

}
