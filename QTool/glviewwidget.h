#ifndef GLVIEWWIDGET_H
#define GLVIEWWIDGET_H

#include <QGLWidget>
#include <QOpenGLFunctions>
#include "ui_glviewwidget.h"

class GLViewWidget : public QGLWidget
{
	Q_OBJECT

public:
	explicit GLViewWidget(QWidget *parent = 0, QGLWidget *shareWidget = 0);
	~GLViewWidget();

signals:
	void clicked();

protected:
	void initializeGL();
	void paintGL();
	void resizeGL(int width, int height);
	void mousePressEvent(QMouseEvent *event);
	void mouseMoveEvent(QMouseEvent *event);
	void mouseReleaseEvent(QMouseEvent *event);

private:
	Ui::GLViewWidget ui;

private:
	QPoint m_lastMousePos;
};

#endif // GLVIEWWIDGET_H
