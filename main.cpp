#include "Canvas.h"
#include "dgcapp.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);  

    dgcapp d;
    d.show();

    return app.exec();
}