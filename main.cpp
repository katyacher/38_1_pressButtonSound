#include <QApplication>
#include <iostream>
#include "button.h"


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    ImageButton redButton(nullptr);

    redButton.setFixedSize(200,210);
    redButton.move(1000,400);

    QObject::connect(&redButton, &QPushButton::clicked, [](){std::cout << "clicked\n";});

    redButton.show();
    return a.exec();
}
