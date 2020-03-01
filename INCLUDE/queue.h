#ifndef INCLUDE_QUEUE_H_
#define INCLUDE_QUEUE_H_

#include <stdio.h> 
#include <stdint.h>
#include "api.h"
#include "os.h"
#define MAX_QUEUE_SIZE 100
#define OS_Queue_size 10
#define QUEUE_START_POSITION 0
#define CIRCULAR_BUFFER 1
#ifdef __cplusplus
extern "C" {
#endif
/*Macros to be Used by the application and the operating suystem*/
/*Operating System macros ONly*/
#define queue_track_rear                                 os_tasks.track_osqueue_index_rear
#define EnqueOperation_os(preempt,taskrate,func)         os_tasks.addelementqueue(preempt,taskrate,func)
#define DequeOperation_os()                              os_tasks.deleteelementqueue()
#define queuefullstat()                                  os_tasks.isqueuefull()
#define queuefemptystat()                                os_tasks.isqueueempty()
//#define os_task_valuesinsert(i)     os_tasks.os_task[i] \
  //                                  fillup_operating_system_structure(os_tasks.os_task[i])

/*Application Mactos Only. To be Used by the Applciation */



typedef union
{
    uint8_t unsign_byte;
    uint16_t unsign_word;
    uint32_t unsign_inte;
    uint64_t unsign_double;
    float floa;
    char byte; //signed char
    int signed_integer; // signed integer
    long long int  double_integer ; // double_integer

}Application_Datatypes;


/*This Structure allows user to create and delete task rates accordingly
 * Scheduler is a generic now*/
typedef struct
{
   // scheduler s1;
    /*This will be executed when preemptive scheduler is being done */
    uint8_t preemppriority;
    uint32_t task_rate;
    void (*taskratefunc)();

}os_struct;
/*Internal Structure to monitor the taskrate and Evertthing*/
typedef struct 
{
     void (* memprymanagement)();
    uint32_t task_complete_time;
    void (*task_analyzer)(uint32_t task_complete_time , Boolean func_complete);
    /* data */
}private_os_func;


void delete_element_osqueue();
//void add_element_osqueue(uint8_t preemptive_priority , uint32_t task_rate , uint32_t *taskratefunction );
void add_element_osqueue(uint8_t preemptive_priority , uint32_t task_rate , void (*func_ptr)() );
uint8_t is_queue_osempty(void);
uint8_t is_queue_osfull(void);
void initlize_os_structures();
void initos();

typedef struct
{
    os_struct os_task[OS_Queue_size];
    uint8_t track_osqueue_index_front;
    uint8_t track_osqueue_index_rear;
    void (*addelementqueue) (uint8_t , uint32_t ,void (*)());
    void (*deleteelementqueue) ();
    uint8_t (*isqueuefull)(void);
    uint8_t (*isqueueempty)(void);
    void (*initlizequeue)();
    Boolean is_function_exection_compete;
    void (*task_analyzer)(uint32_t task_complete_time , Boolean func_complete);
    #if CIRCULAR_BUFFER
    uint8_t task_osqueue_index_rear;
    #endif 
}OS_Task_ManagementQueue;

extern OS_Task_ManagementQueue os_tasks;


#ifdef __cplusplus
}
#endif
#endif
