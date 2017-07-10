﻿#ifndef V_GROUP_COMPOSER_H
#define V_GROUP_COMPOSER_H

#include <QRect>
#include <QVector>

#include <conversion_factor.h>
#include <delta_size.h>

class QWidget;

class VGroupComposer {
 public:
  void SetDeltaSize(const DeltaSize& delta_size);

  void SetInitialGroupGeometry(const QVector<QRect>& widget_vector);
  void ScaleVGroup(QVector<QWidget*> scale_vector);

 private:
  DeltaSize delta_size_;

  QVector<QRect> geometry_vector_;

  QRect head_group_geometry_;
};

#endif  // V_GROUP_COMPOSER_H
