/*
 * Copyright (C) 2006 Koen Deforche, Kessel-Lo, Belgium.
 *
 * See the LICENSE file for terms of use.
 */

#include <boost/lexical_cast.hpp>

#include <WTimer>
#include "CountDownWidget.h"

CountDownWidget::CountDownWidget(int start, int stop, unsigned msec,
				 WContainerWidget *parent)
  : WText(parent),
    start_(start),
    stop_(stop)
{
  stop_ = std::min(start_ - 1, stop_);  // stop must be smaller than start
  current_ = start_;

  timer_ = new WTimer(this);
  timer_->setInterval(msec);
  timer_->timeout.connect(SLOT(this, CountDownWidget::timerTick));
  timer_->start();

  setText(boost::lexical_cast<std::wstring>(current_));
}

void CountDownWidget::cancel()
{
  timer_->stop();
}

void CountDownWidget::timerTick()
{
  setText(boost::lexical_cast<std::wstring>(--current_));

  if (current_ <= stop_) {
    timer_->stop();
    done.emit();
  }
}
