/*
 * Copyright (C) 2005 Wim Dumon
 *
 * See the LICENSE file for terms of use.
 */

#include "HangmanWidget.h"

#include <WBreak>
#include <WCssDecorationStyle>
#include <WTable>
#include <WText>
#include <WTableCell>
#include <WLineEdit>
#include <WPushButton>
#include <WImage>
#include <WSignalMapper>
#include <boost/lexical_cast.hpp>

#include "Dictionary.h"
#include "HangmanDb.h"

HangmanWidget::HangmanWidget(std::wstring user, Dictionary dict,
			     WContainerWidget *parent):
   WContainerWidget(parent),
   MaxGuesses(9),
   User(user),
   Dict(dict)
{
   setContentAlignment(AlignCenter);

   Title = new WText(L"Guess the word!", this);
   Title->decorationStyle().font().setSize(WFont::XLarge);

   WordContainer = new WContainerWidget(this);
   WordContainer->setMargin(WLength(20), Top | Bottom);
   WordContainer->setContentAlignment(AlignCenter);
   WCssDecorationStyle& style = WordContainer->decorationStyle();
   style.setBorder(WBorder(WBorder::Solid));
   style.font().setFamily(WFont::Monospace, L"courier");
   style.font().setSize(WFont::XXLarge);

   StatusText = new WText(this);
   new WBreak(this);
   createHangmanImages(this);
   createAlphabet(this);
   new WBreak(this);
   NewGameButton = new WPushButton(L"New Game", this);
   NewGameButton->clicked.connect(SLOT(this, HangmanWidget::newGame));

   // prepare for first game
   newGame();
}

void HangmanWidget::createHangmanImages(WContainerWidget *parent)
{
   for(unsigned int i = 0; i <= MaxGuesses; ++i) {
      std::string fname = "icons/hangman";
      fname += boost::lexical_cast<std::string>(i) + ".png";
      WImage *theImage = new WImage(fname, parent);
      HangmanImages.push_back(theImage);

      // Although not necessary, we can avoid flicker (on konqueror)
      // by presetting the image size.
      theImage->resize(WLength(256), WLength(256));
   }

   HurrayImage = new WImage("icons/hangmanhurray.png", parent);
   resetImages(); // Hide all images
}

void HangmanWidget::createAlphabet(WContainerWidget *parent)
{
   LetterButtonLayout = new WTable(parent);

   // The default width of a table is 100%...
   LetterButtonLayout->resize(WLength(13*30), WLength());

   WSignalMapper<WPushButton *> *mapper
     = new WSignalMapper<WPushButton *>(this);

   for(unsigned int i = 0; i < 26; ++i) {
      std::wstring c(1, 'A' + i);
      WPushButton *character =
	 new WPushButton(c, LetterButtonLayout->elementAt(i / 13, i % 13));
      LetterButtons.push_back(character);
      character->resize(WLength(30), WLength());
      mapper->mapConnect(character->clicked, character);
   }

   mapper->mapped.connect(SLOT(this, HangmanWidget::processButton));
}

void HangmanWidget::newGame()
{
   Word = RandomWord(Dict);
   Title->setText(L"Guess the word, " + User + L"!");
   NewGameButton->hide(); // don't let the player chicken out

   // Bring widget to initial state
   resetImages();
   resetButtons();
   BadGuesses = DisplayedLetters = 0;
   HangmanImages[0]->show();

   // Prepare the widgets for the new word
   WordContainer->clear();
   WordLetters.clear();
   for(unsigned int i = 0; i < Word.size(); ++i) {
      WText *c = new WText(L"-", WordContainer);
      WordLetters.push_back(c);
   }

   // resize appropriately so that the border nooks nice.
   WordContainer->resize(WLength(Word.size() * 1.5, WLength::FontEx),
			 WLength());

   StatusText->setText(L"");
}

void HangmanWidget::processButton(WPushButton *button)
{
   if (!button->isEnabled())
     return;

   const wchar_t *txt = button->text().value().c_str();
   wchar_t c = txt[0];
   if(std::find(Word.begin(), Word.end(), c) != Word.end())
      registerCorrectGuess(c);
   else
      registerBadGuess();
   button->disable();
}

void HangmanWidget::registerBadGuess()
{
   if(BadGuesses < MaxGuesses) {
      HangmanImages[BadGuesses]->hide();
      BadGuesses++;
      HangmanImages[BadGuesses]->show();
      if(BadGuesses == MaxGuesses) {
	 StatusText->setText(L"You hang... <br />"
			     "The correct answer was: " + Word);
	 LetterButtonLayout->hide();
	 NewGameButton->show();
	 HangmanDb::addToScore(User, -10);
      }
   }
}

void HangmanWidget::registerCorrectGuess(wchar_t c)
{
   for(unsigned int i = 0; i < Word.size(); ++i) {
      if(Word[i] == c) {
	 DisplayedLetters++;
	 WordLetters[i]->setText(std::wstring(1, c));
      }
   }
   if(DisplayedLetters == Word.size()) {
      StatusText->setText(L"You win!");
      HangmanImages[BadGuesses]->hide();
      HurrayImage->show();
      LetterButtonLayout->hide();
      NewGameButton->show();
      HangmanDb::addToScore(User, 20 - BadGuesses);
   }
}

void HangmanWidget::resetImages()
{
    HurrayImage->hide();
    for(unsigned int i = 0; i < HangmanImages.size(); ++i)
       HangmanImages[i]->hide();
}

void HangmanWidget::resetButtons()
{
   for(unsigned int i = 0; i < LetterButtons.size(); ++i) {
      LetterButtons[i]->enable();
   }
   LetterButtonLayout->show();
}
