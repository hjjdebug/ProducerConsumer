最简单的生产者，消费者多线程编程,QT

功能及流程概述:

1. 创建一个生产者，一个消费者，让他们开始运行.  main.cpp 文件
2. 生产者的任务是创建1万个数据.
	创建的数据放到缓存中，但我们只开1024个数据缓存，缓存循环使用
3. 消费者的任务是消费1万个数据.

4.	要有一个变量记录缓冲区中有多少个数据可以使用.
	生产者每创建一个数据,avail_bytes 加1
	消费者每消费一个数据,avail_bytes 减1
	操作这个avail_bytes, 要用互斥量保护 QMutex mutex

5.	如果缓存满了，即avail_bytes==1024时就不生产了，等待消费者消费了， 缓冲有了空间再生产.
	同样,如果缓存为空，就不能再消费了，因为无数据可消费.
	这可以用2个QCondition 变量来表示
	QWaitCondition cond_bufEmpty;
	QWaitCondition cond_bufFull;

6.	当有数据了，要通知被阻塞的消费者线程执行
	当有空间了，要通知被阻塞的生产者线程执行

7. 数据消费完，退出程序

实现:
全部采用全局变量以方便编程
参考global.h,global.cpp

缓冲区: buffer,buffer_size,avail_bytes，
多线程同步变量: mutex, cond_bufFull,cond_bufEmpty 

生产者: Producer.h Producer.cpp
消费者: Consumer.h Consumer.cpp
主程序: main.cpp
