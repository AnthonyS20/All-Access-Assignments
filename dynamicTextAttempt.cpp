// dynamicTextAttempt.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Aspose.PDF.Cpp/Text/TextFragment.h"
#include "Aspose.PDF.Cpp/Text/TextFragmentState.h"
#include "Aspose.PDF.Cpp/Text/Font.h"
#include "Aspose.PDF.Cpp/Document.h"
#include "Aspose.PDF.Cpp/PageCollection.h"
#include <Aspose.PDF.Cpp/Page.h>
#include <Aspose.PDF.Cpp/Text/TextAbsorber.h>
#include <Aspose.PDF.Cpp/Text/TextFragmentAbsorber.h>
#include <Aspose.PDF.Cpp/Text/TextFragmentCollection.h>

using namespace System;
using namespace Aspose::Pdf;
using namespace Aspose::Pdf::Text;


int main()
{
    std::cout << "Please input the filepath of the document you wish to have altered.";
    std::string filepath;
    std::cin >> filepath;
    String filename(filepath);
  //Test file name is "C:/Users/User/Documents/DynamicTextTestFile.pdf"
  auto document = MakeObject<Document>(filename);

  auto textFragmentAbsorber = MakeObject<TextFragmentAbsorber>(
      MakeObject<TextEditOptions>(TextEditOptions::FontReplace::RemoveUnusedFonts));

  document->get_Pages()->Accept(textFragmentAbsorber);
  //Document pages processed

  auto textFragmentCollection = textFragmentAbsorber->get_TextFragments();
  float fontSize = 0.0;
  float adjustedSize = 0.0;
  std::cout << "Please enter your preferred Font Size: ";
  std::cin >> adjustedSize;
  for (auto textFragment : textFragmentCollection) {
      //Each text fragment is adjusted to new text size
      textFragment->get_TextState()->set_FontSize(adjustedSize);
  }
  String updatedDoc("C:/Users/User/Documents/DynamicTextTestResult.pdf");
  document->Save(updatedDoc);
  //Document saved to specificied Location
}

