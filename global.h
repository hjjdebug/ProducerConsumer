#ifndef GLOBAL_H
#define GLOBAL_H
#include <QMutex>
#include <QWaitCondition>
#include <QApplication>

extern char buffer[];
extern int BufferSize ;
extern int DataSize;
extern int available_bytes;
extern QMutex mutex;
extern QWaitCondition cond_bufEmpty;
extern QWaitCondition cond_bufFull;
extern QApplication *gApp;
#endif
