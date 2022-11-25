#include "Producer.h"
#include "global.h"
#include <QTime>
#include <QDebug>
void Producer::run()
{
    qsrand(QTime(0,0,0).secsTo(QTime::currentTime()));
    for (int i = 0; i < DataSize; ++i)
    {
        mutex.lock();
        if (available_bytes == BufferSize) //如果缓冲区满了
        {
            cond_bufFull.wait(&mutex); //线程要阻塞，等待消费者取数据
        }
        buffer[i % BufferSize] = "ABCDEF"[(int)qrand() % 6];
        qDebug() << "I am producer, and I produce a data! -------" << "buffer["<<i<<"] is" << buffer[i % BufferSize];
        ++available_bytes;
        mutex.unlock();		// 创建一条数据,存入缓冲
        cond_bufEmpty.wakeAll(); //通知消费者去取. (消费者有可能被阻塞在无数据上)
    }
}
