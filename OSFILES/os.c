#include "os.h"

uint16_t task_mask;
uint16_t task_mask_p1;
const uint16_t task_mask_limit = (sizeof(sch1)/sizeof(sch1[0]));
uint32_t oscounterincrement_1ms;
uint16_t os_normal_task_count[total_taskcount];
uint32_t count;
uint32_t count_test[5];
const scheduler sch1[5] =
{
{task1  ,task1ms ,  task1ms_comp , &task_1ms},
{task5   ,task5ms ,  task5ms_comp , &task_5ms},
{task10  ,task10ms , task10ms_comp , &task_10ms},
{task20  ,task20ms , task20ms_comp , &task_20ms},
{task100 ,task100ms ,task_100ms_comp , &task_100ms}
};

taskrateindex cooperative_scheduler()
{
    taskrateindex temp = total_taskcount;
    count++;
    if(((task_mask == 0x00)) && (os_tasksplitter(oscounterincrement_1ms,task1ms)))
     {
        count_test[0] = count;
         //task_1ms();
         task_mask = 0x01;
         temp =task1;
       //  break;
     }

     else if((task_mask ==(sch1[task5].m1)) && (os_tasksplitter(oscounterincrement_1ms,task5ms)))
     {
         count_test[1] = count;
           // task_5ms();
            task_mask = (task_mask |(task_mask<<1));
            temp = task5;
           // break;
     }

     else if((task_mask ==(sch1[task10].m1)) && (os_tasksplitter(oscounterincrement_1ms,task10ms)))
     {
         count_test[2] = count;
            //task_10ms();
         task_mask  = (task_mask |(task_mask<<1));
          temp = task10 ;
         // break;
     }

     else if((task_mask ==(sch1[task20].m1)) && (os_tasksplitter(oscounterincrement_1ms,task20ms)))
     {
         count_test[3] = count;
            // task_20ms();
            task_mask  = (task_mask |(task_mask<<1));
            temp = task20;

     }

     else if((task_mask ==(sch1[task100].m1)) && (os_tasksplitter(oscounterincrement_1ms,task100ms)))
       {
         count_test[4] = count;
             //task_100ms();
             task_mask  = (task_mask |(task_mask<<1));
             temp = task100;
       }

       else  if(task_mask == task_mask_p1)
     {
             task_mask= 0x00;
     }

     return(temp);
}

void task_5ms(){os_normal_task_count[task5]++;}
void task_10ms(){os_normal_task_count[task10]++;}
void task_20ms(){os_normal_task_count[task20]++;}
void task_100ms(){os_normal_task_count[task100]++;}
void task_1ms(){os_normal_task_count[task1]++;}


void start_os()
{
    set_maxtaskmask(task_mask_limit);
    systick_initlize();
   while(1)
   {
      switch(cooperative_scheduler())
      {
      case 0 : sch1[task1].task_pointer();
                break;
      case 1 : sch1[task5].task_pointer();
                break;
      case 2 : sch1[task10].task_pointer();
                break;
      case 3 : sch1[task20].task_pointer();
                break;
      case 4 : sch1[task100].task_pointer();
                break;
      default :break;
      }

   }
}
void set_maxtaskmask(int n)
{
    int iterator = 0;
     while(iterator < n)
     {
         /*1 because we are setting the bit wise operator*/
         task_mask_p1 = (task_mask_p1 | (0x01<<iterator));
         iterator++;
     }
}

void system_register_initilize(){}
