/*
 * Copyright (c) 2015-2016, Texas Instruments Incorporated
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * *  Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 *
 * *  Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * *  Neither the name of Texas Instruments Incorporated nor the names of
 *    its contributors may be used to endorse or promote products derived
 *    from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
 * THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR
 * CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS;
 * OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
 * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR
 * OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
 * EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

/*
 *  ======== main.c ========
 */
/* XDCtools Header files */
#include <xdc/std.h>
#include <xdc/runtime/System.h>

/* BIOS Header files */
#include <ti/sysbios/BIOS.h>
#include <ti/sysbios/knl/Clock.h>
#include <ti/sysbios/knl/Task.h>

/* TI-RTOS Header files */
// #include <ti/drivers/I2C.h>
#include <ti/drivers/PIN.h>
// #include <ti/drivers/SPI.h>
// #include <ti/drivers/UART.h>
// #include <ti/drivers/Watchdog.h>

/* Board Header files */
#include "Board.h"

#define TASKSTACKSIZE   512

Task_Struct task0Struct;
Char task0Stack[TASKSTACKSIZE];
Task_Struct task1Struct;
Char task1Stack[TASKSTACKSIZE];

Task_Params task1Params;

static bool ledTaskIsRunning = 0;

/* Pin driver handle */
static PIN_Handle ledPinHandle;
static PIN_Handle buttonPinHandle;
static PIN_State ledPinState;
static PIN_State buttonPinState;

/*
 * Application LED pin configuration table:
 *   - All LEDs board LEDs are off.
 */
PIN_Config ledPinTable[] = {
    Board_LED0 | PIN_GPIO_OUTPUT_EN | PIN_GPIO_LOW | PIN_PUSHPULL | PIN_DRVSTR_MAX,
    Board_LED1 | PIN_GPIO_OUTPUT_EN | PIN_GPIO_LOW | PIN_PUSHPULL | PIN_DRVSTR_MAX,
    PIN_TERMINATE
};

/*
 * Application button pin configuration table:
 *   - Buttons interrupts are configured to trigger on falling edge.
 */
PIN_Config buttonPinTable[] = {
    Board_BUTTON0  | PIN_INPUT_EN | PIN_PULLUP | PIN_IRQ_NEGEDGE,
    Board_BUTTON1  | PIN_INPUT_EN | PIN_PULLUP | PIN_IRQ_NEGEDGE,
    PIN_TERMINATE
};

/*
 *  ======== heartBeatFxn ========
 *  Toggle the Board_LED0. The Task_sleep is determined by arg0 which
 *  is configured for the heartBeat Task instance.
 */
Void heartBeatFxn0(UArg arg0, UArg arg1)
{
    while (1) {
        Task_sleep((UInt)arg0);

        /*
        ledFlashCounter++;
        if (ledFlashCounter >= 7)
            System_exit(0);
        */
        PIN_setOutputValue(ledPinHandle, Board_LED0,
                           !PIN_getOutputValue(Board_LED0));
    }
}

Void heartBeatFxn1(UArg arg0, UArg arg1)
{
    while (1) {
        Task_sleep((UInt)arg0);

        /*
        ledFlashCounter++;
        if (ledFlashCounter >= 7)
            System_exit(0);
         */
        PIN_setOutputValue(ledPinHandle, Board_LED1,
                           !PIN_getOutputValue(Board_LED1));
    }
}

/*
 *  ======== buttonCallbackFxn ========
 *  Pin interrupt Callback function board buttons configured in the pinTable.
 *  If Board_LED3 and Board_LED4 are defined, then we'll add them to the PIN
 *  callback function.
 */
void buttonCallbackFxn(PIN_Handle handle, PIN_Id pinId) {
    uint32_t currVal = 0;

    /* Debounce logic, only toggle if the button is still pushed (low) */
    CPUdelay(8000*50);
    if (!PIN_getInputValue(pinId)) {
        /* Toggle LED based on the button pressed */
        switch (pinId) {

            case Board_BUTTON0:
                currVal =  PIN_getOutputValue(Board_LED0);
                PIN_setOutputValue(ledPinHandle, Board_LED0, !currVal);
                System_printf("Button 0 pressed\n");
                System_flush();
                break;

            case Board_BUTTON1:
                System_printf("Button 1 pressed\n");
                if (ledTaskIsRunning)  {
                    Task_destruct(&task1Struct);
                    ledTaskIsRunning = !ledTaskIsRunning;
                    PIN_setOutputValue(ledPinHandle, Board_LED1, 0);
                    System_printf("task LED1 destructed\n");
                }  else  {
                    Task_construct(&task1Struct, (Task_FuncPtr)heartBeatFxn1, &task1Params, NULL);
                    ledTaskIsRunning = !ledTaskIsRunning;
                    PIN_setOutputValue(ledPinHandle, Board_LED1, 1);
                    System_printf("task LED1 constructed\n");
                }
                System_flush();
                break;

            default:
                /* Do nothing */
                break;
        }
    }
}

/*
 *  ======== main ========
 */
int main(void)
{
    Task_Params task0Params;  // construct struct for task parameters


    /* Call board init functions */
    Board_initGeneral();
    // Board_initI2C();
    // Board_initSPI();
    // Board_initUART();
    // Board_initWatchdog();

    /* Construct heartBeat Task  thread */
    Task_Params_init(&task0Params);  //initial task params struct
    task0Params.arg0 = 1000000 / Clock_tickPeriod;
    task0Params.stackSize = TASKSTACKSIZE;
    task0Params.stack = &task0Stack;
    Task_construct(&task0Struct, (Task_FuncPtr)heartBeatFxn0, &task0Params, NULL);  //start task
    System_printf("task LED0 constructed\n");
    System_flush();

    Task_Params_init(&task1Params);
    task1Params.arg0 = 600000 / Clock_tickPeriod;
    task1Params.stackSize = TASKSTACKSIZE;
    task1Params.stack = &task1Stack;
    //Task_construct(&task1Struct, (Task_FuncPtr)heartBeatFxn1, &task1Params, NULL);

    /* Open IO pins */
    ledPinHandle = PIN_open(&ledPinState, ledPinTable);  // open pin
    if(!ledPinHandle) {  //open failed
        System_abort("Error initializing board LED pins\n");
    }

    buttonPinHandle = PIN_open(&buttonPinState, buttonPinTable);
    if(!buttonPinHandle) {
        System_abort("Error initializing button pins\n");
    }

    //PIN_setOutputValue(ledPinHandle, Board_LED1, 1);  // set output pin value

    System_printf("Starting the example\nSystem provider is set to SysMin. "
                  "Halt the target to view any SysMin contents in ROV.\n");

    /* SysMin will only print to the console when you call flush or exit */
    System_flush();

    /* Setup callback for button pins */
    if (PIN_registerIntCb(buttonPinHandle, &buttonCallbackFxn) != 0) {
        System_abort("Error registering button callback function");
    }

    /* Start BIOS */

    BIOS_start();

    return (0);
}
