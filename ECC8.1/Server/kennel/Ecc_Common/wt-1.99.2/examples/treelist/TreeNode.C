/*
 * Copyright (C) 2005 Koen Deforche, Kessel-Lo, Belgium.
 *
 * See the LICENSE file for terms of use.
 */
#include <boost/lexical_cast.hpp>
#include <WTable>
#include <WTableCell>
#include <WImage>
#include <WText>
#include <WCssDecorationStyle>

#include "TreeNode.h"
#include "IconPair.h"

using std::find;

std::string TreeNode::imageLine_[] = { "icons/line-middle.gif",
					"icons/line-last.gif" };
std::string TreeNode::imagePlus_[] = { "icons/nav-plus-line-middle.gif",
					"icons/nav-plus-line-last.gif" };
std::string TreeNode::imageMin_[] = { "icons/nav-minus-line-middle.gif",
				       "icons/nav-minus-line-last.gif" };

TreeNode::TreeNode(const std::wstring labelText,
		   Wt::WText::Formatting labelFormatting,
		   IconPair *labelIcon,
		   Wt::WContainerWidget *parent)
  : Wt::WCompositeWidget(parent),
    parentNode_(0),
    labelIcon_(labelIcon)
{
  // pre-learned stateless implementations ...
  implementStateless(&TreeNode::expand, &TreeNode::undoExpand);
  implementStateless(&TreeNode::collapse, &TreeNode::undoCollapse);

  // ... or auto-learned stateless implementations
  // which do not need undo functions
  //implementStateless(&TreeNode::expand);
  //implementStateless(&TreeNode::collapse);

  setImplementation(layout_ = new Wt::WTable());

  expandIcon_ = new IconPair(imagePlus_[Last], imageMin_[Last]);
  expandIcon_->hide();
  noExpandIcon_ = new Wt::WImage(imageLine_[Last]);

  expandedContent_ = new Wt::WContainerWidget();
  expandedContent_->hide();

  labelText_ = new Wt::WText(labelText);
  labelText_->setFormatting(labelFormatting);
  labelText_->setStyleClass(L"treenodelabel");
  childCountLabel_ = new Wt::WText();
  childCountLabel_->setMargin(Wt::WLength(7), Left);
  childCountLabel_->setStyleClass(L"treenodechildcount");

  layout_->elementAt(0, 0)->addWidget(expandIcon_);
  layout_->elementAt(0, 0)->addWidget(noExpandIcon_);

  if (labelIcon_) {
    layout_->elementAt(0, 1)->addWidget(labelIcon_);
    labelIcon_->setVerticalAlignment(AlignMiddle);
  }
  layout_->elementAt(0, 1)->addWidget(labelText_);
  layout_->elementAt(0, 1)->addWidget(childCountLabel_);

  layout_->elementAt(1, 1)->addWidget(expandedContent_);

  layout_->elementAt(0, 0)->setContentAlignment(AlignTop);
  layout_->elementAt(0, 1)->setContentAlignment(AlignMiddle);

  expandIcon_->icon1Clicked.connect(SLOT(this, TreeNode::expand));
  expandIcon_->icon2Clicked.connect(SLOT(this, TreeNode::collapse));
} //

bool TreeNode::isLastChildNode() const
{
  if (parentNode_) {
    return parentNode_->childNodes_.back() == this;
  } else
    return true;
}

void TreeNode::addChildNode(TreeNode *node)
{
  childNodes_.push_back(node);
  node->parentNode_ = this;

  expandedContent_->addWidget(node);

  childNodesChanged();
}

void TreeNode::removeChildNode(TreeNode *node)
{
  childNodes_.erase(find(childNodes_.begin(), childNodes_.end(), node));

  node->parentNode_ = 0;

  expandedContent_->removeWidget(node);

  childNodesChanged();
} //

void TreeNode::childNodesChanged()
{
  for (unsigned i = 0; i < childNodes_.size(); ++i)
    childNodes_[i]->adjustExpandIcon();

  adjustExpandIcon();

  if (childNodes_.size())
    childCountLabel_
      ->setText(L"(" + boost::lexical_cast<std::wstring>(childNodes_.size())
		+ L")");
  else
    childCountLabel_->setText(L"");

  resetLearnedSlots();
} //

void TreeNode::collapse()
{
  wasCollapsed_ = expandedContent_->isHidden();

  expandIcon_->setState(0);
  expandedContent_->hide();
  if (labelIcon_)
    labelIcon_->setState(0);
} //

void TreeNode::expand()
{
  wasCollapsed_ = expandedContent_->isHidden();

  expandIcon_->setState(1);
  expandedContent_->show();
  if (labelIcon_)
    labelIcon_->setState(1);

  /*
   * collapse all children
   */
  for (unsigned i = 0; i < childNodes_.size(); ++i)
    childNodes_[i]->collapse();
} //

void TreeNode::undoCollapse()
{
  if (!wasCollapsed_) {
    // re-expand
    expandIcon_->setState(1);
    expandedContent_->show();
    if (labelIcon_)
      labelIcon_->setState(1);    
  }
}

void TreeNode::undoExpand()
{
  if (wasCollapsed_) {
    // re-collapse
    expandIcon_->setState(0);
    expandedContent_->hide();
    if (labelIcon_)
      labelIcon_->setState(0);
  }

  /*
   * undo collapse of children
   */
  for (unsigned i = 0; i < childNodes_.size(); ++i)
    childNodes_[i]->undoCollapse();  
} //

void TreeNode::adjustExpandIcon()
{
  ImageIndex index = isLastChildNode() ? Last : Middle;

  if (expandIcon_->icon1()->imageRef() != imagePlus_[index])
    expandIcon_->icon1()->setImageRef(imagePlus_[index]);
  if (expandIcon_->icon2()->imageRef() != imageMin_[index])
    expandIcon_->icon2()->setImageRef(imageMin_[index]);
  if (noExpandIcon_->imageRef() != imageLine_[index])
    noExpandIcon_->setImageRef(imageLine_[index]);

  if (index == Last) {
    layout_->elementAt(0, 0)
      ->decorationStyle().setBackgroundImage("");
    layout_->elementAt(1, 0)
      ->decorationStyle().setBackgroundImage("");
  } else {
    layout_->elementAt(0, 0)
      ->decorationStyle().setBackgroundImage("icons/line-trunk.gif",
					     Wt::WCssDecorationStyle::RepeatY);
    layout_->elementAt(1, 0)
      ->decorationStyle().setBackgroundImage("icons/line-trunk.gif",
					     Wt::WCssDecorationStyle::RepeatY);
  } //

  if (childNodes_.empty()) {
    if (noExpandIcon_->isHidden()) {
      noExpandIcon_->show();
      expandIcon_->hide();
    }
  } else {
    if (expandIcon_->isHidden()) {
      noExpandIcon_->hide();
      expandIcon_->show();
    }
  }
} //
