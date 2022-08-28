/**
  ******************************************************************************
  * @file    main.c
  * @author  Ac6
  * @version V1.0
  * @date    01-December-2013
  * @brief   Default main function.
  ******************************************************************************
*/


#include "stm32f4xx.h"
#include "stdio.h"
#include "stdint.h"

#include "FreeRTOS.h"
#include "task.h"


TaskHandle_t xTaskHandle1=NULL;
TaskHandle_t xTaskHandle2=NULL;


void vTask1_handler(void *params);
void vTask2_handler(void *params);

//used for semihosting
extern void initialise_monitor_handles();


int main(void)
{

	initialise_monitor_handles();
	printf("example code\n");
	//1. Reset the RCC clock configuration to default reset state
	//hsi on, hse off, pll off, System clock = 16MHz
	RCC_DeInit();

	//2. Update the SystemCoreClock variable
	SystemCoreClockUpdate();


	//3. lets create 2 tasks , task-1 and task-2
	xTaskCreate( vTask1_handler,"Task-1", configMINIMAL_STACK_SIZE,NULL,2,&xTaskHandle1 );

	xTaskCreate( vTask2_handler,"Task-2", configMINIMAL_STACK_SIZE,NULL,2,&xTaskHandle2 );

	//4. Start the scheduler.
	vTaskStartScheduler();



	for(;;);
}


void vTask1_handler(void *params)
{
	while(1)
	{
		printf("hello world from task-1\n");
	}
}

void vTask2_handler(void *params)
{
	while(1)
	{
		printf("hello world from task-2\n");
	}
}







