﻿#include <splash_screen_tuner.h>

#include <QFrame>
#include <QLabel>

#include <side.h>
#include <splash_screen_geometry.h>
#include <widget_font.h>

void SplashScreenTuner::TuneLabels(QLabel* version_label,
                                   QLabel* company_name_label,
                                   QLabel* text_label,
                                   QLabel* atm_label) {
  SetText(version_label, text_label, atm_label);
  SetGeometry(version_label, company_name_label, atm_label);
  SetFont(version_label, company_name_label, text_label, atm_label);
  SetAlignment(company_name_label, text_label, atm_label);
}

void SplashScreenTuner::SetText(QLabel* version_label,
                                QLabel* text_label,
                                QLabel* atm_label) {
  version_label->setText("v1.0.1");
  text_label->setText("Press <Enter> to start");
  atm_label->setText("ATM");
}

void SplashScreenTuner::SetGeometry(QLabel* version_label,
                                    QLabel* company_name_label,
                                    QLabel* atm_label) {
  version_label->setGeometry(SplashScreenGeometry::VersionLabel());
  company_name_label->setGeometry(SplashScreenGeometry::CompanyNameLabel());
  atm_label->setGeometry(SplashScreenGeometry::AtmLabel());
}

void SplashScreenTuner::SetFont(QLabel* version_label,
                                QLabel* company_name_label,
                                QLabel* text_label,
                                QLabel* atm_label) {
  version_label->setFont(WidgetFont::SetFont(8));
  company_name_label->setFont(WidgetFont::SetFont(25));
  text_label->setFont(WidgetFont::SetFont(15));
  atm_label->setFont(WidgetFont::SetFont(100));
}

void SplashScreenTuner::SetAlignment(QLabel* company_name_label,
                                     QLabel* text_label,
                                     QLabel* atm_label) {
  company_name_label->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
  text_label->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
  atm_label->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
}
