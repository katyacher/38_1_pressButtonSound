#ifndef BUTTON_H
#define BUTTON_H


#include <QPushButton>
#include <QPixmap>
#include <QPainter>
#include <QPaintEvent>
#include <QTimer>

#include <QMediaPlayer>
#include <QMediaContent>

class ImageButton : public QPushButton{
    Q_OBJECT
public:
    ImageButton() = default;
    ImageButton(QWidget *perent);
    void paintEvent(QPaintEvent *e) override;
    QSize sizeHint() const override;
    QSize minimumSizeHint() const override;
    void keyPressEvent(QKeyEvent *e) override;

public slots:
    void setUp();
    void setDown();
private:
    QPixmap mCurrentButtonPixmap;
    QPixmap mButtonDownPixmap;
    QPixmap mButtonUpPixmap;

    bool isDown = false;

    QMediaPlayer *player;
    QMediaContent *sound;
};



#endif
