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


#ifndef INCLUDED_EDITOR_EXPORT_H
#define INCLUDED_EDITOR_EXPORT_H


#include <config/libraries.h>
#include <database/styles.h>
#include <pugixml/pugixml.hpp>


using namespace pugi;


class Editor_Html2Usfm
{
public:
  void load (string html);
  void stylesheet (string stylesheet);
  void quill ();
  void run ();
  string get ();
private:
  xml_document document; // DOMDocument holding the html.
  map <string, Database_Styles_Item> styles; // Style information.
  vector <string> output; // Output USFM.
  string currentLine; // Growing current USFM line.
  bool mono; // Monospace font.
  set <string> suppressEndMarkers; // Markers which should not have endmarkers, e.g. \v does not have \v*
  set <string> noteOpeners;
  vector <string> characterStyles; // Active character styles.
  bool processingNote = false; // Note processing flag.
  void preprocess ();
  void flushLine ();
  void postprocess ();
  void process ();
  void processNode (xml_node node);
  void openElementNode (xml_node node);
  void closeElementNode (xml_node node);
  void openInline (string className);
  void processNoteCitation (xml_node node);
  string cleanUSFM (string usfm);
  xml_node get_note_pointer (xml_node node, string id);
  bool quill_enabled = false;
  string update_quill_class (string classname);
};


string editor_export_verse (string stylesheet, string html);
string editor_export_verse_quill (string stylesheet, string html);


#endif
