#include "types.h"
#include "user.h"
#include "fcntl.h"

int
main()
{
  int proc_num = 10;
  int sleep_total = 10;
  int i, pid;

  testlock();

  for (i=0; i< proc_num; i++)
	{
	  pid = fork();
	  if (pid)
		{
		  printf(1, "process %d is created\n", i);
		  sleep(sleep_total/proc_num);
		}
	  else
		break;
	}

  if (pid)
	{
	  sleep(sleep_total);
	  testlock();
	  for (i=0; i<proc_num; i++)
		{
		  wait();
		}
	}
  else
	{
	  testlock();
	  printf(1, "%d have acquired lock\n", i);
	  testlock();
	}

  exit();
}
