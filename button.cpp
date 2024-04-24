#include "button.h"

ImageButton::ImageButton(QWidget *parent){
    setParent(parent);
    setToolTip("Stop");
    setSizePolicy(QSizePolicy::Fixed,QSizePolicy::Fixed);
    mButtonUpPixmap = QPixmap("../38_1_pressButtonSound/img/red_button_up.png");
    mButtonDownPixmap = QPixmap("../38_1_pressButtonSound/img/red_button_down.png");
    mCurrentButtonPixmap = mButtonUpPixmap;
    setGeometry(mCurrentButtonPixmap.rect());

    connect(this, &QPushButton::clicked, this, &ImageButton::setDown);

    player = new QMediaPlayer;
    sound = new QMediaContent(QUrl::fromLocalFile("/home/kate/38_1_pressButtonSound/sound/pressKeySound.mp3"));
    player->setMedia(*sound);
    player->setVolume(100);

};

void ImageButton::paintEvent(QPaintEvent *e){
    QPainter p(this);
    p.drawPixmap(e->rect(), mCurrentButtonPixmap);
};

QSize ImageButton::sizeHint()const{
    return QSize(50,50);
};

QSize ImageButton::minimumSizeHint() const{
    return sizeHint();
};

void ImageButton::keyPressEvent(QKeyEvent *e){
    setDown();
};

void ImageButton::setDown(){
    player->play();
    mCurrentButtonPixmap = mButtonDownPixmap;
    update();
    QTimer::singleShot(100, this, &ImageButton::setUp);
};

void ImageButton::setUp(){
    mCurrentButtonPixmap = mButtonUpPixmap;
    update();
};

