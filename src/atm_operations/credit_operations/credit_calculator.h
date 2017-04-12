﻿#ifndef CREDIT_CALCULATOR_H
#define CREDIT_CALCULATOR_H

#include <vector>

class CreditCalculator {
 public:
  int CalculateMaxCreditSum(int cash);

  void SetUserCreditSum(int credit_sum);

 private:
  int multiplier_ = 15;
  int max_credit_sum_ = 0;
  int user_credit_sum_ = 0;

  std::vector<double> payments_;
};

#endif  // CREDIT_CALCULATOR_H
