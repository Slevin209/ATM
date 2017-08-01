﻿#include <description_menu.h>

#include <QFrame>
#include <QList>
#include <QResizeEvent>
#include <QWidget>

#include <atm_button.h>
#include <demo_menu_geometry.h>
#include <description_frame.h>
#include <side.h>

DescriptionMenu::DescriptionMenu(QWidget* parent)
    : BaseAtmFrame(parent), description_frame_(new QFrame(this)) {
  SetInitialFrameGeometry(DemoMenuGeometry::DemoFrame());
  SetInitialBackButtonGeometry(DemoMenuGeometry::BackButton());

  description_frame_->setGeometry(DemoMenuGeometry::DescriprionFrame());

  description_frame_->setStyleSheet(
      "QFrame {"
      "border: 2px solid green;}");

  composer_.SetStretchFactor(1.0, 0.95);
  composer_.SetStretchSide(Side::kDown | Side::kRight);
  composer_.SetTransformationType(GeometryComposer::kStretch);

  SetFrameAnimation(Side::kLeft, Side::kRight, kHalfASecond, this);
}

DescriptionMenu::~DescriptionMenu() {}

void DescriptionMenu::SetDeltaSize(const DeltaSize& delta_size) {
  BaseAtmFrame::SetDeltaSize(delta_size);
  delta_size_ = delta_size;
}

void DescriptionMenu::resizeEvent(QResizeEvent*) {
  BaseAtmFrame::SetDeltaSize(delta_size_);

  composer_.SetDeltaSize(delta_size_);
  composer_.ComposeGeometry(DemoMenuGeometry::DescriprionFrame(),
                            description_frame_);
  ScaleBackButton();
}
