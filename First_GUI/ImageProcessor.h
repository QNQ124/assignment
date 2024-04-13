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

#endif // IMAGEPROCESSOR_H
