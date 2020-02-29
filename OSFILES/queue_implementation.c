/*This is a generic implementation of the queue for opearating system sand interacting with the application*/
#include <stdio.h> 
#include "os.h"

#define MAX_QUEUE_SIZE 100
#define OS_Queue_size 10

static uint8_t track_osqueue_index;
static uint8_t track_Applicationqueue_index;
void add_element_queue()
{

}; 

void delete_element_queue() 
{

};

void is_queue_full()
{

};

void is_queue_empty()
{

};

void initlize_queue() 
{
    track_queue_index = 0;
    /*have an array of structures for the operating systems*/
    os_struct os_task[OS_Queue_size]; 
    /*Initilize the applciation structures*/
    Application_Datatypes application[MAX_QUEUE_SIZE];
    // [MAX_Queue_Size]
    /*currently considering */

};
