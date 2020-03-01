/*This is a generic implementation of the queue for opearating system sand interacting with the application*/
#include "os.h"
#include "queue.h"
/*Access operating system structure*/
#define Acc_os_struct(index) os_tasks.os_task[index]


/*Global Variables */
OS_Task_ManagementQueue os_tasks;

/*Function Defanitions*/
static void fillup_operating_system_structure(uint8_t priority ,uint32_t taskrate );
/*Provivate function implementation*/

static void fillup_operating_system_structure(uint8_t priority ,uint32_t taskrate )
{
      Acc_os_struct(os_tasks.track_osqueue_index_rear).preemppriority = priority;
      Acc_os_struct(os_tasks.track_osqueue_index_rear).task_rate = taskrate;
      //Acc_os_struct(os_tasks.track_osqueue_index_rear).taskratefunc = *Addr_func;


}


uint8_t is_queue_osfull(void)
{
    uint8_t tempvar = 0x00;
     
    if(os_tasks.track_osqueue_index_rear == OS_Queue_size)
    {
        #if !CIRCULAR_BUFFER
        tempvar = 0x01;
        #else 
        os_tasks.task_osqueue_index_rear = OS_Queue_size ; 
        #endif 
    }
    /*Circular Buffer is only considered to be FULL when front == rear and index_rear = OS_Queue_size*/
    #if CIRCULAR_BUFFER 
    if((os_tasks.task_osqueue_index_rear == OS_Queue_size) && (os_tasks.task_osqueue_index_rear == os_tasks.track_osqueue_index_front))
    {
        tempvar = 0x01;
    }
    #endif  
    return(tempvar);

}

uint8_t is_queue_osempty(void)
{
     uint8_t temp_var = 0x00;
     #if CIRCULAR_BUFFER
     if((os_tasks.track_osqueue_index_front == os_tasks.track_osqueue_index_rear) && ((os_tasks.task_osqueue_index_rear != OS_Queue_size)))
     {
         temp_var = 0x01;
     } 
     #else
    if(os_tasks.track_osqueue_index_front == os_tasks.track_osqueue_index_rear)
    {
        temp_var = 0x01;
    }
    #endif 
    return(temp_var);

}

/*Create an element of the member 0s_struct and pass the handle */
void delete_element_osqueue()
{
    //uint8_t 
    if(queuefemptystat())
    {
          // noting can be deleted
    }
     else if(os_tasks.track_osqueue_index_front != os_tasks.track_osqueue_index_rear)
     {
    #if CIRCULAR_BUFFER
          if((os_tasks.track_osqueue_index_front == OS_Queue_size))
          {
              os_tasks.track_osqueue_index_front = os_tasks.track_osqueue_index_front % OS_Queue_size; 
              if(os_tasks.track_osqueue_index_front != os_tasks.track_osqueue_index_rear) //queue full condition 
              {
                  os_tasks.track_osqueue_index_front++;
              }

          }
          else
          {
              os_tasks.track_osqueue_index_front++;
          }
    #else
         /* code */
        os_tasks.track_osqueue_index_front++;
    #endif 
     }
    
}

void add_element_osqueue(uint8_t preemptive_priority , uint32_t task_rate, void (*func_ptr)())
{
    if(queuefemptystat())
    {
        #if !CIRCULAR_BUFFER
        /*If front index == rear index it measn that queue is empt and we can reuse it */
        if(os_tasks.track_osqueue_index_front & os_tasks.track_osqueue_index_rear) 
        {
            os_tasks.track_osqueue_index_front = 0; 
            os_tasks.track_osqueue_index_rear =0 ;

        }
        #endif 
        func_ptr();                         /*priority*/       /*rate*/   /*Handle to the function to be executed */
        /*Fill up OS Functions here . Have to find out what is causing the error. May be use a Double pointer */
        Acc_os_struct(os_tasks.track_osqueue_index_rear).taskratefunc = func_ptr;
        //Acc_os_struct(os_tasks.track_osqueue_index_rear).taskratefunc();
        fillup_operating_system_structure(preemptive_priority,task_rate);

       /*Front and Rear pointing to the first element */
       //os_tasks.track_osqueue_index_front++;
        os_tasks.track_osqueue_index_rear++;

    }
   
    if(!queuefullstat())
    {
        fillup_operating_system_structure(preemptive_priority,task_rate);
        /*Always insert elements at the end of the Queue */
        os_tasks.track_osqueue_index_rear++;
       
    
    }
    
}




void initos()
 {
     os_tasks.addelementqueue = &add_element_osqueue;
     os_tasks.deleteelementqueue = &delete_element_osqueue;
     os_tasks.isqueueempty = &is_queue_osempty;
     os_tasks.isqueuefull = &is_queue_osfull;
     os_tasks.track_osqueue_index_front = 0;
     os_tasks.track_osqueue_index_rear = 0;
     os_tasks.addelementqueue(0,100,&task_100ms);
    // EnqueOperation_os(0,10,&task_10ms);
   //  EnqueOperation_os(0,5,&task_5ms);
    // EnqueOperation_os(0,100,&task_100ms);
  //   DequeOperation_os();
  //   DequeOperation_os();

 }


    


























