# tm4c123_devolopmentfromscratch-
This repo concentrates on tm4c123 board bringup 
1. In this commit i2c and genral purpose timers are configured . The timeout for i2c was also implemented. 
2. Intertupt enable and disable functions are added.
3. Function for MPTR has to be added. 
4. The reason for i2c holding the BUS have to be found out.  

01/31/2020 
1. Timer API improvent. Generic Timer API for timeouts written. Timer 0 selected in 32 bit mode. 
2. Testing results have to be attached. 

02/02/2020
1. e2prom driver devolopment under progress. Writing Generic API for reading and writing data from e2prom. 
2. Writing data driver for reaing and writing huge chunk of data and individual data. Work in Progress.
Things yet to do 
1. Decide the block size and offset value based on the given address. 
   for ex if address is 0x31 it has to be block 2 and 0 offset.(block 2 offset 1 )
