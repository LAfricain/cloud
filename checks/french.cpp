/*
 Copyright (©) 2003-2017 Teus Benschop.
 
 This program is free software; you can redistribute it and/or modify
 it under the terms of the GNU General Public License as published by
 the Free Software Foundation; either version 3 of the License, or
 (at your option) any later version.
 
 This program is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 GNU General Public License for more details.
 
 You should have received a copy of the GNU General Public License
 along with this program; if not, write to the Free Software
 Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
 */


#include <checks/french.h>
#include <filter/string.h>
#include <filter/usfm.h>
#include <database/check.h>
#include <locale/translate.h>


// In French there is a no-break space after the « and before the » ! ? : ;
// The Unicode value for the no-break space is U+00A0.
void Checks_French::spaceBeforeAfterPunctuation (string bible, int book, int chapter,
                                                 map <int, string> texts)
{
  Database_Check database_check;
  string nbsp = non_breaking_space_u00A0 ();
  vector <string> right_punctuation = { right_guillemet(), "!", "?", ":", ";" };
  for (auto element : texts) {
    int verse = element.first;

    {
      string text = element.second;
      size_t pos = text.find (left_guillemet ());
      while (pos != string::npos) {
        text.erase (0, pos + left_guillemet ().size ());
        if (text.find (" ") == 0) {
          string message = left_guillemet () + " - " + translate ("Should be followed by a no-break space rather than a plain space in French");
          database_check.recordOutput (bible, book, chapter, verse, message);
        } else if (text.find (nbsp) != 0) {
          string message = left_guillemet () + " - " + translate ("Should be followed by a no-break space in French");
          database_check.recordOutput (bible, book, chapter, verse, message);
        }
        pos = text.find (left_guillemet ());
      }
    }
    
    for (auto punctuation : right_punctuation) {
      string text = element.second;
      size_t pos = text.find (punctuation);
      while (pos != string::npos) {
        if ((pos > 0) && (text.substr (pos - 1, 1) == " ")) {
          string message = punctuation + " - " + translate ("Should be preceded by a no-break space rather than a plain space in French");
          database_check.recordOutput (bible, book, chapter, verse, message);
        } else if ((pos > 2) && (text.substr (pos - 2, 2) != nbsp)) {
          string message = punctuation + " - " + translate ("Should be preceded by a no-break space in French");
          database_check.recordOutput (bible, book, chapter, verse, message);
        }
        text.erase (0, pos + punctuation.size ());
        pos = text.find (punctuation);
      }
    }
    
  }
}


// In French, if a citation starts with "«", all subsequent paragraphs within that citation, may begin with a new «.
// Example:
// « This is the text of the citation.
// « This is a new paragraph, and it ends the citation ».
// This checks on that style.
void Checks_French::citationStyle (string bible, int book, int chapter,
                                   vector <map <int, string>> verses_paragraphs)
{
  Database_Check database_check;

  // Store the state of the previous paragraph.
  // It indicates whether any citation was left open at the end of the paragraph.
  bool previous_paragraph_open_citation = false;
  
  // Iterate over the paragraphs.
  for (unsigned int paragraph_counter = 0; paragraph_counter < verses_paragraphs.size (); paragraph_counter++) {
    
    // Container with verse numbers as the keys, plus the text of the whole paragraph.
    map <int, string> verses_paragraph = verses_paragraphs [paragraph_counter];
    
    // Skip empty containers.
    if (verses_paragraph.empty ()) continue;

    // If this the first paragraph in the chapter, leave it as it is.
    // If it is not the first paragraph, and if the previous paragraph left an open citation,
    // this new paragraph should start with the French citation marker.
    if (paragraph_counter) {
      if (previous_paragraph_open_citation) {
        int verse = verses_paragraph.begin()->first;
        string text = verses_paragraph.begin()->second;
        if (!text.empty ()) {
          string character = unicode_string_substr (text, 0, 1);
          if (character != "«") {
            string message = translate ("The previous paragraph contains a citation not closed with a » therefore the current paragraph is expected to start with a « to continue that citation in French");
            database_check.recordOutput (bible, book, chapter, verse, message);
          }
        }
      }
    }
    
    // Determine whether the current paragraph opens a citation and does not close it.
    string paragraph;
    for (auto element : verses_paragraph) {
      paragraph.append (element.second);
    }
    int opener_count = 0;
    filter_string_str_replace ("«", "", paragraph, &opener_count);
    int closer_count = 0;
    filter_string_str_replace (right_guillemet (), "", paragraph, &closer_count);
    previous_paragraph_open_citation = (opener_count > closer_count);
  }
}


string Checks_French::left_guillemet ()
{
  return "«";
}


string Checks_French::right_guillemet ()
{
  return "»";
}
