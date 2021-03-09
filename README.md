# ff_iso
STM32 multitasking FATFS+SDIO
* http://www.github.com/NimaLTD   
* https://www.instagram.com/github.nimaltd/   
* https://www.linkedin.com/in/nimaltd/   
* https://www.youtube.com/channel/UCUhY7qY1klJm1d2kulr9ckw   

Solve problem in using fatfs+sdio in different tasks.
Create a task with high priority.
Call ff_init().
Call ff_loop() in infinite loop.
```

void StartTaskOther(void *argument)
{
  osDelay(100);
  ff_mount ......
  ....
  ....
  ff_open ....
  
  ff_close ....
  
  for(;;)
  {
    osDelay(1);
  }
}

void StartTaskSD(void *argument)
{
  ff_init();
  for(;;)
  {
    ff_loop();
    osDelay(1);
  }
}

```
