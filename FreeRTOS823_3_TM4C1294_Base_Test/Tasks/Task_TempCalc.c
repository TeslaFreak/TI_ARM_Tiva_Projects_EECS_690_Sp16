/*--Task_TempCalc.c
 *
 *  Author:			Chris Allmon
 *	Organization:	KU/EECS/EECS 690
 *  Date:			April 14, 2016
 *
 *  Description: Transmits data via UART to PC.
 *
 */
#include <stddef.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdarg.h>
#include "Drivers/uartstdio.h"
#include "Tasks/Task_ReportData.h"
#include "FreeRTOS.h"
#include "task.h"
#include "queue.h"
//
// Define the ReportData Queue
//
extern QueueHandle_t Temp_Queue = NULL;

extern uint32_t UART_Initialization();
//
// Define the ReportData Task
//
extern void Task_ReportData( void *pvParameters ) {
	ReportData_Item theReport;
	BaseType_t ReportQueue_Status;
	//
	// Insure UARTStdio is initialized
	//
	UART_Initialization();
	//
	// Define Temp_Queue
	//
	Temp_Queue = xQueueCreate( 10, sizeof( ReportData_Item ) );

	while ( 1 ) {
	//
	// Try to read ReportItem from ReportData_Queue.
	// If a ReportData_Item is returned, print the contents
	//     to the UART via UARTStdioPrintf
	//
		ReportQueue_Status = xQueueReceive( Temp_Queue,
						&theReport,
						 10 * portTICK_PERIOD_MS );
		if ( ReportQueue_Status == pdTRUE ) {
			UARTprintf( "%08d,%02d,%d,%d\n",
					theReport.TimeStamp, theReport.ReportName,
					theReport.ReportValue_0, theReport.ReportValue_1 );
		}
	}
}


