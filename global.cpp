#include"global.h"

//假定数据缓冲区 1K
char buffer[1024];
int BufferSize = 1024;
int available_bytes=0;
//假定需要产生1万条数据,数据可以循环使用buffer
int DataSize = 10000 ;
//多线程编程
QMutex mutex;
QWaitCondition cond_bufEmpty;
QWaitCondition cond_bufFull;
