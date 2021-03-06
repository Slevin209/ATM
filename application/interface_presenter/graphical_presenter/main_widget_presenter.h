﻿#ifndef MAIN_WIDGET_PRESENTER_H
#define MAIN_WIDGET_PRESENTER_H

#include <QObject>
#include <QRect>

class AtmMainWidget;
class GraphicalRegistrationMenu;
class GraphicalLoginMenu;

class MainWidgetPresenter : public QObject {
  Q_OBJECT
 public:
  explicit MainWidgetPresenter(QObject* parent = nullptr);
  ~MainWidgetPresenter();

  void RunApplication();

 public slots:
  void SetWidgetGeometry(const QRect& initial_position);
  void SetMaximized(bool is_maximized);

 private:
  void CreateLoginMenu();
  void CreateRegistrationMenu();

  void ConnectLoginMenu();
  void ConnectRegistrationMenu();

  AtmMainWidget* atm_main_widget_ = nullptr;
  GraphicalLoginMenu* login_menu_ = nullptr;
  GraphicalRegistrationMenu* registration_menu_ = nullptr;

  QRect main_widget_position_;

  bool is_maximized_ = false;
};

#endif  // MAIN_WIDGET_PRESENTER_H
