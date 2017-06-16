#include <QApplication>
#include "start_activity.h"
#include "external.h"
#include "data.h"
#include <QDebug>

using namespace std;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    start_activity w;
    w.show();

    data::loadData();

    return a.exec();
}
