﻿#include <atm_main_widget.h>

#include <QCursor>
#include <QIcon>
#include <QPixmap>
#include <QResizeEvent>

#include <app_geometry.h>
#include <atm_composer.h>
#include <delta_size.h>
#include <exit_dialog.h>
#include <graphical_initial_menu.h>
#include <initial_property_installer.h>
#include <main_frame.h>
#include <side.h>
#include <splash_screen_frame.h>

AtmMainWidget::AtmMainWidget(QWidget* parent) : QMainWindow(parent) {
  setWindowTitle("ATM");
  SetInitialSettings();
  SetInitialMainWidgetProperties();
  SetConnections();
}

AtmMainWidget::~AtmMainWidget() {}

void AtmMainWidget::SetCompanyName(const QString& company_name) {
  splash_screen_->SetCompanyName(company_name);
}

QFrame* AtmMainWidget::GetMainFrame() const { return main_frame_; }

void AtmMainWidget::ProcessLoginButtonClick() { emit LoginButtonClicked(); }

void AtmMainWidget::ProcessRegistrationButtonClick() {
  emit RegistrationButtonClicked();
}

void AtmMainWidget::ProcessInitialMenuOpening() { emit ShowInitialMenu(); }

void AtmMainWidget::ShowExitWidget() {
  exit_dialog_->ShowWidgetOnCenterAt(geometry());
}

void AtmMainWidget::keyPressEvent(QKeyEvent* event) {
  switch (event->key()) {
    case Qt::Key_Escape:
      emit Exit();
      break;
    case Qt::Key_Space:
      event->ignore();
      break;
    case Qt::Key_Enter:
    case Qt::Key_Return:
      CheckSplashScreenCondition();
      break;
  }
  QWidget::keyPressEvent(event);
}

void AtmMainWidget::resizeEvent(QResizeEvent*) {
  ComputeDeltaSize();
  emit GeometryChanged();
}

void AtmMainWidget::SetInitialSettings() {
  InitializeObjects();
  SetImages();
  setMinimumSize(AppGeometry::InitialWidth(), AppGeometry::InitialHeight());
}

void AtmMainWidget::InitializeObjects() {
  exit_dialog_ = new ExitDialog(this);
  main_frame_ = new MainFrame(this);
  splash_screen_ = new SplashScreenFrame(main_frame_);
  initial_menu_ = new GraphicalInitialMenu(main_frame_);
}

void AtmMainWidget::SetImages() {
  QCursor custom_cursor(QPixmap(":/images/app_cursor.png"));
  setCursor(custom_cursor);
  setWindowIcon(QIcon(":/images/project_icon.png"));
}

void AtmMainWidget::SetInitialMainWidgetProperties() {
  InitialPropertyInstaller::SetInitialProperties(
      this, AppGeometry::InitialWidth(), AppGeometry::InitialHeight(),
      InitialPropertyInstaller::kResize);
  setStyleSheet("background-color:black;");
  exit_dialog_->setModal(true);
}

void AtmMainWidget::SetConnections() {
  connect(initial_menu_, SIGNAL(LoginButtonClicked()),
          SLOT(ProcessLoginButtonClick()));
  connect(initial_menu_, SIGNAL(RegistrationButtonClicked()),
          SLOT(ProcessRegistrationButtonClick()));
  connect(this, SIGNAL(ShowInitialMenu()), initial_menu_, SLOT(ShowMenu()));

  connect(this, SIGNAL(SplashScreenEnterPressed()), splash_screen_,
          SLOT(Close()));
  connect(splash_screen_, SIGNAL(FrameClosed()), initial_menu_,
          SLOT(ShowFirstTime()));
  connect(this, SIGNAL(Exit()), SLOT(ShowExitWidget()));

  connect(this, SIGNAL(GeometryChanged()), splash_screen_,
          SLOT(ChangeGeometry()));
  connect(this, SIGNAL(GeometryChanged()), initial_menu_,
          SLOT(ChangeGeometry()));
  connect(this, SIGNAL(GeometryChanged()), main_frame_, SLOT(ChangeGeometry()));
}

void AtmMainWidget::ComputeDeltaSize() {
  int delta_width = width() - AppGeometry::InitialWidth();
  int delta_height = height() - AppGeometry::InitialHeight();
  AtmComposer::SetDeltaSize(DeltaSize(delta_width, delta_height));
}

void AtmMainWidget::CheckSplashScreenCondition() {
  if (!is_splash_screen_closed_) {
    emit SplashScreenEnterPressed();
    is_splash_screen_closed_ = true;
  }
}
