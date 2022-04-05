# pthread
```c
pthread_create : 쓰레드 생성 및 실행 
pthread_join : 해당 쓰레드가 종료 할때까지 대기  
pthread_detach : pthread_create 를 통해 생성된 쓰레드를 떼어냄  
pthread_exit : 현재 실행중인 쓰레드 종료  
pthread_mutex_init : 뮤텍스 초기화  
pthread_mutex_destory : 뮤텍스 제거  
pthread_mutex_lock : 뮤텍스 잠금  
pthread_mutex_unlock : 뮤텍스 잠금 해제  
pthread_cancel : 쓰레드 취소  
```

## Example (다음 코드를 동작을 분석한 후 재 사용성을 높이도록 리펙토링 하시오)
> gcc -o thread_example thread_example.c -lpthread

**therad_example.c**
```c
#include <stdio.h>
#include <string.h>
#include <pthread.h>

pthread_t threads[5];
int done[5];

void *thread_main(void *);

int main(void)
{
	int i;
	int rc;
	int status;
	
	printf("pid=%d\n", getpid());
	
	for (i = 0; i < 5; i++)
	{	
		done[i] = 0;
		pthread_create(&threads[i], NULL, &thread_main, (void *)i);
		printf("%d, %d\n", i, threads[i]);
	}

	for (i = 4; i >= 0; i--)
	{
		done[i] = 1;
	         rc = pthread_join(threads[i], (void **)&status);
		if (rc == 0)
		{
			printf("Completed join with thread %d status= %d\n",i, status);
		}
		else
		{
			printf("ERROR; return code from pthread_join() is %d, thread %d\n", rc, i);
      return -1;
		}
	}

	return 0;
}

void *thread_main(void *arg)
{
	int i;
	double result=0.0;

	printf("therad: %d, %d\n", (int)arg, getpid());

	while (!done[(int)arg])
	{
	   for (i=0; i < 1000000; i++)
   	   {
     	      result = result + (double)random()
   	   }
   	   printf("thread: %d, result = %e\n", (int)arg, result);
	}

	pthread_exit((void *) 0);
}
```
