#include "cube.h"
#include <GL/glut.h>
#include <QOpenGLFunctions>
#include<cmath>
Cube::Cube(QWidget* parent) : QOpenGLWidget(parent)
{

}

void Cube::initializeGL()
{
    points = {
        { -0.5f, -0.5f, 0.5f },  // 0
        { 0.5f, -0.5f, 0.5f },   // 1
        { 0.5f, 0.5f, 0.5f },    // 2
        { -0.5f, 0.5f, 0.5f },   // 3
        { -0.5f, -0.5f, -0.5f }, // 4
        { 0.5f, -0.5f, -0.5f },  // 5
        { 0.5f, 0.5f, -0.5f },   // 6
        { -0.5f, 0.5f, -0.5f }   // 7
    };
    faces = {
        { { 0, 1, 2, 3 }, { 1.0f, 0.0f, 0.0f } }, // Front face (red)
        { { 1, 5, 6, 2 }, { 0.0f, 1.0f, 0.0f } }, // Right face (green)
        { { 5, 4, 7, 6 }, { 0.0f, 0.0f, 1.0f } }, // Back face (blue)
        { { 4, 0, 3, 7 }, { 1.0f, 1.0f, 0.0f } }, // Left face (yellow)
        { { 3, 2, 6, 7 }, { 1.0f, 0.0f, 1.0f } }, // Top face (purple)
        { { 4, 5, 1, 0 }, { 0.0f, 1.0f, 1.0f } }  // Bottom face (cyan)
    };

    QOpenGLFunctions* glFunctions = QOpenGLContext::currentContext()->functions();
    glFunctions->initializeOpenGLFunctions();
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
}


void Cube::paintGL()
{

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glEnable(GL_DEPTH_TEST);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    //gluPerspective(45.0, width() / height(), 0.1, 100.0);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    //gluLookAt(3, 3, 3, 0, 0, 0, 0, 1, 0);

    drawCube();
}

void Cube::drawCube()
{
    glBegin(GL_QUADS);

    for (const Face& face : faces)
    {
        glColor3f(face.color[0], face.color[1], face.color[2]);

        for (GLuint index : face.indices)
        {
            const Point& point = points[index];
            glVertex3f(point.x, point.y, point.z);
        }
    }
    glEnd();
}
std::vector<std::vector<double>> Cube::Matrix_mul(std::vector<std::vector<double>>& matrix1,std::vector<std::vector<double>>& matrix2)
{
    int rows1 = matrix1.size();
    int cols1 = matrix1[0].size();

    // 矩阵2的维度
    int rows2 = matrix2.size();
    int cols2 = matrix2[0].size();

    // 创建结果矩阵
    std::vector<std::vector<double>> result(rows1, std::vector<double>(cols2, 0));

    // 进行矩阵乘法运算
    for (int i = 0; i < rows1; i++) {
        for (int j = 0; j < cols2; j++) {
            for (int k = 0; k < cols1; k++) {
                result[i][j] += matrix1[i][k] * matrix2[k][j];
            }
        }
    }

    return result;
}
void Cube::zzty()
{
    points = {
        { -0.5f, -0.5f, 0.5f },  // 0
        { 0.5f, -0.5f, 0.5f },   // 1
        { 0.5f, 0.5f, 0.5f },    // 2
        { -0.5f, 0.5f, 0.5f },   // 3
        { -0.5f, -0.5f, -0.5f }, // 4
        { 0.5f, -0.5f, -0.5f },  // 5
        { 0.5f, 0.5f, -0.5f },   // 6
        { -0.5f, 0.5f, -0.5f }   // 7
    };
    std::vector<std::vector<double>> translateMatrix = {
        {0.7071, -0.4082, 0,0},
        {0, 0.8165, 0,0},
        {-0.7071, -0.4082, 0,0},
        {0, 0, 0,1}
    };

    for (int i = 0; i < points.size(); i++) {
        std::vector<std::vector<double>> vertex  = {{double(points[i].x),double(points[i].y),points[i].z,1}};
        auto tt=Matrix_mul(vertex,translateMatrix);
        qDebug()<<points[i].x<<" "<<points[i].y<<" "<<points[i].z;
        points[i].x = tt[0][0];
        points[i].y = tt[0][1];
        points[i].z = tt[0][2];
        qDebug()<<points[i].x<<" "<<points[i].y<<" "<<points[i].z;
    }
    update();

}
void Cube::xzty(double x, double y)
{
    points = {
        { -0.5f, -0.5f, 0.5f },  // 0
        { 0.5f, -0.5f, 0.5f },   // 1
        { 0.5f, 0.5f, 0.5f },    // 2
        { -0.5f, 0.5f, 0.5f },   // 3
        { -0.5f, -0.5f, -0.5f }, // 4
        { 0.5f, -0.5f, -0.5f },  // 5
        { 0.5f, 0.5f, -0.5f },   // 6
        { -0.5f, 0.5f, -0.5f }   // 7
    };
    std::vector<std::vector<double>> translateMatrix = {
        {1, 0, 0,0},
        {0, 1, 0,0},
        {cos(y)/tan(x), sin(y)/tan(x), 0,0},
        {0, 0, 0,1}
    };
    for (int i = 0; i < points.size(); i++) {
        std::vector<std::vector<double>> vertex  = {{double(points[i].x),double(points[i].y),points[i].z,1}};
        auto tt=Matrix_mul(vertex,translateMatrix);
        qDebug()<<points[i].x<<" "<<points[i].y<<" "<<points[i].z;
        points[i].x = tt[0][0];
        points[i].y = tt[0][1];
        points[i].z = tt[0][2];
        qDebug()<<points[i].x<<" "<<points[i].y<<" "<<points[i].z;
    }
    update();
}
void Cube::t1(double d, double p,double q ,double a1,double a2)
{
    points = {
        { -0.5f, -0.5f, 0.5f },  // 0
        { 0.5f, -0.5f, 0.5f },   // 1
        { 0.5f, 0.5f, 0.5f },    // 2
        { -0.5f, 0.5f, 0.5f },   // 3
        { -0.5f, -0.5f, -0.5f }, // 4
        { 0.5f, -0.5f, -0.5f },  // 5
        { 0.5f, 0.5f, -0.5f },   // 6
        { -0.5f, 0.5f, -0.5f }   // 7
    };
    std::vector<std::vector<double>> translateMatrix = {
        {1, 0, 0,p},
        {0, 1, 0,q},
        {0, 0, 1,d},
        {0, 0, 0,1}
    };
    std::vector<std::vector<double>> translateMatrix3 = {
        {cos(a1), 0, -sin(a1),0},
        {0, 1, 0,0},
        {sin(a1), 0, cos(a1),0},
        {0, 0, 0,1}
    };
    std::vector<std::vector<double>> translateMatrix4 = {
        {1, 0, 0,0},
        {0, cos(a2), sin(a2),0},
        {0, -sin(a2), cos(a2),0},
        {0, 0, 0,1}
    };
    std::vector<std::vector<double>> translateMatrix2 = {
        {1, 0, 0,0},
        {0, 1, 0,0},
        {0, 0, 1,0},
        {0, 0, 0,1}
    };
    for (int i = 0; i < points.size(); i++) {
        std::vector<std::vector<double>> vertex  = {{double(points[i].x),double(points[i].y),points[i].z,1}};
        qDebug()<<points[i].x<<" "<<points[i].y<<" "<<points[i].z;
        auto ttt=Matrix_mul(vertex,translateMatrix);
        ttt =(ttt,translateMatrix3);
        ttt=(ttt,translateMatrix4);
       auto tt=(ttt,translateMatrix2);
        points[i].x = tt[0][0];
        points[i].y = tt[0][1];
        points[i].z = tt[0][2];
        qDebug()<<points[i].x<<" "<<points[i].y<<" "<<points[i].z;
    }
    update();
}
