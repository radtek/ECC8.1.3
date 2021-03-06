#include "WValidationStatus"
#include "WContainerWidget"
#include "WFormWidget"

namespace Wt {

WValidationStatus::WValidationStatus(WFormWidget *field,
				     WWidget *validStateWidget,
				     WWidget *invalidStateWidget,
				     WWidget *invalidEmptyStateWidget,
				     WContainerWidget *parent)
  : WCompositeWidget(parent),
    validated(this),
    field_(field),
    validStateWidget_(validStateWidget),
    invalidStateWidget_(invalidStateWidget),
    invalidEmptyStateWidget_(invalidEmptyStateWidget)
{
  setImplementation(impl_ = new WContainerWidget());
  impl_->setInline(true);

  state_ = field_->validate();

  if (validStateWidget_) {
    impl_->addWidget(validStateWidget_);
    validStateWidget_->setHidden(state_ != WValidator::Valid);
  }

  if (invalidStateWidget_) {
    impl_->addWidget(invalidStateWidget_);
    invalidStateWidget_->setHidden(state_ != WValidator::Invalid);
  }

  if (invalidEmptyStateWidget_) {
    impl_->addWidget(invalidEmptyStateWidget_);
    invalidEmptyStateWidget_->setHidden(state_ != WValidator::InvalidEmpty);
  }

  field->changed.connect(SLOT(this, WValidationStatus::inputChanged));
  field->keyWentUp.connect(SLOT(this, WValidationStatus::inputChanged));
  //field->keyPressed.connect(SLOT(this, WValidationStatus::inputChanged));
}

void WValidationStatus::inputChanged()
{
  WValidator::State state = field_->validate();

  if (state != state_) {
    if (validStateWidget_)
      validStateWidget_->setHidden(state != WValidator::Valid);
    if (invalidStateWidget_)
      invalidStateWidget_->setHidden(state != WValidator::Invalid);
    if (invalidEmptyStateWidget_)
      invalidEmptyStateWidget_->setHidden(state != WValidator::InvalidEmpty);

    if ((state_ == WValidator::Valid) || (state == WValidator::Valid)) {
      state_ = state;
      validated.emit(state_ == WValidator::Valid);
    } else
      state_ = state;
  }
}

}
