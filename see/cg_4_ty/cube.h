#ifndef CUBE_H
#define CUBE_H

#include <QtWidgets>
#include <QtOpenGL>

struct Point
{
    double x, y, z;
};

struct Face
{
    GLuint indices[4];
    GLfloat color[3];
};

class Cube : public QOpenGLWidget
{
public:
    Cube(QWidget* parent = nullptr);
    void zzty();
    void xzty(double x,double y);
    void t1(double d, double p,double q ,double a1,double a2);
protected:
    void initializeGL();
    void paintGL();

private:
    std::vector<std::vector<double>> Matrix_mul(std::vector<std::vector<double>>& A,std::vector<std::vector<double>>& B);

    std::vector<Point> points;
    std::vector<Face> faces;
    void drawCube();

};

#endif // CUBE_H


