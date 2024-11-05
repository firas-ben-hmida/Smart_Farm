#ifndef IMAGE_H
#define IMAGE_H
#include <QPixmap>


class image
{
public:
    image();
     QPixmap productImage;
    void loadImage(const QString& imagePath);
};

#endif // IMAGE_H
