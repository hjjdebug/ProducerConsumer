#ifndef CONSUMER_H
#define CONSUMER_H
#include<QThread>
class Consumer : public QThread
{
public:
    Consumer(){}
    ~Consumer(){}
    void run() Q_DECL_OVERRIDE;
};
#endif // CONSUMER_H
