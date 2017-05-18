
#include "Prj_Define.h"
#include "Soc_Macro.h"
#include "Sof_Macro.h"
#include "ChgM_Macro.h"

extern const sSOC_SocToVoltType SocToOcvArray[SOC_MAX_T_POINT][SOC_MAX_SOC_POINT];
extern const sSOF_VoltLmtType VoltLowArray[SOF_MAX_VOLT_POINT];
extern const sSOF_VoltLmtType VoltHighArray[SOF_MAX_VOLT_POINT];
extern const sByte DchTemperArray[SOF_MAX_T_POINT];
extern const sByte FbTemperArray[SOF_MAX_T_POINT];
extern const uWord SocArray[SOF_MAX_SOC_POINT];
extern const uWord CnstDisCurArray[SOF_MAX_SOC_POINT][SOF_MAX_T_POINT];
extern const uWord CnstFeedbackCurArray[SOF_MAX_SOC_POINT][SOF_MAX_T_POINT];
extern const uWord PulseDisCurArray[SOF_MAX_SOC_POINT][SOF_MAX_T_POINT];
extern const uWord PulseFeedbackCurArray[SOF_MAX_SOC_POINT][SOF_MAX_T_POINT];
extern const uWord CnstDisPowArray[SOF_MAX_SOC_POINT][SOF_MAX_T_POINT];
extern const uWord CnstFeedbackPowArray[SOF_MAX_SOC_POINT][SOF_MAX_T_POINT];
extern const uWord PulseDisPowArray[SOF_MAX_SOC_POINT][SOF_MAX_T_POINT];
extern const uWord PulseFeedbackPowArray[SOF_MAX_SOC_POINT][SOF_MAX_T_POINT];
extern const sChg_CurTableType  DcChg_TemperCurTable[T_SEC];
extern const sChg_CurTableType AcChg_TemperCurTable[T_SEC];

#if(ECU_RAM_USE_MODE)
#ifdef ECU_RAM_USE_GPGAE
#pragma DATA_SEG __GPAGE_SEG PAGED_RAM
#endif
#ifdef ECU_RAM_USE_RPGAE
#pragma DATA_SEG __RPAGE_SEG PAGED_RAM
#endif
#else
#pragma DATA_SEG DEFAULT
#endif


#pragma DATA_SEG DEFAULT

           /*  define  for  SOC  */
           /*  define  for  SOC  */
           /*  define  for  SOC  */
/**************** battery data for SOC estimation **************************/
const sSOC_SocToVoltType SocToOcvArray[SOC_MAX_T_POINT][SOC_MAX_SOC_POINT] =
// [temperature][point] // soc-ocv curve data 
{
    {
        {   0, 3400}, { 50, 3470}, { 100, 3510}, { 150, 3560}, { 200, 3590}, 
        { 250, 3610}, { 300, 3620},{ 350, 3630}, { 400, 3650}, { 450, 3660}, 
        { 500, 3680}, { 550, 3710},{ 600, 3750}, { 650, 3790}, { 700, 3830},
        { 750, 3870}, { 800, 3920},{ 850, 3970}, { 900, 4030}, { 950, 4080}, { 100, 4180}
    },
    {  // 0~15
        {   0, 3400}, { 50, 3470}, { 100, 3510}, { 150, 3560}, { 200, 3590}, 
        { 250, 3610}, { 300, 3620},{ 350, 3630}, { 400, 3650}, { 450, 3660}, 
        { 500, 3680}, { 550, 3710},{ 600, 3750}, { 650, 3790}, { 700, 3830},
        { 750, 3870}, { 800, 3920},{ 850, 3970}, { 900, 4030}, { 950, 4080}, { 100, 4180}
    },
    {   //-10~0
        {   0, 3400}, { 50, 3470}, { 100, 3510}, { 150, 3560}, { 200, 3590}, 
        { 250, 3610}, { 300, 3620},{ 350, 3630}, { 400, 3650}, { 450, 3660}, 
        { 500, 3680}, { 550, 3710},{ 600, 3750}, { 650, 3790}, { 700, 3830},
        { 750, 3870}, { 800, 3920},{ 850, 3970}, { 900, 4030}, { 950, 4080}, { 100, 4180}
    },
    {    // < -10
        {   0, 3400}, { 50, 3470}, { 100, 3510}, { 150, 3560}, { 200, 3590}, 
        { 250, 3610}, { 300, 3620},{ 350, 3630}, { 400, 3650}, { 450, 3660}, 
        { 500, 3680}, { 550, 3710},{ 600, 3750}, { 650, 3790}, { 700, 3830},
        { 750, 3870}, { 800, 3920},{ 850, 3970}, { 900, 4030}, { 950, 4080}, { 100, 4180}
    }
};
           /*  end of define  SOC  */
           /*  end of define  SOC  */
           /*  end of define  SOC  */



           /*  define  for  SOF  */
           /*  define  for  SOF  */
           /*  define  for  SOF  */
/***************************** volt modify Array ********************************/
const sSOF_VoltLmtType VoltLowArray[SOF_MAX_VOLT_POINT] = 
{
    {3000, 50}, {3020, 60}, {3040, 70}, {3060, 80},
};

const sSOF_VoltLmtType VoltHighArray[SOF_MAX_VOLT_POINT] = 
{
    {3600, 50}, {3580, 60}, {3560, 70}, {3540, 80},
};
/**************************** end volt modify Array *******************************/

/*
 * temperatrue point
 * unit is 1 degree
 */
const sByte DchTemperArray[SOF_MAX_T_POINT] = {-30,-20,-10,-5,0,5,10,25,35,40,45,55};
const sByte FbTemperArray[SOF_MAX_T_POINT] =  {-30,-20,-10,-5,0,5,10,25,35,40,45,55};
/*
 * soc point
 * unit is 0.1%
 */
const uWord SocArray[SOF_MAX_SOC_POINT] = {0,50,100,200,300,400,500,650,700,800,950,1000};


/********************************* CURRENT Array ********************************/
/*
 * max last current of discharge
 * unit is 0.1A
 */
const uWord CnstDisCurArray[SOF_MAX_SOC_POINT][SOF_MAX_T_POINT] =
{
//  -30, -20,  -10,  -5,    0,    5,   10,   25,   35,   40,   45,    55                   // 温度
    {0,   0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0}, // 0% soc
    {0,   0,  540,  540,  540,  900,  900,  900,  900,  900,  900,  540}, // 5% soc
    {0,   0,  540,  540,  540,  900,  900,  900,  900,  900,  900,  540}, // 10% soc
    {0,   0,  540,  900,  900, 1080, 1080, 1080, 1080, 1080, 1080,  540}, // 20% soc
    {0,   0,  540,  900,  900, 1080, 1080, 1080, 1080, 1080, 1080, 1440}, // 30% soc
    {0,   0,  900, 1080, 1080, 1440, 1440, 1440, 1440, 1440, 1440,  900}, // 40% soc
    {0,   0,  900, 1080, 1080, 1440, 1440, 1440, 1440, 1440, 1440,  900}, // 50% soc
    {0,   0,  900, 1080, 1080, 1440, 1440, 1440, 1440, 1440, 1440,  900}, // 65% soc
    {0,   0,  900, 1080, 1080, 1440, 1440, 1440, 1440, 1440, 1440,  900}, // 70% soc
    {0,   0,  900, 1080, 1080, 1440, 1440, 1440, 1440, 1440, 1440,  900}, // 80% soc
    {0,   0,  900, 1080, 1080, 1440, 1440, 1440, 1440, 1440, 1440,  900}, // 95% soc
    {0,   0,  900, 1080, 1080, 1440, 1440, 1440, 1440, 1440, 1440,  900}, // 100% soc
};

/*
 * max last current of charge
 * unit is 0.1A
 */
const uWord CnstFeedbackCurArray[SOF_MAX_SOC_POINT][SOF_MAX_T_POINT] =
{
//  -30, -20,  -10,  -5,    0,    5,   10,   25,   35,   40,   45,    55                   // 温度
    {0,   0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0}, // 0% soc
    {0,   0,    0,    0,    0,  540,  540,  900,  900,  900,  900,    0}, // 5% soc
    {0,   0,    0,    0,    0,  540,  540,  900,  900,  900,  900,    0}, // 10% soc
    {0,   0,    0,    0,    0,  540,  540,  900,  900,  900,  900,    0}, // 20% soc
    {0,   0,    0,    0,    0,  540,  540,  900,  900,  900,  900,    0}, // 30% soc
    {0,   0,    0,    0,    0,  540,  540,  900,  900,  900,  900,    0}, // 40% soc
    {0,   0,    0,    0,    0,  540,  540,  900,  900,  900,  900,    0}, // 50% soc
    {0,   0,    0,    0,    0,  540,  540,  900,  900,  900,  900,    0}, // 65% soc
    {0,   0,    0,    0,    0,  540,  540,  900,  900,  900,  900,    0}, // 70% soc
    {0,   0,    0,    0,    0,  540,  540,  540,  540,  540,  900,    0}, // 80% soc
    {0,   0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0}, // 95% soc
    {0,   0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0}, // 100% soc
};

/*
 * max pulse current of discharge
 * unit is 0.1A
 */
const uWord PulseDisCurArray[SOF_MAX_SOC_POINT][SOF_MAX_T_POINT] =
{
//  -30, -20,  -10,  -5,    0,    5,   10,   25,   35,   40,   45,    55                   // 温度
    {0,   0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0}, // 0% soc
    {0,   0,  540,  540,  540,  900,  900,  900,  900,  900,  900,  540}, // 5% soc
    {0,   0,  540,  540,  540,  900,  900,  900,  900,  900,  900,  540}, // 10% soc
    {0,   0,  540,  900,  900, 1080, 1080, 1080, 1080, 1080, 1080,  540}, // 20% soc
    {0,   0,  540,  900,  900, 1080, 1080, 1080, 1080, 1080, 1080, 1440}, // 30% soc
    {0,   0,  900, 1080, 1080, 1440, 1440, 1440, 1440, 1440, 1440,  900}, // 40% soc
    {0,   0,  900, 1080, 1080, 1440, 1440, 1440, 1440, 1440, 1440,  900}, // 50% soc
    {0,   0,  900, 1080, 1080, 1440, 1440, 1440, 1440, 1440, 1440,  900}, // 65% soc
    {0,   0,  900, 1080, 1080, 1440, 1440, 1440, 1440, 1440, 1440,  900}, // 70% soc
    {0,   0,  900, 1080, 1080, 1440, 1440, 1440, 1440, 1440, 1440,  900}, // 80% soc
    {0,   0,  900, 1080, 1080, 1440, 1440, 1440, 1440, 1440, 1440,  900}, // 95% soc
    {0,   0,  900, 1080, 1080, 1440, 1440, 1440, 1440, 1440, 1440,  900}, // 100% soc
};

/*
 * max pulse current of charge
 * unit is 0.1A
 */
const uWord PulseFeedbackCurArray[SOF_MAX_SOC_POINT][SOF_MAX_T_POINT] =
{
//  -30, -20,  -10,  -5,    0,    5,   10,   25,   35,   40,   45,    55                   // 温度
    {0,   0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0}, // 0% soc
    {0,   0,    0,    0,    0,  540,  540,  900,  900,  900,  900,    0}, // 5% soc
    {0,   0,    0,    0,    0,  540,  540,  900,  900,  900,  900,    0}, // 10% soc
    {0,   0,    0,    0,    0,  540,  540,  900,  900,  900,  900,    0}, // 20% soc
    {0,   0,    0,    0,    0,  540,  540,  900,  900,  900,  900,    0}, // 30% soc
    {0,   0,    0,    0,    0,  540,  540,  900,  900,  900,  900,    0}, // 40% soc
    {0,   0,    0,    0,    0,  540,  540,  900,  900,  900,  900,    0}, // 50% soc
    {0,   0,    0,    0,    0,  540,  540,  900,  900,  900,  900,    0}, // 65% soc
    {0,   0,    0,    0,    0,  540,  540,  900,  900,  900,  900,    0}, // 70% soc
    {0,   0,    0,    0,    0,  540,  540,  540,  540,  540,  900,    0}, // 80% soc
    {0,   0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0}, // 95% soc
    {0,   0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0}, // 100% soc
};
/****************************** End CURRENT Array ********************************/



/********************************* POWER Array ********************************/
/*
 * max last power of discharge
 * unit is 0.1 KW
 */
const uWord CnstDisPowArray[SOF_MAX_SOC_POINT][SOF_MAX_T_POINT] =
{
//  -30, -20,  -10,  -5,    0,    5,   10,   25,   35,   40,   45,    55                   // 温度
    {0,   0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0}, // 0% soc
    {0,   0,  0,  50,  100,  100,  100,  100,  100,  100,  100,  50}, // 5% soc
    {0,   100,  100,  150,  150,  150,  200,  200,  200,  200,  200,  100}, // 10% soc
    {0,   100,  100,  200,  250,  300,  300,  300,  300,  300,  300,  250}, // 20% soc
    {0,   100,  150,  200,  300,  360,  360,  360,  360,  360,  300,  250}, // 30% soc
    {0,   150,  200,  200, 300, 380, 400, 400, 400, 400, 380,  300}, // 40% soc
    {0,   150,  200,  200, 300, 400, 400, 400, 400, 430, 380,  300}, // 50% soc
    {0,   150,  200,  200, 300, 430, 430, 430, 430, 430, 380,  300}, // 65% soc
    {0,   150,  200,  200, 300, 430, 430, 430, 430, 430, 380,  300}, // 70% soc
    {0,   150,  200,  200, 320, 430, 430, 430, 430, 430, 380,  300}, // 80% soc
    {0,   150,  200,  250, 320, 430, 430, 430, 430, 430, 380,  300}, // 95% soc
    {0,   150,  200,  250, 360, 430, 430, 430, 430, 430, 380,  300}, // 100% soc
};

/*
 * max last max power of charge
 * unit is 0.1 KW
 */
const uWord CnstFeedbackPowArray[SOF_MAX_SOC_POINT][SOF_MAX_T_POINT] =
{
//  -30, -20,  -10,  -5,    0,    5,   10,   25,   35,   40,   45,    55                   // 温度
    {0,   0,    0,    0,    10,    30,  50,  50,  50,    30,    30,    10}, // 0% soc
    {0,   0,    10,    10,    20,  50,  70,  70,  70,  50,  40,    10}, // 5% soc
    {0,   0,    10,    10,    20,  50,  70,  70,  70,  50,  40,    10}, // 10% soc
    {0,   0,    10,    10,    20,  50,  70,  70,  70,  50,  40,    10}, // 20% soc
    {0,   0,    10,    10,    30,  60,  70,  70,  70,  70, 40,    20}, // 30% soc
    {0,   0,    10,    10,    40,  60,  80,  80,  80,  70,  50,    20}, // 40% soc
    {0,   0,    10,    20,    40,  60,  80,  80,  80,  70,  50,    20}, // 50% soc
    {0,   0,    20,    20,    50,  60,  90,  90,  90,  80,  60,    20}, // 65% soc
    {0,   0,    20,    20,    50,  70,  90,  90,  90,  80,  60,    20}, // 70% soc
    {0,   0,    20,    20,    70,  70,  100, 100, 100,  80,  70,    20}, // 80% soc
    {0,   0,    20,    20,    70,  90,  100, 100, 100,    90,    80,    20}, // 95% soc
    {0,   0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0}, // 100% soc
};

/*
 * max pulse power of discharge
 * unit is 0.1 KW
 */
const uWord PulseDisPowArray[SOF_MAX_SOC_POINT][SOF_MAX_T_POINT] =
{
//  -30, -20,  -10,  -5,    0,    5,   10,   25,   35,   40,   45,    55                   // 温度
    {0,   0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0}, // 0% soc
    {0,   0,    0,    200,  300,  400,  600,  300,  300,  300,  300,  150}, // 5% soc
    {0,   200,  200,  200,  300,  450,  700,  600,  600,  600,  400,  300}, // 10% soc
    {0,   200,  200,  300,  500,  800,  900,  1000, 1000, 800,  600,  500}, // 20% soc
    {0,   200,  250,  300,  500,  800,  900,  1000, 1000, 800,  600,  500}, // 30% soc
    {0,   300,  300,  300,  600,  800,  1200, 1300, 1300, 1000, 800,  600}, // 40% soc
    {0,   300,  300,  300,  600,  1000, 1200, 1300, 1300, 1200, 800,  600}, // 50% soc
    {0,   300,  300,  400,  600,  1000, 1200, 1300, 1300, 1200, 1000,  700}, // 65% soc
    {0,   300,  400,  400,  600,  1000, 1200, 1300, 1300, 1200, 1000,  700}, // 70% soc
    {0,   300,  400,  400,  700,  1000, 1200, 1300, 1300, 1200, 1000,  700}, // 80% soc
    {0,   300,  400,  450,  700,  1000, 1200, 1300, 1300, 1200, 1000,  700}, // 95% soc
    {0,   300,  400,  450,  700,  1000, 1200, 1300, 1300, 1200, 1000,  700}, // 100% soc
};
/*
 * max pulse power of charge
 * unit is 0.1 KW
 */
const uWord PulseFeedbackPowArray[SOF_MAX_SOC_POINT][SOF_MAX_T_POINT] =
{
//  -30, -20,  -10,  -5,    0,    5,   10,   25,   35,   40,   45,    55                   // 温度
    {0,   0,    0,    0,    20,    80,  150,  150,  150,    90,    90,    20}, // 0% soc
    {0,   0,    20,    20,    40,  100,  180,  200,  200,  150,  120,    20}, // 5% soc
    {0,   0,    20,    20,    40,  120,  200,  230,  210,  150,  120,    20}, // 10% soc
    {0,   0,    20,    20,    40,  120,  200,  230,  210,  150,  120,    30}, // 20% soc
    {0,   0,    20,    30,    60,  150,  200,  250,  230,  200,  150,    40}, // 30% soc
    {0,   0,    20,    30,    60,  150,  230,  250,  230,  200,  150,    50}, // 40% soc
    {0,   0,    20,    30,    80,  180,  230,  280,  250,  200,  150,    50}, // 50% soc
    {0,   0,    40,    40,    80,  180,  260,  280,  250,  230,  180,    50}, // 65% soc
    {0,   0,    40,    40,    100,  200,  260, 300,  280,  230,  180,    60}, // 70% soc
    {0,   0,    40,    40,    140,  200,  300, 300,  280,  250,  210,    60}, // 80% soc
    {0,   0,    40,    40,    140,  240,  300, 300,  300,   270,    240,    60}, // 95% soc
    {0,   0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0}, // 100% soc
};
/****************************** End POWER Array ********************************/
           /*  end of define  SOF  */
           /*  end of define  SOF  */
           /*  end of define  SOF  */
           
           
           /*  define  for  Chg  */
           /*  define  for  Chg  */
           /*  define  for  Chg  */

/* table for charge manage */
const sChg_CurTableType  DcChg_TemperCurTable[T_SEC] =
{
    {20,  0}, {40,  10}, {45, 20}, { 55, 30},    /* Temper: unit: 1'C, Offset -40; Current: unit: 0.01C */
    {80, 50}, {92,  20}, {95, 10}, {96,  0}
};

const sChg_CurTableType AcChg_TemperCurTable[T_SEC] =
{
    {20,  0}, {40, 40}, {45, 80}, {55, 110},  /* Temper: unit: 1'C, Offset -40; Current: unit: 0.1A */
    {80,  190}, {92, 80}, {95, 40}, {96,  0}
};

           /*  end of define  Chg  */
           /*  end of define  Chg  */
           /*  end of define  Chg  */
           

           
