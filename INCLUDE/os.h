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
#include<stdio.h>
#include <sys_init.h>

#define PREMPTIVE_SCHEDULING 0
#define ROUND_ROBIN_SCHEDULING 0

#if (PREMPTIVE_SCHEDULING | ROUND_ROBIN_SCHEDULING) 

#endif  

typedef enum 
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
    task100ms = 100u, //04,
    totaltask,
    maxtask

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
    void (*task_pointer)();

}scheduler;

#if (PREMPTIVE_SCHEDULING | ROUND_ROBIN_SCHEDULING) 
typedef struct 
{
    scheduler s1; 
    uint32_t task_complete_time; 
    Boolean is_function_exection_compete;
    void (*task_analyzer)(uint32_t task_complete_time , Boolean func_complete); 
    //void () 
     
}os_struct;

//Application can only return any of the following and should explicitly specifiy what are they returning since queue is common
//In the current code application can only interact with the BSW with any one of the data types.
typedef union 
{
    uint8_t unsign_byte; 
    uint16_t unsign_word; 
    uint32_t unsign_ integer;
    uint64_t unsign_double;
    float floa; 
    char byte; //signed char
    int signed_ integer; // signed integer  
    long long int  double_integer ; // double_integer

}Application_Datatypes;
#endif 
/*stupid logic as of now but have a scope for improvisation*/
extern uint16_t task_mask;
extern const uint16_t task_mask_limit;
extern uint32_t oscounterincrement_1ms;
extern uint16_t task_mask_p1;
extern taskrateindex  task_switcher;
extern uint64_t os_normal_task_count[total_taskcount];
extern const scheduler sch1[5];
extern uint32_t count;
extern uint32_t counter_lock;
extern uint32_t count_test[5];
extern uint64_t freerunningcounter;
void start_os();
void cooperative_scheduler();

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
    if(counter_lock)
    {
       printf("Task not completed yet");
    }
    else
    {
        oscounterincrement_1ms++;
        freerunningcounter++;
    }

}
void task_1ms();
void task_5ms();
void task_10ms();
void task_20ms();
void task_100ms();
void set_maxtaskmask(int n);
#endif /* INCLUDE_OS_H_ */
