/*
 * os.h
 *
 *  Created on: Nov 29, 2019
 *      Author: satish
 */

#ifndef INCLUDE_OS_H_
#define INCLUDE_OS_H_

#include <stdint.h>
/*MACRO declaration */

#include <sys_init.h>


typedef enum
{
    task1,
    task5 ,
    task10 ,
    task20,
    task100,
    total_taskcount
}taskrateindex;


typedef enum
{
    task1ms = 1, //00
    task5ms = 5, //1
    task10ms = 0x0A, //02
    task20ms = 20u, //03
    task100ms = 100u, //04

}taskrate;

typedef enum
{
   task1ms_comp = 0x00,
   task5ms_comp = 0x01,
   task10ms_comp = 0x03,
   task20ms_comp = 0x07,
   task_100ms_comp = 0x0F,
}mask_completion_stat;


typedef struct
{
    taskrateindex t1;
    taskrate t2;
    mask_completion_stat m1;
    void (*task_pointer)();

}scheduler;


/*stupid logic as of now but have a scope for improvisation*/
extern uint16_t task_mask;
extern const uint16_t task_mask_limit;
extern uint32_t oscounterincrement_1ms;
extern uint16_t task_mask_p1;
extern uint16_t os_normal_task_count[total_taskcount];
extern const scheduler sch1[5];
void start_os();
taskrateindex cooperative_scheduler();

inline uint8_t os_tasksplitter(uint32_t counter ,uint32_t  taskrate)
{
    if((counter!=0)&&(counter % taskrate) == 0)
        {

        return(1);
        }
    else
        {
        return(0);
        }
}

inline void os_tick_reset()
{
    oscounterincrement_1ms++;
    //tirgger should be from here//

}
void task_1ms();
void task_5ms();
void task_10ms();
void task_20ms();
void task_100ms();
void set_maxtaskmask(int n);
#endif /* INCLUDE_OS_H_ */
