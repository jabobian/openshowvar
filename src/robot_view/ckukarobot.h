#ifndef CKUKAROBOT_H
#define CKUKAROBOT_H

#include <QtGui>
#include "cglscene.h"
#include "../variabledb.h"
#include "../kukavar.h"

class CKUKARobot : public QDockWidget{
    Q_OBJECT

public:
    CKUKARobot( VariableDB* databaseVar, int updateInterval = 500, QWidget *parent = 0);
    ~CKUKARobot();

    void setRobotPosition( float r1, float r2, float r3, float r4, float r5, float r6 );

private:
    void initSceneInteractionControls();

private:
    CGLScene*   m_scene;

private://scene interaction
    QWidget*    mainContainer;
    QWidget*    m_controlsContainer;
    QToolBar    m_toolBar;
    QAction*    m_traslateObject;
    QAction*    m_rotateObject;

    QAction*    m_traslateScene;
    QAction*    m_rotateScene;

    QTimer      m_pulsar;

    VariableDB* m_databaseVar;

    QString     m_robotIP; //ip address del robot da cui si vuole leggere la posizione
    QComboBox   m_robotList;

public slots:
    void setTraslateObjMode( bool toggle );
    void setRotateObjMode( bool toggle );

    void setTraslateSceneMode( bool toggle );
    void setRotateSceneMode( bool toggle );

    //void inputRobotChanged( QString s );

    void updatePulsar();

    void robotListSelection( QString ip );

};

#endif // CKUKAROBOT_H
