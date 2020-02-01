#include "os.h"

uint16_t task_mask;
uint16_t task_mask_p1;
const uint16_t task_mask_limit = (sizeof(sch1)/sizeof(sch1[0]));
uint32_t oscounterincrement_1ms;
uint64_t os_normal_task_count[total_taskcount] = {0};
taskrateindex task_switcher;
uint32_t count;
uint32_t counter_lock = 0;
uint32_t count_test[5];
uint64_t freerunningcounter;
taskrate prev = maxtask;
uint32_t global_trigger;
const scheduler sch1[5] =
{
{task1   , task1ms ,   &task_1ms},
{task5   , task5ms ,   &task_5ms},
{task10  , task10ms ,  &task_10ms},
{task20  , task20ms ,  &task_20ms},
{task100 , task100ms , &task_100ms}
};

 void start_os()
 {
     while(1)
     {


         /*Heart of the scheduler*/
         while(global_trigger< total_taskcount)
         {
              if(((oscounterincrement_1ms % sch1[global_trigger].t2) == 0) &&  (oscounterincrement_1ms >= sch1[global_trigger].t2) && (prev != sch1[global_trigger].t2))
              {
                  counter_lock = 1;
                  sch1[global_trigger].task_pointer();
                  prev = sch1[global_trigger].t2;

                  if(sch1[global_trigger].t2 == task100ms)
                  {
                      prev = totaltask;
                      oscounterincrement_1ms = 0;
                      global_trigger =0;
                  }
                  else
                  {
                  global_trigger++;
                  }

                  counter_lock =0;
              }
         }
     }
 }

 void task_1ms(){os_normal_task_count[task1]++;}
void task_5ms(){os_normal_task_count[task5]++; }
void task_10ms(){os_normal_task_count[task10]++;}
void task_20ms(){os_normal_task_count[task20]++;}
void task_100ms(){os_normal_task_count[task100]++;}


void set_maxtaskmask(int n)
{
    int iterator = 0;
     while(iterator < (n-1))
     {
         /*1 because we are setting the bit wise operator*/
         task_mask_p1 = (task_mask_p1 | (0x01<<iterator));
         iterator++;
     }
}

void system_register_initilize(){}
