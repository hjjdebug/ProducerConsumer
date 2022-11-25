#include <QApplication>
#include"Producer.h"
#include"Consumer.h"

QApplication *gApp;
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
	gApp = &a;
    Producer producer;
    Consumer consumer;
    producer.start();
    consumer.start();
    return a.exec();
}
