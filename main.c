/**
 * main.c
 */
#include<stdio.h>
 #include "api.h"
 #include"sys_init.h" 
#include "pwm_timer_lib.h"
 #include "os.h"
int main(void)
{
//    starttimer();
	sys_init();
	start_os();
	return 0;
}
