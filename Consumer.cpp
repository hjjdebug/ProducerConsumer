#include "stdio.h"
#include "Consumer.h"
#include <QDebug>
#include "global.h"
void Consumer::run()
{
    for (int i = 0; i < DataSize; ++i)
    {
        mutex.lock();
        if (available_bytes == 0)
        {
            cond_bufEmpty.wait(&mutex); //等待直到缓冲不空,wait 时 mutex 被释放,线程被阻塞
        }
//      满足条件后, 此时mutex 又被锁定
        fprintf(stderr, "I'm a consumer,now I use a data:%d,%c\n",i, buffer[i % BufferSize]);
        --available_bytes;
        mutex.unlock();
        cond_bufFull.wakeAll(); //唤醒因缓冲满而阻塞的进程
    }
	gApp->exit(); //消费完数据后，程序退出
}
