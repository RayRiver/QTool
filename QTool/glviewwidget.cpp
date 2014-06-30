#include "glviewwidget.h"

#include <QDebug>
#include <QtOpenGL>

#include <gl/glu.h>

#include "kazmath/utility.h"
#include "kazmath/vec3.h"
#include "kazmath/mat3.h"
#include "kazmath/quaternion.h"

#include "base/CCDirector.h"

USING_NS_CC;

QColor g_clearColor = Qt::black;

GLViewWidget::GLViewWidget(QWidget *parent, QGLWidget *shareWidget)
	: QGLWidget(parent, shareWidget)
{
	ui.setupUi(this);
}

GLViewWidget::~GLViewWidget()
{

}

void GLViewWidget::initializeGL()
{
	glShadeModel(GL_FLAT);
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
	glClearDepth(1.0f);
	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LEQUAL);
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);
}

void GLViewWidget::paintGL()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glLoadIdentity();	

	glTranslatef(-1.5f, 0.0f, -6.0f);

	glBegin(GL_TRIANGLES);							// 绘制三角形
		glVertex3f( 0.0f, 1.0f, 0.0f);					// 上顶点
		glVertex3f(-1.0f,-1.0f, 0.0f);					// 左下
		glVertex3f( 1.0f,-1.0f, 0.0f);					// 右下
	glEnd();								// 三角形绘制结束

	//Director::getInstance()->mainLoop();


}
#include <qgl.h>
void GLViewWidget::resizeGL( int width, int height )
{
	glViewport(0, 0, (GLint)width, (GLint)height);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	gluPerspective(45.0f,(GLfloat)width/(GLfloat)height,0.1f,100.0f);

	glMatrixMode(GL_MODELVIEW);	
	glLoadIdentity();

}

void GLViewWidget::mousePressEvent( QMouseEvent *event )
{
	qDebug() << "mouse down";
	m_lastMousePos = event->pos();
}

void GLViewWidget::mouseMoveEvent( QMouseEvent *event )
{
	int dx = event->x() - m_lastMousePos.x();
	int dy = event->y() - m_lastMousePos.y();

	if (event->buttons() & Qt::LeftButton) {
		// ... 
	} else if (event->buttons() & Qt::RightButton) {
		// ...
	}
	m_lastMousePos = event->pos();
}

void GLViewWidget::mouseReleaseEvent( QMouseEvent *event )
{
	qDebug() << "mouse up";
	emit clicked();
}
