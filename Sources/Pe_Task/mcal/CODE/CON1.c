/** ###################################################################
**     THIS COMPONENT MODULE IS GENERATED BY THE TOOL. DO NOT MODIFY IT.
**     Filename  : CON1.c
**     Project   : mcal
**     Processor : MC9S12XEP100MAG
**     Component : BitIO
**     Version   : Component 02.075, Driver 03.14, CPU db: 3.00.036
**     Compiler  : CodeWarrior HCS12X C Compiler
**     Date/Time : 2017/3/23, 21:47
**     Abstract  :
**         This component "BitIO" implements an one-bit input/output.
**         It uses one bit/pin of a port.
**         Note: This component is set to work in Output direction only.
**         Methods of this component are mostly implemented as a macros
**         (if supported by target language and compiler).
**     Settings  :
**         Used pin                    :
**             ----------------------------------------------------
**                Number (on package)  |    Name
**             ----------------------------------------------------
**                       76            |  PA3_ADDR11_IVD11
**             ----------------------------------------------------
**
**         Port name                   : A
**
**         Bit number (in port)        : 3
**         Bit mask of the port        : $0008
**
**         Initial direction           : Output (direction cannot be changed)
**         Initial output value        : 0
**         Initial pull option         : off
**
**         Port data register          : PORTA     [$0000]
**         Port control register       : DDRA      [$0002]
**
**         Optimization for            : speed
**     Contents  :
**         PutVal - void CON1_PutVal(bool Val);
**
**     Copyright : 1997 - 2011 Freescale Semiconductor, Inc. All Rights Reserved.
**     
**     http      : www.freescale.com
**     mail      : support@freescale.com
** ###################################################################*/

/* MODULE CON1. */

#include "CON1.h"
  /* Including shared modules, which are used in the whole project */
#include "PE_Types.h"
#include "PE_Error.h"
#include "PE_Const.h"
#include "IO_Map.h"
#include "Cpu.h"

#pragma DATA_SEG CON1_DATA             /* Select data segment "CON1_DATA" */
#pragma CODE_SEG CON1_CODE
#pragma CONST_SEG CON1_CONST           /* Constant section for this module */
/*
** ===================================================================
**     Method      :  CON1_PutVal (component BitIO)
**
**     Description :
**         This method writes the new output value.
**     Parameters  :
**         NAME       - DESCRIPTION
**         Val             - Output value. Possible values:
**                           FALSE - logical "0" (Low level)
**                           TRUE - logical "1" (High level)
**     Returns     : Nothing
** ===================================================================
*/
void CON1_PutVal(bool Val)
{
  if (Val) {
    setReg8Bits(PORTA, 0x08U);         /* PA3=0x01U */
  } else { /* !Val */
    clrReg8Bits(PORTA, 0x08U);         /* PA3=0x00U */
  } /* !Val */
}


/* END CON1. */
/*
** ###################################################################
**
**     This file was created by Processor Expert 3.05 [04.46]
**     for the Freescale HCS12X series of microcontrollers.
**
** ###################################################################
*/
