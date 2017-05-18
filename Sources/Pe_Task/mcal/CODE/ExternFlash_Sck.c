/** ###################################################################
**     THIS COMPONENT MODULE IS GENERATED BY THE TOOL. DO NOT MODIFY IT.
**     Filename  : ExternFlash_Sck.c
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
**                       45            |  PH6_KWH6_SCK2_RxD5
**             ----------------------------------------------------
**
**         Port name                   : H
**
**         Bit number (in port)        : 6
**         Bit mask of the port        : $0040
**
**         Initial direction           : Output (direction cannot be changed)
**         Initial output value        : 0
**         Initial pull option         : off
**
**         Port data register          : PTH       [$0260]
**         Port control register       : DDRH      [$0262]
**
**         Optimization for            : speed
**     Contents  :
**         SetInput  - void ExternFlash_Sck_SetInput(void);
**         SetOutput - void ExternFlash_Sck_SetOutput(void);
**         GetVal    - bool ExternFlash_Sck_GetVal(void);
**         ClrVal    - void ExternFlash_Sck_ClrVal(void);
**         SetVal    - void ExternFlash_Sck_SetVal(void);
**
**     Copyright : 1997 - 2011 Freescale Semiconductor, Inc. All Rights Reserved.
**     
**     http      : www.freescale.com
**     mail      : support@freescale.com
** ###################################################################*/

/* MODULE ExternFlash_Sck. */

#include "ExternFlash_Sck.h"
  /* Including shared modules, which are used in the whole project */
#include "PE_Types.h"
#include "PE_Error.h"
#include "PE_Const.h"
#include "IO_Map.h"
#include "Cpu.h"

#pragma DATA_SEG ExternFlash_Sck_DATA  /* Select data segment "ExternFlash_Sck_DATA" */
#pragma CODE_SEG ExternFlash_Sck_CODE
#pragma CONST_SEG ExternFlash_Sck_CONST /* Constant section for this module */
/*
** ===================================================================
**     Method      :  ExternFlash_Sck_GetVal (component BitIO)
**
**     Description :
**         This method returns an input value.
**           a) direction = Input  : reads the input value from the
**                                   pin and returns it
**           b) direction = Output : returns the last written value
**         Note: This component is set to work in Output direction only.
**     Parameters  : None
**     Returns     :
**         ---             - Input value. Possible values:
**                           FALSE - logical "0" (Low level)
**                           TRUE - logical "1" (High level)

** ===================================================================
*/
/*
bool ExternFlash_Sck_GetVal(void)

**  This method is implemented as a macro. See ExternFlash_Sck.h file.  **
*/

/*
** ===================================================================
**     Method      :  ExternFlash_Sck_ClrVal (component BitIO)
**
**     Description :
**         This method clears (sets to zero) the output value.
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/
/*
void ExternFlash_Sck_ClrVal(void)

**  This method is implemented as a macro. See ExternFlash_Sck.h file.  **
*/

/*
** ===================================================================
**     Method      :  ExternFlash_Sck_SetVal (component BitIO)
**
**     Description :
**         This method sets (sets to one) the output value.
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/
/*
void ExternFlash_Sck_SetVal(void)

**  This method is implemented as a macro. See ExternFlash_Sck.h file.  **
*/

/*
** ===================================================================
**     Method      :  ExternFlash_Sck_SetInput (component BitIO)
**
**     Description :
**         This method sets direction of the component to input.
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/
/*
void ExternFlash_Sck_SetInput(void)

**  This method is implemented as a macro. See ExternFlash_Sck.h file.  **
*/

/*
** ===================================================================
**     Method      :  ExternFlash_Sck_SetOutput (component BitIO)
**
**     Description :
**         This method sets direction of the component to output.
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/
void ExternFlash_Sck_SetOutput(void)
{
  setReg8(PTH, (getReg8(PTH) & (byte)(~(byte)0x40U)) | (Shadow_H & 0x40U)); /* PTH6=Shadow_H[bit 6] */
  setReg8Bits(DDRH, 0x40U);            /* DDRH6=0x01U */
}


/* END ExternFlash_Sck. */
/*
** ###################################################################
**
**     This file was created by Processor Expert 3.05 [04.46]
**     for the Freescale HCS12X series of microcontrollers.
**
** ###################################################################
*/
