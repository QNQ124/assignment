#ifndef IMAGEPROCESSOR_H
#define IMAGEPROCESSOR_H

#include <QObject>

class ImageProcessor1 : public QObject
{
    Q_OBJECT
public:
    explicit ImageProcessor1(QObject *parent = nullptr);
    Q_INVOKABLE int applyGrayScale(const QString &filename);

signals:

public slots:
};

class ImageProcessor2 : public QObject
{
    Q_OBJECT
public:
    explicit ImageProcessor2(QObject *parent = nullptr);
    Q_INVOKABLE int applyBlackAndWhite(const QString &filename);

signals:

public slots:
};

class ImageProcessor3 : public QObject
{
    Q_OBJECT
public:
    explicit ImageProcessor3(QObject *parent = nullptr);
    Q_INVOKABLE int applyPurple(const QString &filename);

signals:

public slots:
};

class ImageProcessor4 : public QObject
{
    Q_OBJECT
public:
    explicit ImageProcessor4(QObject *parent = nullptr);
    Q_INVOKABLE int applyInvert(const QString &filename);

signals:

public slots:
};

class ImageProcessor5 : public QObject
{
    Q_OBJECT
public:
    explicit ImageProcessor5(QObject *parent = nullptr);
    Q_INVOKABLE int applyInfrared(const QString &filename);

signals:

public slots:
};

class ImageProcessor6 : public QObject
{
    Q_OBJECT
public:
    explicit ImageProcessor6(QObject *parent = nullptr);
    Q_INVOKABLE int applyNoise(const QString &filename);

signals:

public slots:
};

class ImageProcessor7 : public QObject
{
    Q_OBJECT
public:
    explicit ImageProcessor7(QObject *parent = nullptr);
    Q_INVOKABLE int applyNightVision(const QString &filename);

signals:

public slots:
};

class ImageProcessor8 : public QObject
{
    Q_OBJECT
public:
    explicit ImageProcessor8(QObject *parent = nullptr);
    Q_INVOKABLE int applyDetectEdges(const QString &filename);

signals:

public slots:
};

class ImageProcessor9 : public QObject
{
    Q_OBJECT
public:
    explicit ImageProcessor9(QObject *parent = nullptr);
    Q_INVOKABLE int applyOilPainting(const QString &filename);

signals:

public slots:
};

class ImageProcessor10 : public QObject
{
    Q_OBJECT
public:
    explicit ImageProcessor10(QObject *parent = nullptr);
    Q_INVOKABLE int applySunlight(const QString &filename);

signals:

public slots:
};

class ImageProcessor11 : public QObject
{
    Q_OBJECT
public:
    explicit ImageProcessor11(QObject *parent = nullptr);
    Q_INVOKABLE int applyOldTV(const QString &filename);

signals:

public slots:
};

class ImageProcessor12 : public QObject
{
    Q_OBJECT
public:
    explicit ImageProcessor12(QObject *parent = nullptr);
    Q_INVOKABLE int savingImage(const QString &filename);

signals:

public slots:
};

class ImageProcessor13 : public QObject
{
    Q_OBJECT
public:
    explicit ImageProcessor13(QObject *parent = nullptr);
    Q_INVOKABLE int applyMerge(const QString &filename1, const QString &filename2, const int choice);

signals:

public slots:
};

class ImageProcessor14 : public QObject
{
    Q_OBJECT
public:
    explicit ImageProcessor14(QObject *parent = nullptr);
    Q_INVOKABLE int applyResize(const QString &filename1, const int &new_width, const int &new_height);

signals:

public slots:
};

class ImageProcessor15 : public QObject
{
    Q_OBJECT
public:
    explicit ImageProcessor15(QObject *parent = nullptr);
    Q_INVOKABLE int applyFlip(const QString &filename, const int &choice);

signals:

public slots:
};

class ImageProcessor16 : public QObject
{
    Q_OBJECT
public:
    explicit ImageProcessor16(QObject *parent = nullptr);
    Q_INVOKABLE int applySkewing(const QString &filename, const int &angle);

signals:

public slots:
};

class ImageProcessor17 : public QObject
{
    Q_OBJECT
public:
    explicit ImageProcessor17(QObject *parent = nullptr);
    Q_INVOKABLE int applyRotate(const QString &filename, const int &degree_rotation);

signals:

public slots:
};

class ImageProcessor18 : public QObject
{
    Q_OBJECT
public:
    explicit ImageProcessor18(QObject *parent = nullptr);
    Q_INVOKABLE int applyBlur(const QString &filename, int blur_level);

signals:

public slots:
};

class ImageProcessor19 : public QObject
{
    Q_OBJECT
public:
    explicit ImageProcessor19(QObject *parent = nullptr);
    Q_INVOKABLE int applyBrightness(const QString &filename, int num_brightness, int choice1);

signals:

public slots:
};

#endif // IMAGEPROCESSOR_H
