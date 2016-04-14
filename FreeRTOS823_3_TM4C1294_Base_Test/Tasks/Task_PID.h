/*--Task_PID.h
 *
 *  Author:			Chris Allmon
 *	Organization:	KU/EECS/EECS 690
 *  Date:			April 14, 2016
 *
 *  Description: Transmits data via UART to PC.
 *
 */
#ifndef TASKS_TASK_REPORTDATA_H_
#define TASKS_TASK_REPORTDATA_H_
#include <stddef.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdarg.h>
#include "Drivers/uartstdio.h"
#include "FreeRTOS.h"
#include "task.h"
#include "queue.h"
//
// Reference SysTickCount
//
extern volatile uint32_t xPortSysTickCount;
//
// Define the PID Task
//
extern void Task_PID( void *pvParameters );
//
// Define the PID Queue
//
extern QueueHandle_t PID_Queue;
//
// Define a structure to hold a data report
//
typedef struct ReportData_Item {uint32_t TimeStamp;
uint32_t ReportName;
uint32_t ReportValue_0;
uint32_t ReportValue_1; } ReportData_Item;
#endif /* TASKS_TASK_REPORTDATA_H_ */
