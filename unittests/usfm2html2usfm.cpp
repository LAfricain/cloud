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


#include <unittests/usfm2html2usfm.h>
#include <unittests/utilities.h>
#include <editor/html2usfm.h>
#include <editor/usfm2html.h>
#include <styles/logic.h>
#include <filter/string.h>
#include <filter/url.h>


void test_usfm2html2usfm ()
{
  trace_unit_tests (__func__);
  refresh_sandbox (true);
  // One unknown opening marker.
  {
    string standard_usfm = "\\abc";
    {
      // DOM-based editor.
      string standard_html = "<p class=\"mono\"><span>\\abc </span></p>";

      Editor_Usfm2Html editor_usfm2html;
      editor_usfm2html.load (standard_usfm);
      editor_usfm2html.stylesheet (styles_logic_standard_sheet ());
      editor_usfm2html.run ();
      string html = editor_usfm2html.get ();
      evaluate (__LINE__, __func__, standard_html, filter_string_trim (html));
      
      Editor_Html2Usfm editor_html2usfm;
      editor_html2usfm.load (html);
      editor_html2usfm.stylesheet (styles_logic_standard_sheet ());
      editor_html2usfm.run ();
      string usfm = editor_html2usfm.get ();
      evaluate (__LINE__, __func__, standard_usfm, filter_string_trim (usfm));
    }
    {
      // Quill-based editor.
      string standard_html = "<p class=\"b-mono\"><span>\\abc </span></p>";

      Editor_Usfm2Html editor_usfm2html;
      editor_usfm2html.load (standard_usfm);
      editor_usfm2html.stylesheet (styles_logic_standard_sheet ());
      editor_usfm2html.quill ();
      editor_usfm2html.run ();
      string html = editor_usfm2html.get ();
      evaluate (__LINE__, __func__, standard_html, filter_string_trim (html));
      
      Editor_Html2Usfm editor_html2usfm;
      editor_html2usfm.load (html);
      editor_html2usfm.stylesheet (styles_logic_standard_sheet ());
      editor_html2usfm.quill ();
      editor_html2usfm.run ();
      string usfm = editor_html2usfm.get ();
      evaluate (__LINE__, __func__, standard_usfm, filter_string_trim (usfm));
    }
  }
  // Two unknown opening markers.
  {
    string standard_usfm =
    "\\abc\n"
    "\\abc";
    {
      // DOM-based editor.
      string standard_html =
      "<p class=\"mono\"><span>\\abc </span></p>"
      "<p class=\"mono\"><span>\\abc </span></p>";
      Editor_Usfm2Html editor_usfm2html;
      editor_usfm2html.load (standard_usfm);
      editor_usfm2html.stylesheet (styles_logic_standard_sheet ());
      editor_usfm2html.run ();
      string html = editor_usfm2html.get ();
      evaluate (__LINE__, __func__, standard_html, html);
      
      Editor_Html2Usfm editor_html2usfm;
      editor_html2usfm.load (html);
      editor_html2usfm.stylesheet (styles_logic_standard_sheet ());
      editor_html2usfm.run ();
      string usfm = editor_html2usfm.get ();
      evaluate (__LINE__, __func__, standard_usfm, usfm);
    }
    {
      // Quill-based editor.
      string standard_html =
      "<p class=\"b-mono\"><span>\\abc </span></p>"
      "<p class=\"b-mono\"><span>\\abc </span></p>";
      Editor_Usfm2Html editor_usfm2html;
      editor_usfm2html.load (standard_usfm);
      editor_usfm2html.stylesheet (styles_logic_standard_sheet ());
      editor_usfm2html.quill ();
      editor_usfm2html.run ();
      string html = editor_usfm2html.get ();
      evaluate (__LINE__, __func__, standard_html, html);
      
      Editor_Html2Usfm editor_html2usfm;
      editor_html2usfm.load (html);
      editor_html2usfm.stylesheet (styles_logic_standard_sheet ());
      editor_html2usfm.quill ();
      editor_html2usfm.run ();
      string usfm = editor_html2usfm.get ();
      evaluate (__LINE__, __func__, standard_usfm, usfm);
    }
  }
  // One unknown closing marker.
  {
    string standard_usfm = "\\abc text\\abc*.";
    {
      // DOM-based editor.
      string standard_html = "<p class=\"mono\"><span>\\abc </span><span>text</span><span>\\abc*</span><span>.</span></p>";
      Editor_Usfm2Html editor_usfm2html;
      editor_usfm2html.load (standard_usfm);
      editor_usfm2html.stylesheet (styles_logic_standard_sheet ());
      editor_usfm2html.run ();
      string html = editor_usfm2html.get ();
      evaluate (__LINE__, __func__, standard_html, html);
      
      Editor_Html2Usfm editor_html2usfm;
      editor_html2usfm.load (html);
      editor_html2usfm.stylesheet (styles_logic_standard_sheet ());
      editor_html2usfm.run ();
      string usfm = editor_html2usfm.get ();
      evaluate (__LINE__, __func__, standard_usfm, usfm);
    }
    {
      // Quill-based editor.
      string standard_html = "<p class=\"b-mono\"><span>\\abc </span><span>text</span><span>\\abc*</span><span>.</span></p>";
      Editor_Usfm2Html editor_usfm2html;
      editor_usfm2html.load (standard_usfm);
      editor_usfm2html.stylesheet (styles_logic_standard_sheet ());
      editor_usfm2html.quill ();
      editor_usfm2html.run ();
      string html = editor_usfm2html.get ();
      evaluate (__LINE__, __func__, standard_html, html);
      
      Editor_Html2Usfm editor_html2usfm;
      editor_html2usfm.load (html);
      editor_html2usfm.stylesheet (styles_logic_standard_sheet ());
      editor_html2usfm.quill ();
      editor_html2usfm.run ();
      string usfm = editor_html2usfm.get ();
      evaluate (__LINE__, __func__, standard_usfm, usfm);
    }
  }
  // Two unknown closing markers.
  {
    string standard_usfm =
    "\\abc text\\abc*.\n"
    "\\abc text\\abc*.";
    {
      // DOM-based editor.
      string standard_html =
      "<p class=\"mono\"><span>\\abc </span><span>text</span><span>\\abc*</span><span>.</span></p>"
      "<p class=\"mono\"><span>\\abc </span><span>text</span><span>\\abc*</span><span>.</span></p>";
      Editor_Usfm2Html editor_usfm2html;
      editor_usfm2html.load (standard_usfm);
      editor_usfm2html.stylesheet (styles_logic_standard_sheet ());
      editor_usfm2html.run ();
      string html = editor_usfm2html.get ();
      evaluate (__LINE__, __func__, standard_html, html);
      
      Editor_Html2Usfm editor_html2usfm;
      editor_html2usfm.load (html);
      editor_html2usfm.stylesheet (styles_logic_standard_sheet ());
      editor_html2usfm.run ();
      string usfm = editor_html2usfm.get ();
      evaluate (__LINE__, __func__, standard_usfm, usfm);
    }
    {
      // Quill-based editor.
      string standard_html =
      "<p class=\"b-mono\"><span>\\abc </span><span>text</span><span>\\abc*</span><span>.</span></p>"
      "<p class=\"b-mono\"><span>\\abc </span><span>text</span><span>\\abc*</span><span>.</span></p>";
      Editor_Usfm2Html editor_usfm2html;
      editor_usfm2html.load (standard_usfm);
      editor_usfm2html.stylesheet (styles_logic_standard_sheet ());
      editor_usfm2html.quill ();
      editor_usfm2html.run ();
      string html = editor_usfm2html.get ();
      evaluate (__LINE__, __func__, standard_html, html);
      
      Editor_Html2Usfm editor_html2usfm;
      editor_html2usfm.load (html);
      editor_html2usfm.stylesheet (styles_logic_standard_sheet ());
      editor_html2usfm.quill ();
      editor_html2usfm.run ();
      string usfm = editor_html2usfm.get ();
      evaluate (__LINE__, __func__, standard_usfm, usfm);
    }
  }
  // Identifiers.
  {
    string standard_usfm =
    "\\id GEN\n"
    "\\h Header\n"
    "\\toc1 The Book of Genesis\n"
    "\\cl Chapter\n"
    "\\cp ②\n"
    "\\cp Ⅰ";
    {
      // DOM-based editor.
      string standard_html =
      "<p class=\"mono\"><span>\\id </span><span>GEN</span></p>"
      "<p class=\"mono\"><span>\\h </span><span>Header</span></p>"
      "<p class=\"mono\"><span>\\toc1 </span><span>The Book of Genesis</span></p>"
      "<p class=\"mono\"><span>\\cl </span><span>Chapter</span></p>"
      "<p class=\"mono\"><span>\\cp </span><span>②</span></p>"
      "<p class=\"mono\"><span>\\cp </span><span>Ⅰ</span></p>";
      Editor_Usfm2Html editor_usfm2html;
      editor_usfm2html.load (standard_usfm);
      editor_usfm2html.stylesheet (styles_logic_standard_sheet ());
      editor_usfm2html.run ();
      string html = editor_usfm2html.get ();
      evaluate (__LINE__, __func__, standard_html, html);
      
      Editor_Html2Usfm editor_html2usfm;
      editor_html2usfm.load (html);
      editor_html2usfm.stylesheet (styles_logic_standard_sheet ());
      editor_html2usfm.run ();
      string usfm = editor_html2usfm.get ();
      evaluate (__LINE__, __func__, standard_usfm, usfm);
    }
    {
      // Quill-based editor.
      string standard_html =
      "<p class=\"b-mono\"><span>\\id </span><span>GEN</span></p>"
      "<p class=\"b-mono\"><span>\\h </span><span>Header</span></p>"
      "<p class=\"b-mono\"><span>\\toc1 </span><span>The Book of Genesis</span></p>"
      "<p class=\"b-mono\"><span>\\cl </span><span>Chapter</span></p>"
      "<p class=\"b-mono\"><span>\\cp </span><span>②</span></p>"
      "<p class=\"b-mono\"><span>\\cp </span><span>Ⅰ</span></p>";
      Editor_Usfm2Html editor_usfm2html;
      editor_usfm2html.load (standard_usfm);
      editor_usfm2html.stylesheet (styles_logic_standard_sheet ());
      editor_usfm2html.quill ();
      editor_usfm2html.run ();
      string html = editor_usfm2html.get ();
      evaluate (__LINE__, __func__, standard_html, html);
      
      Editor_Html2Usfm editor_html2usfm;
      editor_html2usfm.load (html);
      editor_html2usfm.stylesheet (styles_logic_standard_sheet ());
      editor_html2usfm.quill ();
      editor_html2usfm.run ();
      string usfm = editor_html2usfm.get ();
      evaluate (__LINE__, __func__, standard_usfm, usfm);
    }
  }
  // One paragraph.
  {
    string standard_usfm = "\\p Paragraph text.";
    {
      // DOM-based editor.
      string standard_html = "<p class=\"p\"><span>Paragraph text.</span></p>";
      Editor_Usfm2Html editor_usfm2html;
      editor_usfm2html.load (standard_usfm);
      editor_usfm2html.stylesheet (styles_logic_standard_sheet ());
      editor_usfm2html.run ();
      string html = editor_usfm2html.get ();
      evaluate (__LINE__, __func__, standard_html, html);
      
      Editor_Html2Usfm editor_html2usfm;
      editor_html2usfm.load (html);
      editor_html2usfm.stylesheet (styles_logic_standard_sheet ());
      editor_html2usfm.run ();
      string usfm = editor_html2usfm.get ();
      evaluate (__LINE__, __func__, standard_usfm, usfm);
    }
    {
      // Quill-based editor.
      string standard_html = "<p class=\"b-p\"><span>Paragraph text.</span></p>";
      Editor_Usfm2Html editor_usfm2html;
      editor_usfm2html.load (standard_usfm);
      editor_usfm2html.stylesheet (styles_logic_standard_sheet ());
      editor_usfm2html.quill ();
      editor_usfm2html.run ();
      string html = editor_usfm2html.get ();
      evaluate (__LINE__, __func__, standard_html, html);
      
      Editor_Html2Usfm editor_html2usfm;
      editor_html2usfm.load (html);
      editor_html2usfm.stylesheet (styles_logic_standard_sheet ());
      editor_html2usfm.quill ();
      editor_html2usfm.run ();
      string usfm = editor_html2usfm.get ();
      evaluate (__LINE__, __func__, standard_usfm, usfm);
    }
  }
  // Two paragraphs.
  {
    string standard_usfm =
    "\\p Paragraph text.\n"
    "\\p Paragraph txt.";
    {
      // DOM-based editor.
      string standard_html =
      "<p class=\"p\"><span>Paragraph text.</span></p>"
      "<p class=\"p\"><span>Paragraph txt.</span></p>";
      Editor_Usfm2Html editor_usfm2html;
      editor_usfm2html.load (standard_usfm);
      editor_usfm2html.stylesheet (styles_logic_standard_sheet ());
      editor_usfm2html.run ();
      string html = editor_usfm2html.get ();
      evaluate (__LINE__, __func__, standard_html, html);
      
      Editor_Html2Usfm editor_html2usfm;
      editor_html2usfm.load (html);
      editor_html2usfm.stylesheet (styles_logic_standard_sheet ());
      editor_html2usfm.run ();
      string usfm = editor_html2usfm.get ();
      evaluate (__LINE__, __func__, standard_usfm, usfm);
    }
    {
      // Quill-based editor.
      string standard_html =
      "<p class=\"b-p\"><span>Paragraph text.</span></p>"
      "<p class=\"b-p\"><span>Paragraph txt.</span></p>";
      Editor_Usfm2Html editor_usfm2html;
      editor_usfm2html.load (standard_usfm);
      editor_usfm2html.stylesheet (styles_logic_standard_sheet ());
      editor_usfm2html.quill ();
      editor_usfm2html.run ();
      string html = editor_usfm2html.get ();
      evaluate (__LINE__, __func__, standard_html, html);
      
      Editor_Html2Usfm editor_html2usfm;
      editor_html2usfm.load (html);
      editor_html2usfm.stylesheet (styles_logic_standard_sheet ());
      editor_html2usfm.quill ();
      editor_html2usfm.run ();
      string usfm = editor_html2usfm.get ();
      evaluate (__LINE__, __func__, standard_usfm, usfm);
    }
  }
  // Inline text
  {
    string standard_usfm = "\\p Paragraph text plus \\add added\\add* text.";
    {
      // DOM-based editor.
      string standard_html = "<p class=\"p\"><span>Paragraph text plus </span><span class=\"add\">added</span><span> text.</span></p>";
      Editor_Usfm2Html editor_usfm2html;
      editor_usfm2html.load (standard_usfm);
      editor_usfm2html.stylesheet (styles_logic_standard_sheet ());
      editor_usfm2html.run ();
      string html = editor_usfm2html.get ();
      evaluate (__LINE__, __func__, standard_html, html);
      
      Editor_Html2Usfm editor_html2usfm;
      editor_html2usfm.load (html);
      editor_html2usfm.stylesheet (styles_logic_standard_sheet ());
      editor_html2usfm.run ();
      string usfm = editor_html2usfm.get ();
      evaluate (__LINE__, __func__, standard_usfm, usfm);
    }
    {
      // Quill-based editor.
      string standard_html = "<p class=\"b-p\"><span>Paragraph text plus </span><span class=\"i-add\">added</span><span> text.</span></p>";
      Editor_Usfm2Html editor_usfm2html;
      editor_usfm2html.load (standard_usfm);
      editor_usfm2html.stylesheet (styles_logic_standard_sheet ());
      editor_usfm2html.quill ();
      editor_usfm2html.run ();
      string html = editor_usfm2html.get ();
      evaluate (__LINE__, __func__, standard_html, html);
      
      Editor_Html2Usfm editor_html2usfm;
      editor_html2usfm.load (html);
      editor_html2usfm.stylesheet (styles_logic_standard_sheet ());
      editor_html2usfm.quill ();
      editor_html2usfm.run ();
      string usfm = editor_html2usfm.get ();
      evaluate (__LINE__, __func__, standard_usfm, usfm);
    }
  }
  // Inline texts
  {
    string standard_usfm = "\\p Paragraph text plus \\add added\\add* text plus \\add added\\add* text.";
    {
      // DOM-based editor.
      string standard_html = "<p class=\"p\"><span>Paragraph text plus </span><span class=\"add\">added</span><span> text plus </span><span class=\"add\">added</span><span> text.</span></p>";
      Editor_Usfm2Html editor_usfm2html;
      editor_usfm2html.load (standard_usfm);
      editor_usfm2html.stylesheet (styles_logic_standard_sheet ());
      editor_usfm2html.run ();
      string html = editor_usfm2html.get ();
      evaluate (__LINE__, __func__, standard_html, html);
      
      Editor_Html2Usfm editor_html2usfm;
      editor_html2usfm.load (html);
      editor_html2usfm.stylesheet (styles_logic_standard_sheet ());
      editor_html2usfm.run ();
      string usfm = editor_html2usfm.get ();
      evaluate (__LINE__, __func__, standard_usfm, usfm);
    }
    {
      // Quill-based editor.
      string standard_html = "<p class=\"b-p\"><span>Paragraph text plus </span><span class=\"i-add\">added</span><span> text plus </span><span class=\"i-add\">added</span><span> text.</span></p>";
      Editor_Usfm2Html editor_usfm2html;
      editor_usfm2html.load (standard_usfm);
      editor_usfm2html.stylesheet (styles_logic_standard_sheet ());
      editor_usfm2html.quill ();
      editor_usfm2html.run ();
      string html = editor_usfm2html.get ();
      evaluate (__LINE__, __func__, standard_html, html);
      
      Editor_Html2Usfm editor_html2usfm;
      editor_html2usfm.load (html);
      editor_html2usfm.stylesheet (styles_logic_standard_sheet ());
      editor_html2usfm.quill ();
      editor_html2usfm.run ();
      string usfm = editor_html2usfm.get ();
      evaluate (__LINE__, __func__, standard_usfm, usfm);
    }
  }
  // Chapter.
  {
    string standard_usfm =
    "\\c 1\n"
    "\\p Paragraph.";
    {
      // DOM-based editor.
      string standard_html =
      "<p class=\"c\"><span>1</span></p>"
      "<p class=\"p\"><span>Paragraph.</span></p>";
      Editor_Usfm2Html editor_usfm2html;
      editor_usfm2html.load (standard_usfm);
      editor_usfm2html.stylesheet (styles_logic_standard_sheet ());
      editor_usfm2html.run ();
      string html = editor_usfm2html.get ();
      evaluate (__LINE__, __func__, standard_html, html);
      
      Editor_Html2Usfm editor_html2usfm;
      editor_html2usfm.load (html);
      editor_html2usfm.stylesheet (styles_logic_standard_sheet ());
      editor_html2usfm.run ();
      string usfm = editor_html2usfm.get ();
      evaluate (__LINE__, __func__, standard_usfm, usfm);
    }
    {
      // Quill-based editor.
      string standard_html =
      "<p class=\"b-c\"><span>1</span></p>"
      "<p class=\"b-p\"><span>Paragraph.</span></p>";
      Editor_Usfm2Html editor_usfm2html;
      editor_usfm2html.load (standard_usfm);
      editor_usfm2html.stylesheet (styles_logic_standard_sheet ());
      editor_usfm2html.quill ();
      editor_usfm2html.run ();
      string html = editor_usfm2html.get ();
      evaluate (__LINE__, __func__, standard_html, html);
      
      Editor_Html2Usfm editor_html2usfm;
      editor_html2usfm.load (html);
      editor_html2usfm.stylesheet (styles_logic_standard_sheet ());
      editor_html2usfm.quill ();
      editor_html2usfm.run ();
      string usfm = editor_html2usfm.get ();
      evaluate (__LINE__, __func__, standard_usfm, usfm);
    }
  }
  // Verses.
  {
    string standard_usfm =
    "\\p\n"
    "\\v 1 One.\n"
    "\\v 2 Two.";
    {
      // DOM-based editor.
      string standard_html =
      "<p class=\"p\"><span class=\"v\">1</span><span> </span><span>One.</span><span> </span><span class=\"v\">2</span><span> </span><span>Two.</span></p>";
      Editor_Usfm2Html editor_usfm2html;
      editor_usfm2html.load (standard_usfm);
      editor_usfm2html.stylesheet (styles_logic_standard_sheet ());
      editor_usfm2html.run ();
      string html = editor_usfm2html.get ();
      evaluate (__LINE__, __func__, standard_html, html);
      
      Editor_Html2Usfm editor_html2usfm;
      editor_html2usfm.load (html);
      editor_html2usfm.stylesheet (styles_logic_standard_sheet ());
      editor_html2usfm.run ();
      string usfm = editor_html2usfm.get ();
      evaluate (__LINE__, __func__, standard_usfm, usfm);
    }
    {
      // Quill-based editor.
      string standard_html =
      "<p class=\"b-p\"><span class=\"i-v\">1</span><span> </span><span>One.</span><span> </span><span class=\"i-v\">2</span><span> </span><span>Two.</span></p>";
      Editor_Usfm2Html editor_usfm2html;
      editor_usfm2html.load (standard_usfm);
      editor_usfm2html.stylesheet (styles_logic_standard_sheet ());
      editor_usfm2html.quill ();
      editor_usfm2html.run ();
      string html = editor_usfm2html.get ();
      evaluate (__LINE__, __func__, standard_html, html);
      
      Editor_Html2Usfm editor_html2usfm;
      editor_html2usfm.load (html);
      editor_html2usfm.stylesheet (styles_logic_standard_sheet ());
      editor_html2usfm.quill ();
      editor_html2usfm.run ();
      string usfm = editor_html2usfm.get ();
      evaluate (__LINE__, __func__, standard_usfm, usfm);
    }
  }
  // Peripherals.
  {
    string standard_usfm =
    "\\periph Title Page\n"
    "\\periph Publication Data";
    {
      // DOM-based editor.
      string standard_html =
      "<p class=\"mono\"><span>\\periph </span><span>Title Page</span></p>"
      "<p class=\"mono\"><span>\\periph </span><span>Publication Data</span></p>";
      Editor_Usfm2Html editor_usfm2html;
      editor_usfm2html.load (standard_usfm);
      editor_usfm2html.stylesheet (styles_logic_standard_sheet ());
      editor_usfm2html.run ();
      string html = editor_usfm2html.get ();
      evaluate (__LINE__, __func__, standard_html, html);
      
      Editor_Html2Usfm editor_html2usfm;
      editor_html2usfm.load (html);
      editor_html2usfm.stylesheet (styles_logic_standard_sheet ());
      editor_html2usfm.run ();
      string usfm = editor_html2usfm.get ();
      evaluate (__LINE__, __func__, standard_usfm, usfm);
    }
    {
      // Quill-based editor.
      string standard_html =
      "<p class=\"b-mono\"><span>\\periph </span><span>Title Page</span></p>"
      "<p class=\"b-mono\"><span>\\periph </span><span>Publication Data</span></p>";
      Editor_Usfm2Html editor_usfm2html;
      editor_usfm2html.load (standard_usfm);
      editor_usfm2html.stylesheet (styles_logic_standard_sheet ());
      editor_usfm2html.quill ();
      editor_usfm2html.run ();
      string html = editor_usfm2html.get ();
      evaluate (__LINE__, __func__, standard_html, html);
      
      Editor_Html2Usfm editor_html2usfm;
      editor_html2usfm.load (html);
      editor_html2usfm.stylesheet (styles_logic_standard_sheet ());
      editor_html2usfm.quill ();
      editor_html2usfm.run ();
      string usfm = editor_html2usfm.get ();
      evaluate (__LINE__, __func__, standard_usfm, usfm);
    }
  }
  // Picture.
  {
    string standard_usfm =
    "\\p Text\n"
    "\\fig DESC|FILE|SIZE|LOC|COPY|CAP|REF\\fig*\n"
    "\\p Text";
    {
      // DOM-based editor.
      string standard_html =
      "<p class=\"p\"><span>Text</span></p>"
      "<p class=\"mono\"><span>\\fig </span><span>DESC|FILE|SIZE|LOC|COPY|CAP|REF</span><span>\\fig*</span></p>"
      "<p class=\"p\"><span>Text</span></p>";
      Editor_Usfm2Html editor_usfm2html;
      editor_usfm2html.load (standard_usfm);
      editor_usfm2html.stylesheet (styles_logic_standard_sheet ());
      editor_usfm2html.run ();
      string html = editor_usfm2html.get ();
      evaluate (__LINE__, __func__, standard_html, html);
      
      Editor_Html2Usfm editor_html2usfm;
      editor_html2usfm.load (html);
      editor_html2usfm.stylesheet (styles_logic_standard_sheet ());
      editor_html2usfm.run ();
      string usfm = editor_html2usfm.get ();
      evaluate (__LINE__, __func__, standard_usfm, usfm);
    }
    {
      // Quill-based editor.
      string standard_html =
      "<p class=\"b-p\"><span>Text</span></p>"
      "<p class=\"b-mono\"><span>\\fig </span><span>DESC|FILE|SIZE|LOC|COPY|CAP|REF</span><span>\\fig*</span></p>"
      "<p class=\"b-p\"><span>Text</span></p>";
      Editor_Usfm2Html editor_usfm2html;
      editor_usfm2html.load (standard_usfm);
      editor_usfm2html.stylesheet (styles_logic_standard_sheet ());
      editor_usfm2html.quill ();
      editor_usfm2html.run ();
      string html = editor_usfm2html.get ();
      evaluate (__LINE__, __func__, standard_html, html);
      
      Editor_Html2Usfm editor_html2usfm;
      editor_html2usfm.load (html);
      editor_html2usfm.stylesheet (styles_logic_standard_sheet ());
      editor_html2usfm.quill ();
      editor_html2usfm.run ();
      string usfm = editor_html2usfm.get ();
      evaluate (__LINE__, __func__, standard_usfm, usfm);
    }
  }
  // Table.
  {
    string standard_usfm =
    "\\tr \\th1 Tribe \\th2 Leader \\thr3 Number\n"
    "\\tr \\tc1 Reuben \\tc2 Elizur son of Shedeur \\tcr3 46500\n"
    "\\tr \\tc1 Simeon \\tc2 Shelumiel son of Zurishaddai \\tcr3 59300\n"
    "\\tr \\tc1 Gad \\tc2 Eliasaph son of Reuel \\tcr3 45650\n"
    "\\tr \\tc1 \\tcr2 Total: \\tcr3 151450";
    {
      // DOM-based editor.
      string standard_html =
      "<p class=\"mono\"><span>\\tr </span><span class=\"th1\">Tribe </span><span class=\"th2\">Leader </span><span class=\"thr3\">Number</span></p>"
      "<p class=\"mono\"><span>\\tr </span><span class=\"tc1\">Reuben </span><span class=\"tc2\">Elizur son of Shedeur </span><span class=\"tcr3\">46500</span></p>"
      "<p class=\"mono\"><span>\\tr </span><span class=\"tc1\">Simeon </span><span class=\"tc2\">Shelumiel son of Zurishaddai </span><span class=\"tcr3\">59300</span></p>"
      "<p class=\"mono\"><span>\\tr </span><span class=\"tc1\">Gad </span><span class=\"tc2\">Eliasaph son of Reuel </span><span class=\"tcr3\">45650</span></p>"
      "<p class=\"mono\"><span>\\tr </span><span class=\"tcr2\">Total: </span><span class=\"tcr3\">151450</span></p>";
      Editor_Usfm2Html editor_usfm2html;
      editor_usfm2html.load (standard_usfm);
      editor_usfm2html.stylesheet (styles_logic_standard_sheet ());
      editor_usfm2html.run ();
      string html = editor_usfm2html.get ();
      evaluate (__LINE__, __func__, standard_html, html);
      
      Editor_Html2Usfm editor_html2usfm;
      editor_html2usfm.load (html);
      editor_html2usfm.stylesheet (styles_logic_standard_sheet ());
      editor_html2usfm.run ();
      string usfm = editor_html2usfm.get ();
      string standard_usfm2 = filter_string_str_replace ("\\tc1 \\", "\\", standard_usfm);
      evaluate (__LINE__, __func__, standard_usfm2, usfm);
    }
    {
      // Quill-based editor.
      string standard_html =
      "<p class=\"b-mono\"><span>\\tr </span><span class=\"i-th1\">Tribe </span><span class=\"i-th2\">Leader </span><span class=\"i-thr3\">Number</span></p>"
      "<p class=\"b-mono\"><span>\\tr </span><span class=\"i-tc1\">Reuben </span><span class=\"i-tc2\">Elizur son of Shedeur </span><span class=\"i-tcr3\">46500</span></p>"
      "<p class=\"b-mono\"><span>\\tr </span><span class=\"i-tc1\">Simeon </span><span class=\"i-tc2\">Shelumiel son of Zurishaddai </span><span class=\"i-tcr3\">59300</span></p>"
      "<p class=\"b-mono\"><span>\\tr </span><span class=\"i-tc1\">Gad </span><span class=\"i-tc2\">Eliasaph son of Reuel </span><span class=\"i-tcr3\">45650</span></p>"
      "<p class=\"b-mono\"><span>\\tr </span><span class=\"i-tcr2\">Total: </span><span class=\"i-tcr3\">151450</span></p>";
      Editor_Usfm2Html editor_usfm2html;
      editor_usfm2html.load (standard_usfm);
      editor_usfm2html.stylesheet (styles_logic_standard_sheet ());
      editor_usfm2html.quill ();
      editor_usfm2html.run ();
      string html = editor_usfm2html.get ();
      evaluate (__LINE__, __func__, standard_html, html);
      
      Editor_Html2Usfm editor_html2usfm;
      editor_html2usfm.load (html);
      editor_html2usfm.stylesheet (styles_logic_standard_sheet ());
      editor_html2usfm.quill ();
      editor_html2usfm.run ();
      string usfm = editor_html2usfm.get ();
      string standard_usfm2 = filter_string_str_replace ("\\tc1 \\", "\\", standard_usfm);
      evaluate (__LINE__, __func__, standard_usfm2, usfm);
    }
  }
  // Word list entry.
  {
    string standard_usfm = "\\p A \\ndx index\\ndx* b \\wh Hebrew\\wh* c.";
    {
      // DOM-based editor.
      string standard_html =
      "<p class=\"p\"><span>A </span><span class=\"ndx\">index</span><span> b </span><span class=\"wh\">Hebrew</span><span> c.</span></p>";
      Editor_Usfm2Html editor_usfm2html;
      editor_usfm2html.load (standard_usfm);
      editor_usfm2html.stylesheet (styles_logic_standard_sheet ());
      editor_usfm2html.run ();
      string html = editor_usfm2html.get ();
      evaluate (__LINE__, __func__, standard_html, html);
      
      Editor_Html2Usfm editor_html2usfm;
      editor_html2usfm.load (html);
      editor_html2usfm.stylesheet (styles_logic_standard_sheet ());
      editor_html2usfm.run ();
      string usfm = editor_html2usfm.get ();
      evaluate (__LINE__, __func__, standard_usfm, usfm);
    }
    {
      // Quill-based editor.
      string standard_html =
      "<p class=\"b-p\"><span>A </span><span class=\"i-ndx\">index</span><span> b </span><span class=\"i-wh\">Hebrew</span><span> c.</span></p>";
      Editor_Usfm2Html editor_usfm2html;
      editor_usfm2html.load (standard_usfm);
      editor_usfm2html.stylesheet (styles_logic_standard_sheet ());
      editor_usfm2html.quill ();
      editor_usfm2html.run ();
      string html = editor_usfm2html.get ();
      evaluate (__LINE__, __func__, standard_html, html);
      
      Editor_Html2Usfm editor_html2usfm;
      editor_html2usfm.load (html);
      editor_html2usfm.stylesheet (styles_logic_standard_sheet ());
      editor_html2usfm.quill ();
      editor_html2usfm.run ();
      string usfm = editor_html2usfm.get ();
      evaluate (__LINE__, __func__, standard_usfm, usfm);
    }
  }
  // Crossreference.
  {
    string standard_usfm = "\\p The elder\\x + 2 Joh. 1.1\\x* to the beloved Gaius.";
    {
      // DOM-based editor.
      string standard_html =
      "<p class=\"p\"><span>The elder</span><a href=\"#note1\" id=\"citation1\" style=\"text-decoration:none; color: inherit;\" class=\"superscript\">1</a><span> to the beloved Gaius.</span></p>"
      "<div id=\"notes\">"
      "<hr />"
      "<p class=\"x\"><a href=\"#citation1\" id=\"note1\" style=\"text-decoration:none; color: inherit;\">1</a><span> </span><span>+ 2 Joh. 1.1</span></p>"
      "</div>";
      Editor_Usfm2Html editor_usfm2html;
      editor_usfm2html.load (standard_usfm);
      editor_usfm2html.stylesheet (styles_logic_standard_sheet ());
      editor_usfm2html.run ();
      string html = editor_usfm2html.get ();
      evaluate (__LINE__, __func__, standard_html, html);
      
      Editor_Html2Usfm editor_html2usfm;
      editor_html2usfm.load (html);
      editor_html2usfm.stylesheet (styles_logic_standard_sheet ());
      editor_html2usfm.run ();
      string usfm = editor_html2usfm.get ();
      evaluate (__LINE__, __func__, standard_usfm, usfm);
    }
    {
      // Quill-based editor.
      string standard_html =
      "<p class=\"b-p\"><span>The elder</span><span class=\"i-notecall1\">1</span><span> to the beloved Gaius.</span></p>"
      "<p class=\"b-notes\">"
      "<br />"
      "</p>"
      "<p class=\"b-x\"><span class=\"i-notebody1\">1</span><span> </span><span>+ 2 Joh. 1.1</span></p>";
      Editor_Usfm2Html editor_usfm2html;
      editor_usfm2html.load (standard_usfm);
      editor_usfm2html.stylesheet (styles_logic_standard_sheet ());
      editor_usfm2html.quill ();
      editor_usfm2html.run ();
      string html = editor_usfm2html.get ();
      evaluate (__LINE__, __func__, standard_html, html);
      
      Editor_Html2Usfm editor_html2usfm;
      editor_html2usfm.load (html);
      editor_html2usfm.stylesheet (styles_logic_standard_sheet ());
      editor_html2usfm.quill ();
      editor_html2usfm.run ();
      string usfm = editor_html2usfm.get ();
      evaluate (__LINE__, __func__, standard_usfm, usfm);
    }
  }
  // Crossreferences.
  {
    string standard_usfm =
    "\\p The elder\\x + 2 Joh. 1.1\\x* to the beloved Gaius.\n"
    "\\v 1 The elders\\x + 2 Joh. 2.2\\x* to the beloved.";
    {
      // DOM-based editor.
      string standard_html =
      "<p class=\"p\"><span>The elder</span><a href=\"#note1\" id=\"citation1\" style=\"text-decoration:none; color: inherit;\" class=\"superscript\">1</a><span> to the beloved Gaius.</span><span> </span><span class=\"v\">1</span><span> </span><span>The elders</span><a href=\"#note2\" id=\"citation2\" style=\"text-decoration:none; color: inherit;\" class=\"superscript\">2</a><span> to the beloved.</span></p>"
      "<div id=\"notes\">"
      "<hr />"
      "<p class=\"x\"><a href=\"#citation1\" id=\"note1\" style=\"text-decoration:none; color: inherit;\">1</a><span> </span><span>+ 2 Joh. 1.1</span></p>"
      "<p class=\"x\"><a href=\"#citation2\" id=\"note2\" style=\"text-decoration:none; color: inherit;\">2</a><span> </span><span>+ 2 Joh. 2.2</span></p>"
      "</div>";
      Editor_Usfm2Html editor_usfm2html;
      editor_usfm2html.load (standard_usfm);
      editor_usfm2html.stylesheet (styles_logic_standard_sheet ());
      editor_usfm2html.run ();
      string html = editor_usfm2html.get ();
      evaluate (__LINE__, __func__, standard_html, html);
      
      Editor_Html2Usfm editor_html2usfm;
      editor_html2usfm.load (html);
      editor_html2usfm.stylesheet (styles_logic_standard_sheet ());
      editor_html2usfm.run ();
      string usfm = editor_html2usfm.get ();
      evaluate (__LINE__, __func__, standard_usfm, usfm);
    }
    {
      // Quill-based editor.
      string standard_html =
      "<p class=\"b-p\"><span>The elder</span><span class=\"i-notecall1\">1</span><span> to the beloved Gaius.</span><span> </span><span class=\"i-v\">1</span><span> </span><span>The elders</span><span class=\"i-notecall2\">2</span><span> to the beloved.</span></p>"
      "<p class=\"b-notes\">"
      "<br />"
      "</p>"
      "<p class=\"b-x\"><span class=\"i-notebody1\">1</span><span> </span><span>+ 2 Joh. 1.1</span></p>"
      "<p class=\"b-x\"><span class=\"i-notebody2\">2</span><span> </span><span>+ 2 Joh. 2.2</span></p>";
      Editor_Usfm2Html editor_usfm2html;
      editor_usfm2html.load (standard_usfm);
      editor_usfm2html.stylesheet (styles_logic_standard_sheet ());
      editor_usfm2html.quill ();
      editor_usfm2html.run ();
      string html = editor_usfm2html.get ();
      evaluate (__LINE__, __func__, standard_html, html);
      
      Editor_Html2Usfm editor_html2usfm;
      editor_html2usfm.load (html);
      editor_html2usfm.stylesheet (styles_logic_standard_sheet ());
      editor_html2usfm.quill ();
      editor_html2usfm.run ();
      string usfm = editor_html2usfm.get ();
      evaluate (__LINE__, __func__, standard_usfm, usfm);
    }
  }
  // Footnote.
  {
    string standard_usfm =
    "\\p The earth brought forth\\f + \\fk brought: \\fl Heb. \\fq explanation.\\f*.";
    {
      // DOM-based editor.
      string standard_html =
      "<p class=\"p\"><span>The earth brought forth</span><a href=\"#note1\" id=\"citation1\" style=\"text-decoration:none; color: inherit;\" class=\"superscript\">1</a><span>.</span></p>"
      "<div id=\"notes\">"
      "<hr />"
      "<p class=\"f\"><a href=\"#citation1\" id=\"note1\" style=\"text-decoration:none; color: inherit;\">1</a><span> </span><span>+ </span><span class=\"fk\">brought: </span><span class=\"fl\">Heb. </span><span class=\"fq\">explanation.</span></p>"
      "</div>";
      
      Editor_Usfm2Html editor_usfm2html;
      editor_usfm2html.load (standard_usfm);
      editor_usfm2html.stylesheet (styles_logic_standard_sheet ());
      editor_usfm2html.run ();
      string html = editor_usfm2html.get ();
      evaluate (__LINE__, __func__, standard_html, html);
      
      Editor_Html2Usfm editor_html2usfm;
      editor_html2usfm.load (html);
      editor_html2usfm.stylesheet (styles_logic_standard_sheet ());
      editor_html2usfm.run ();
      string usfm = editor_html2usfm.get ();
      evaluate (__LINE__, __func__, standard_usfm, usfm);
    }
    {
      // Quill-based editor.
      string standard_html =
      "<p class=\"b-p\"><span>The earth brought forth</span><span class=\"i-notecall1\">1</span><span>.</span></p>"
      "<p class=\"b-notes\">"
      "<br />"
      "</p>"
      "<p class=\"b-f\"><span class=\"i-notebody1\">1</span><span> </span><span>+ </span><span class=\"i-fk\">brought: </span><span class=\"i-fl\">Heb. </span><span class=\"i-fq\">explanation.</span></p>";
      Editor_Usfm2Html editor_usfm2html;
      editor_usfm2html.load (standard_usfm);
      editor_usfm2html.stylesheet (styles_logic_standard_sheet ());
      editor_usfm2html.quill ();
      editor_usfm2html.run ();
      string html = editor_usfm2html.get ();
      evaluate (__LINE__, __func__, standard_html, html);
      
      Editor_Html2Usfm editor_html2usfm;
      editor_html2usfm.load (html);
      editor_html2usfm.stylesheet (styles_logic_standard_sheet ());
      editor_html2usfm.quill ();
      editor_html2usfm.run ();
      string usfm = editor_html2usfm.get ();
      evaluate (__LINE__, __func__, standard_usfm, usfm);
    }
  }
  // Cycling the note caller.
  {
    string standard_usfm =
    "\\p Text\\f + note\\f*.\n"
    "\\p Text\\fe + note\\fe*.\n"
    "\\p Text\\x + note\\x*.\n"
    "\\p Text\\f + note\\f*.\n"
    "\\p Text\\fe + note\\fe*.\n"
    "\\p Text\\x + note\\x*.\n"
    "\\p Text\\f + note\\f*.\n"
    "\\p Text\\fe + note\\fe*.\n"
    "\\p Text\\x + note\\x*.\n"
    "\\p Text\\f + note\\f*.\n"
    "\\p Text\\fe + note\\fe*.\n"
    "\\p Text\\x + note\\x*.\n"
    "\\p Text\\f + note\\f*.\n"
    "\\p Text\\fe + note\\fe*.\n"
    "\\p Text\\x + note\\x*.\n"
    "\\p Text\\f + note\\f*.\n"
    "\\p Text\\fe + note\\fe*.\n"
    "\\p Text\\x + note\\x*.\n"
    "\\p Text\\f + note\\f*.\n"
    "\\p Text\\fe + note\\fe*.\n"
    "\\p Text\\x + note\\x*.";
    {
      // DOM-based editor.
      string standard_html =
      "<p class=\"p\"><span>Text</span><a href=\"#note1\" id=\"citation1\" style=\"text-decoration:none; color: inherit;\" class=\"superscript\">1</a><span>.</span></p>"
      "<p class=\"p\"><span>Text</span><a href=\"#note2\" id=\"citation2\" style=\"text-decoration:none; color: inherit;\" class=\"superscript\">2</a><span>.</span></p>"
      "<p class=\"p\"><span>Text</span><a href=\"#note3\" id=\"citation3\" style=\"text-decoration:none; color: inherit;\" class=\"superscript\">3</a><span>.</span></p>"
      "<p class=\"p\"><span>Text</span><a href=\"#note4\" id=\"citation4\" style=\"text-decoration:none; color: inherit;\" class=\"superscript\">4</a><span>.</span></p>"
      "<p class=\"p\"><span>Text</span><a href=\"#note5\" id=\"citation5\" style=\"text-decoration:none; color: inherit;\" class=\"superscript\">5</a><span>.</span></p>"
      "<p class=\"p\"><span>Text</span><a href=\"#note6\" id=\"citation6\" style=\"text-decoration:none; color: inherit;\" class=\"superscript\">6</a><span>.</span></p>"
      "<p class=\"p\"><span>Text</span><a href=\"#note7\" id=\"citation7\" style=\"text-decoration:none; color: inherit;\" class=\"superscript\">7</a><span>.</span></p>"
      "<p class=\"p\"><span>Text</span><a href=\"#note8\" id=\"citation8\" style=\"text-decoration:none; color: inherit;\" class=\"superscript\">8</a><span>.</span></p>"
      "<p class=\"p\"><span>Text</span><a href=\"#note9\" id=\"citation9\" style=\"text-decoration:none; color: inherit;\" class=\"superscript\">9</a><span>.</span></p>"
      "<p class=\"p\"><span>Text</span><a href=\"#note10\" id=\"citation10\" style=\"text-decoration:none; color: inherit;\" class=\"superscript\">1</a><span>.</span></p>"
      "<p class=\"p\"><span>Text</span><a href=\"#note11\" id=\"citation11\" style=\"text-decoration:none; color: inherit;\" class=\"superscript\">2</a><span>.</span></p>"
      "<p class=\"p\"><span>Text</span><a href=\"#note12\" id=\"citation12\" style=\"text-decoration:none; color: inherit;\" class=\"superscript\">3</a><span>.</span></p>"
      "<p class=\"p\"><span>Text</span><a href=\"#note13\" id=\"citation13\" style=\"text-decoration:none; color: inherit;\" class=\"superscript\">4</a><span>.</span></p>"
      "<p class=\"p\"><span>Text</span><a href=\"#note14\" id=\"citation14\" style=\"text-decoration:none; color: inherit;\" class=\"superscript\">5</a><span>.</span></p>"
      "<p class=\"p\"><span>Text</span><a href=\"#note15\" id=\"citation15\" style=\"text-decoration:none; color: inherit;\" class=\"superscript\">6</a><span>.</span></p>"
      "<p class=\"p\"><span>Text</span><a href=\"#note16\" id=\"citation16\" style=\"text-decoration:none; color: inherit;\" class=\"superscript\">7</a><span>.</span></p>"
      "<p class=\"p\"><span>Text</span><a href=\"#note17\" id=\"citation17\" style=\"text-decoration:none; color: inherit;\" class=\"superscript\">8</a><span>.</span></p>"
      "<p class=\"p\"><span>Text</span><a href=\"#note18\" id=\"citation18\" style=\"text-decoration:none; color: inherit;\" class=\"superscript\">9</a><span>.</span></p>"
      "<p class=\"p\"><span>Text</span><a href=\"#note19\" id=\"citation19\" style=\"text-decoration:none; color: inherit;\" class=\"superscript\">1</a><span>.</span></p>"
      "<p class=\"p\"><span>Text</span><a href=\"#note20\" id=\"citation20\" style=\"text-decoration:none; color: inherit;\" class=\"superscript\">2</a><span>.</span></p>"
      "<p class=\"p\"><span>Text</span><a href=\"#note21\" id=\"citation21\" style=\"text-decoration:none; color: inherit;\" class=\"superscript\">3</a><span>.</span></p>"
      "<div id=\"notes\">"
      "<hr />"
      "<p class=\"f\"><a href=\"#citation1\" id=\"note1\" style=\"text-decoration:none; color: inherit;\">1</a><span> </span><span>+ note</span></p>"
      "<p class=\"fe\"><a href=\"#citation2\" id=\"note2\" style=\"text-decoration:none; color: inherit;\">2</a><span> </span><span>+ note</span></p>"
      "<p class=\"x\"><a href=\"#citation3\" id=\"note3\" style=\"text-decoration:none; color: inherit;\">3</a><span> </span><span>+ note</span></p>"
      "<p class=\"f\"><a href=\"#citation4\" id=\"note4\" style=\"text-decoration:none; color: inherit;\">4</a><span> </span><span>+ note</span></p>"
      "<p class=\"fe\"><a href=\"#citation5\" id=\"note5\" style=\"text-decoration:none; color: inherit;\">5</a><span> </span><span>+ note</span></p>"
      "<p class=\"x\"><a href=\"#citation6\" id=\"note6\" style=\"text-decoration:none; color: inherit;\">6</a><span> </span><span>+ note</span></p>"
      "<p class=\"f\"><a href=\"#citation7\" id=\"note7\" style=\"text-decoration:none; color: inherit;\">7</a><span> </span><span>+ note</span></p>"
      "<p class=\"fe\"><a href=\"#citation8\" id=\"note8\" style=\"text-decoration:none; color: inherit;\">8</a><span> </span><span>+ note</span></p>"
      "<p class=\"x\"><a href=\"#citation9\" id=\"note9\" style=\"text-decoration:none; color: inherit;\">9</a><span> </span><span>+ note</span></p>"
      "<p class=\"f\"><a href=\"#citation10\" id=\"note10\" style=\"text-decoration:none; color: inherit;\">1</a><span> </span><span>+ note</span></p>"
      "<p class=\"fe\"><a href=\"#citation11\" id=\"note11\" style=\"text-decoration:none; color: inherit;\">2</a><span> </span><span>+ note</span></p>"
      "<p class=\"x\"><a href=\"#citation12\" id=\"note12\" style=\"text-decoration:none; color: inherit;\">3</a><span> </span><span>+ note</span></p>"
      "<p class=\"f\"><a href=\"#citation13\" id=\"note13\" style=\"text-decoration:none; color: inherit;\">4</a><span> </span><span>+ note</span></p>"
      "<p class=\"fe\"><a href=\"#citation14\" id=\"note14\" style=\"text-decoration:none; color: inherit;\">5</a><span> </span><span>+ note</span></p>"
      "<p class=\"x\"><a href=\"#citation15\" id=\"note15\" style=\"text-decoration:none; color: inherit;\">6</a><span> </span><span>+ note</span></p>"
      "<p class=\"f\"><a href=\"#citation16\" id=\"note16\" style=\"text-decoration:none; color: inherit;\">7</a><span> </span><span>+ note</span></p>"
      "<p class=\"fe\"><a href=\"#citation17\" id=\"note17\" style=\"text-decoration:none; color: inherit;\">8</a><span> </span><span>+ note</span></p>"
      "<p class=\"x\"><a href=\"#citation18\" id=\"note18\" style=\"text-decoration:none; color: inherit;\">9</a><span> </span><span>+ note</span></p>"
      "<p class=\"f\"><a href=\"#citation19\" id=\"note19\" style=\"text-decoration:none; color: inherit;\">1</a><span> </span><span>+ note</span></p>"
      "<p class=\"fe\"><a href=\"#citation20\" id=\"note20\" style=\"text-decoration:none; color: inherit;\">2</a><span> </span><span>+ note</span></p>"
      "<p class=\"x\"><a href=\"#citation21\" id=\"note21\" style=\"text-decoration:none; color: inherit;\">3</a><span> </span><span>+ note</span></p>"
      "</div>";
      Editor_Usfm2Html editor_usfm2html;
      editor_usfm2html.load (standard_usfm);
      editor_usfm2html.stylesheet (styles_logic_standard_sheet ());
      editor_usfm2html.run ();
      string html = editor_usfm2html.get ();
      evaluate (__LINE__, __func__, standard_html, html);
      
      Editor_Html2Usfm editor_html2usfm;
      editor_html2usfm.load (html);
      editor_html2usfm.stylesheet (styles_logic_standard_sheet ());
      editor_html2usfm.run ();
      string usfm = editor_html2usfm.get ();
      evaluate (__LINE__, __func__, standard_usfm, usfm);
    }
    {
      // Quill-based editor.
      string standard_html = filter_url_file_get_contents (filter_url_create_root_path ("unittests", "tests", "editor_roundtrip_1.txt"));
      Editor_Usfm2Html editor_usfm2html;
      editor_usfm2html.load (standard_usfm);
      editor_usfm2html.stylesheet (styles_logic_standard_sheet ());
      editor_usfm2html.quill ();
      editor_usfm2html.run ();
      string html = editor_usfm2html.get ();
      evaluate (__LINE__, __func__, standard_html, html);
      
      Editor_Html2Usfm editor_html2usfm;
      editor_html2usfm.load (html);
      editor_html2usfm.stylesheet (styles_logic_standard_sheet ());
      editor_html2usfm.quill ();
      editor_html2usfm.run ();
      string usfm = editor_html2usfm.get ();
      evaluate (__LINE__, __func__, standard_usfm, usfm);
    }
  }
  // Endnote.
  {
    string standard_usfm =
    "\\p The earth brought forth\\fe + \\fk brought: \\fl Heb. \\fq explanation.\\fe*.";
    {
      // DOM-based editor.
      string standard_html =
      "<p class=\"p\"><span>The earth brought forth</span><a href=\"#note1\" id=\"citation1\" style=\"text-decoration:none; color: inherit;\" class=\"superscript\">1</a><span>.</span></p>"
      "<div id=\"notes\">"
      "<hr />"
      "<p class=\"fe\"><a href=\"#citation1\" id=\"note1\" style=\"text-decoration:none; color: inherit;\">1</a><span> </span><span>+ </span><span class=\"fk\">brought: </span><span class=\"fl\">Heb. </span><span class=\"fq\">explanation.</span></p>"
      "</div>";
      Editor_Usfm2Html editor_usfm2html;
      editor_usfm2html.load (standard_usfm);
      editor_usfm2html.stylesheet (styles_logic_standard_sheet ());
      editor_usfm2html.run ();
      string html = editor_usfm2html.get ();
      evaluate (__LINE__, __func__, standard_html, html);
      
      Editor_Html2Usfm editor_html2usfm;
      editor_html2usfm.load (html);
      editor_html2usfm.stylesheet (styles_logic_standard_sheet ());
      editor_html2usfm.run ();
      string usfm = editor_html2usfm.get ();
      evaluate (__LINE__, __func__, standard_usfm, usfm);
    }
    {
      // Quill-based editor.
      string standard_html =
      "<p class=\"b-p\"><span>The earth brought forth</span><span class=\"i-notecall1\">1</span><span>.</span></p>"
      "<p class=\"b-notes\">"
      "<br />"
      "</p>"
      "<p class=\"b-fe\"><span class=\"i-notebody1\">1</span><span> </span><span>+ </span><span class=\"i-fk\">brought: </span><span class=\"i-fl\">Heb. </span><span class=\"i-fq\">explanation.</span></p>";
      Editor_Usfm2Html editor_usfm2html;
      editor_usfm2html.load (standard_usfm);
      editor_usfm2html.stylesheet (styles_logic_standard_sheet ());
      editor_usfm2html.quill ();
      editor_usfm2html.run ();
      string html = editor_usfm2html.get ();
      evaluate (__LINE__, __func__, standard_html, html);
      
      Editor_Html2Usfm editor_html2usfm;
      editor_html2usfm.load (html);
      editor_html2usfm.stylesheet (styles_logic_standard_sheet ());
      editor_html2usfm.quill ();
      editor_html2usfm.run ();
      string usfm = editor_html2usfm.get ();
      evaluate (__LINE__, __func__, standard_usfm, usfm);
    }

  }
  // Round trip from real life.
  {
    string standard_usfm =
    "\\c 1\n"
    "\\s Ukufika kukaJesu Kristu kuyamenyezelwa nguJohane uMbhabhathizi\n"
    "\\p\n"
    "\\v 1 Ukuqala kwevangeli likaJesu Kristu, iNdodana kaNkulunkulu\\x + Mat. 14.33.\\x*;\n"
    "\\v 2 njengokulotshiweyo kubaprofethi\\x + Mat. 3.1-11. Luka 3.2-16.\\x* \\add ukuthi\\add*: Khangela, mina ngiyathuma isithunywa sami phambi kobuso bakho, esizalungisa indlela yakho phambi kwakho\\x + Mal. 3.1. Mat. 11.10. Luka 7.27.\\x*.\n"
    "\\v 3 Ilizwi lomemezayo enkangala, \\add lithi\\add*: Lungisani indlela yeNkosi; qondisani izindledlana zayo\\x + Isa. 40.3. Joha. 1.23.\\x*.\n"
    "\\v 4 Kweza uJohane ebhabhathiza enkangala, etshumayela ubhabhathizo lokuphenduka kukho ukuthethelelwa kwezono\\x + Mat. 26.28. Luka 1.77.\\x*,\n"
    "\\v 5 njalo kwaphumela kuye ilizwe lonke leJudiya, labo abeJerusalema, basebebhabhathizwa bonke nguye emfuleni iJordani, bevuma izono zabo.\n"
    "\\v 6 Futhi uJohane wayembethe uboya bekamela, elozwezwe lwesikhumba ekhalweni lwakhe, wayesidla intethe loluju lweganga.\n"
    "\\p\n"
    "\\v 7 Watshumayela, esithi: Olamandla kulami uyeza emva kwami, engingafanele ukukhothama ngithukulule umchilo wamanyathela akhe\\x + Gen. 14.23. Isa. 5.27. Luka 3.16. Joha. 1.27.\\x*.\n"
    "\\v 7 Watshumayela, esithi: Olamandla kulami uyeza emva kwami, engingafanele ukukhothama ngithukulule umchilo wamanyathela akhe\\x + Gen. 14.23. Isa. 5.27. Luka 3.16. Joha. 1.27.\\x*.\n"
    "\\v 8 Mina isibili ngilibhabhathize ngamanzi; kodwa yena uzalibhabhathiza ngoMoya oNgcwele.\n"
    "\\s Ukubhabhathizwa kukaJesu\n"
    "\\p\n"
    "\\v 9 Kwasekusithi ngalezonsuku\\x + Mat. 3.13-17. Luka 3.21,22.\\x* kwafika uJesu evela eNazaretha yeGalili\\x + Mat. 2.23.\\x*, wabhabhathizwa nguJohane eJordani.\n"
    "\\v 10 Wenela ukukhuphuka emanzini, wabona amazulu eqhekezeka, loMoya kungathi lijuba esehlela phezu kwakhe;\n"
    "\\v 11 kwasekusiza ilizwi livela emazulwini, \\add lathi\\add*: Wena uyiNdodana yami ethandekayo, engithokoza ngayo.";
    {
      // DOM-based editor.
      Editor_Usfm2Html editor_usfm2html;
      editor_usfm2html.load (standard_usfm);
      editor_usfm2html.stylesheet (styles_logic_standard_sheet ());
      editor_usfm2html.run ();
      string html = editor_usfm2html.get ();
      
      Editor_Html2Usfm editor_html2usfm;
      editor_html2usfm.load (html);
      editor_html2usfm.stylesheet (styles_logic_standard_sheet ());
      editor_html2usfm.run ();
      string usfm = editor_html2usfm.get ();
      evaluate (__LINE__, __func__, standard_usfm, usfm);
    }
    {
      // Quill-based editor.
      Editor_Usfm2Html editor_usfm2html;
      editor_usfm2html.load (standard_usfm);
      editor_usfm2html.stylesheet (styles_logic_standard_sheet ());
      editor_usfm2html.quill ();
      editor_usfm2html.run ();
      string html = editor_usfm2html.get ();
      
      Editor_Html2Usfm editor_html2usfm;
      editor_html2usfm.load (html);
      editor_html2usfm.stylesheet (styles_logic_standard_sheet ());
      editor_html2usfm.quill ();
      editor_html2usfm.run ();
      string usfm = editor_html2usfm.get ();
      evaluate (__LINE__, __func__, standard_usfm, usfm);
    }
  }
  // Round trip from real life.
  {
    string standard_usfm =
    "\\c 1\n"
    "\\s Ukudalwa komhlaba laye umuntu\n"
    "\\p\n"
    "\\v 1 Ekuqaleni\\x + Hlab. 33.6; 136.5; Joha. 1.1-3; Seb. 14.15; 17.24; Kol. 1.16,17; Heb. 1.8-10; 11.3.\\x* uNkulunkulu wadala amazulu lomhlaba.\n"
    "\\v 2 Njalo umhlaba wawungelasimo ungelalutho\\x + Isa. 34.11 Jer. 4.23.\\x*, lobumnyama babuphezu kokujula; loMoya kaNkulunkulu wayendiza phezu kwamanzi.\n"
    "\\v 3 UNkulunkulu wasesithi: Kakube khona ukukhanya\\x + 2 Kor. 4.6\\x*; kwasekusiba khona ukukhanya.\n"
    "\\v 4 UNkulunkulu wasebona ukukhanya ukuthi kuhle; uNkulunkulu wasesehlukanisa phakathi kokukhanya lobumnyama.\n"
    "\\v 5 UNkulunkulu wasebiza ukukhanya ngokuthi yimini, lobumnyama wabubiza ngokuthi yibusuku. Kwasekusiba yikuhlwa, njalo kwaba yikusa, usuku lokuqala.\n"
    "\\p\n"
    "\\v 6 UNkulunkulu wasesithi: Kakube khona umkhathi\\x + Jobe 37.18. Hlab. 136.5. Jer. 10.12; 51.15.\\x* phakathi kwamanzi; kawehlukanise phakathi kwamanzi lamanzi.\n"
    "\\v 7 UNkulunkulu wasesenza umkhathi, wasesehlukanisa phakathi kwamanzi angaphansi komkhathi lamanzi aphezu komkhathi\\x + Hlab. 148.4.\\x*; kwasekusiba njalo.\n"
    "\\v 8 UNkulunkulu wasebiza umkhathi ngokuthi ngamazulu. Kwasekusiba yikuhlwa, njalo kwaba yikusa, usuku lwesibili.\n"
    "\\p\n"
    "\\v 9 UNkulunkulu wasesithi: Kakuqoqelwe amanzi avela ngaphansi kwamazulu ndawonye\\x + Jobe 38.8. Hlab. 33.7. 2 Pet. 3.5.\\x*, njalo kakubonakale umhlabathi owomileyo; kwasekusiba njalo.\n"
    "\\v 10 UNkulunkulu wasebiza umhlabathi owomileyo ngokuthi ngumhlaba, lenhlangano yamanzi wayibiza ngokuthi zinlwandle. UNkulunkulu wasebona ukuthi kuhle.\n"
    "\\v 11 UNkulunkulu wasesithi: Umhlaba kawumilise utshani\\f + \\fk utshani: \\fl Heb. \\fq utshani obubuthakathaka.\\f*, imibhida ethela inhlanyelo, isihlahla sesithelo sisenza isithelo ngohlobo lwaso, onhlanyelo yaso ikuso phezu komhlaba. Kwasekusiba njalo.\n"
    "\\v 12 Umhlaba wasuveza utshani, imibhida ethela inhlanyelo ngohlobo lwayo, lesihlahla sisenza isithelo, esinhlanyelo yaso ikuso ngohlobo lwaso. UNkulunkulu wasebona ukuthi kuhle.\n"
    "\\v 13 Kwasekusiba yikuhlwa, njalo kwaba yikusa, usuku lwesithathu.\n"
    "\\p\n"
    "\\v 14 UNkulunkulu wasesithi: Kakube khona izikhanyiso emkhathini wamazulu, ukuze zehlukanise phakathi kwemini lobusuku\\f + \\fk phakathi kwemini lobusuku: \\fl Heb. \\fq phakathi kwemini laphakathi kobusuku.\\f*; njalo zibe yizibonakaliso lezikhathi ezimisiweyo, lensuku leminyaka.\n"
    "\\v 15 Njalo zibe yizikhanyiso emkhathini wamazulu, ukuze zikhanyise emhlabeni. Kwasekusiba njalo.\n"
    "\\v 16 UNkulunkulu wasesenza izikhanyiso ezimbili ezinkulu\\x + Dute. 4.19. Hlab. 136.7,8,9.\\x*: Isikhanyiso esikhulu ukuze sibuse imini, lesikhanyiso esincinyane ukuze sibuse\\f + \\fk sibuse: \\fl Heb. \\fq kube yikubusa kwe-.\\f* ubusuku, kanye lezinkanyezi.\n"
    "\\v 17 UNkulunkulu wasezimisa emkhathini wamazulu, ukuthi zikhanyise emhlabeni,\n"
    "\\v 18 lokuthi zibuse emini\\x + Jer. 31.35\\x* lebusuku, lokwehlukanisa phakathi kokukhanya lobumnyama. UNkulunkulu wasebona ukuthi kuhle.\n"
    "\\v 19 Kwasekusiba yikuhlwa, njalo kwaba yikusa, usuku lwesine.\n"
    "\\p\n"
    "\\v 20 UNkulunkulu wasesithi: Amanzi kawagcwale ukunyakazela kwemiphefumulo ephilayo, njalo kakuphaphe inyoni phezu komhlaba emkhathini\\f + \\fk emkhathini: \\fl Heb. \\fq ebusweni bomkhathi.\\f* wamazulu.\n"
    "\\v 21 UNkulunkulu wasedala oququmadevu bolwandle abakhulu, laso sonke isidalwa esiphilayo esibhinqikayo, amanzi agcwele sona, ngohlobo lwaso, layo yonke inyoni elempiko, ngohlobo lwayo. UNkulunkulu wasebona ukuthi kuhle.\n"
    "\\v 22 UNkulunkulu wasekubusisa, esithi: Zalani, lande\\x + 8.17; 9.1.\\x*, njalo ligcwalise amanzi enlwandle, lezinyoni kazande emhlabeni.\n"
    "\\v 23 Kwasekusiba yikuhlwa, njalo kwaba yikusa, usuku lwesihlanu.\n"
    "\\p\n"
    "\\v 24 UNkulunkulu wasesithi: Umhlaba kawuveze izidalwa eziphilayo ngohlobo lwazo, izifuyo lokuhuquzelayo lenyamazana zomhlaba ngenhlobo zazo. Kwasekusiba njalo.\n"
    "\\v 25 UNkulunkulu wasesenza izinyamazana zomhlaba ngenhlobo zazo, lezifuyo ngenhlobo zazo, lakho konke okuhuquzelayo komhlaba ngenhlobo zakho. UNkulunkulu wasebona ukuthi kuhle.\n"
    "\\p\n"
    "\\v 26 UNkulunkulu wasesithi: Asenze abantu ngomfanekiso wethu\\x + 5.1; 9.6. 1 Kor. 11.7. Efe. 4.24. Kol. 3.10. Jak. 3.9.\\x*, ngesimo sethu, njalo babuse phezu kwenhlanzi zolwandle, laphezu kwenyoni zamazulu, laphezu kwezifuyo, laphezu komhlaba wonke, laphezu kwakho konke okuhuquzelayo lokho okuhuquzela emhlabeni\\x + 9.2. Hlab. 8.6.\\x*.\n"
    "\\v 27 UNkulunkulu wasemdala umuntu ngomfanekiso wakhe; wamdala ngomfanekiso kaNkulunkulu; owesilisa lowesifazana wabadala\\x + 2.18; 5.2. Mal. 2.15. Mat. 19.4. Mark. 10.6.\\x*.\n"
    "\\v 28 UNkulunkulu wasebabusisa, uNkulunkulu wasesithi kibo: Zalani lande, ligcwalise umhlaba\\x + 9.1,7.\\x* njalo liwehlisele phansi; libuse phezu kwenhlanzi zolwandle, laphezu kwenyoni zamazulu, laphezu kwakho konke okuphilayo okuhuquzela emhlabeni.\n"
    "\\p\n"
    "\\v 29 UNkulunkulu wasesithi: Khangelani, ngilinike yonke imibhida ethela inhlanyelo, esebusweni bomhlaba wonke, laso sonke isihlahla, okukuso isithelo sesihlahla esithela\\f + \\fk esithela: \\fl Heb. \\fq esihlanyela.\\f* inhlanyelo; kini singesokudla\\x + 9.3. Hlab. 145.15,16.\\x*.\n"
    "\\v 30 Njalo kuyo yonke inyamazana yomhlaba, lakuyo yonke inyoni yamazulu, lakukho konke okuhuquzela emhlabeni, okukukho umoya\\f + \\fk umoya: \\fl Heb. \\fq umphefumulo.\\f* ophilayo, lonke uhlaza ngolokudla. Kwasekusiba njalo.\n"
    "\\v 31 UNkulunkulu wasebona konke akwenzileyo; khangela-ke kwakukuhle kakhulu\\x + Tshu. 7.29. 1 Tim. 4.4.\\x*. Kwasekusiba yikuhlwa, njalo kwaba yikusa, usuku lwesithupha.";
    {
      // DOM-based editor.
      Editor_Usfm2Html editor_usfm2html;
      editor_usfm2html.load (standard_usfm);
      editor_usfm2html.stylesheet (styles_logic_standard_sheet ());
      editor_usfm2html.run ();
      string html = editor_usfm2html.get ();
      
      Editor_Html2Usfm editor_html2usfm;
      editor_html2usfm.load (html);
      editor_html2usfm.stylesheet (styles_logic_standard_sheet ());
      editor_html2usfm.run ();
      string usfm = editor_html2usfm.get ();
      evaluate (__LINE__, __func__, standard_usfm, usfm);
    }
    {
      // Quill-based editor.
      Editor_Usfm2Html editor_usfm2html;
      editor_usfm2html.load (standard_usfm);
      editor_usfm2html.stylesheet (styles_logic_standard_sheet ());
      editor_usfm2html.quill ();
      editor_usfm2html.run ();
      string html = editor_usfm2html.get ();
      
      Editor_Html2Usfm editor_html2usfm;
      editor_html2usfm.load (html);
      editor_html2usfm.stylesheet (styles_logic_standard_sheet ());
      editor_html2usfm.quill ();
      editor_html2usfm.run ();
      string usfm = editor_html2usfm.get ();
      evaluate (__LINE__, __func__, standard_usfm, usfm);
    }
  }
  // Nested text markup.
  {
    string input_usfm =
    "\\p\n"
    "\\v 2 \\add add\\+nd addnd\\+nd*\\add*.";
    string output_usfm =
    "\\p\n"
    "\\v 2 \\add add\\add*\\add \\+nd addnd\\+nd*\\add*.";
    {
      // DOM-based editor.
      string html =
      "<p class=\"p\"><span class=\"v\">2</span><span> </span><span class=\"add\">add</span><span class=\"add nd\">addnd</span><span>.</span></p>";
      Editor_Usfm2Html editor_usfm2html;
      editor_usfm2html.load (input_usfm);
      editor_usfm2html.stylesheet (styles_logic_standard_sheet ());
      editor_usfm2html.run ();
      string output = editor_usfm2html.get ();
      evaluate (__LINE__, __func__, html, output);
      
      Editor_Html2Usfm editor_html2usfm;
      editor_html2usfm.load (html);
      editor_html2usfm.stylesheet (styles_logic_standard_sheet ());
      editor_html2usfm.run ();
      output = editor_html2usfm.get ();
      evaluate (__LINE__, __func__, output_usfm, output);
    }
    {
      // Quill-based editor.
      string html =
      "<p class=\"b-p\"><span class=\"i-v\">2</span><span> </span><span class=\"i-add\">add</span><span class=\"i-add0nd\">addnd</span><span>.</span></p>";
      Editor_Usfm2Html editor_usfm2html;
      editor_usfm2html.load (input_usfm);
      editor_usfm2html.stylesheet (styles_logic_standard_sheet ());
      editor_usfm2html.quill ();
      editor_usfm2html.run ();
      string output = editor_usfm2html.get ();
      evaluate (__LINE__, __func__, html, output);
      
      Editor_Html2Usfm editor_html2usfm;
      editor_html2usfm.load (html);
      editor_html2usfm.stylesheet (styles_logic_standard_sheet ());
      editor_html2usfm.quill ();
      editor_html2usfm.run ();
      output = editor_html2usfm.get ();
      evaluate (__LINE__, __func__, output_usfm, output);
    }
  }
  // Nested text markup.
  {
    string input_usfm =
    "\\p\n"
    "\\v 2 \\add add\\+nd addnd\\add*.";
    string output_usfm =
    "\\p\n"
    "\\v 2 \\add add\\add*\\add \\+nd addnd\\+nd*\\add*.";
    {
      // DOM-based editor.
      string html =
      "<p class=\"p\"><span class=\"v\">2</span><span> </span><span class=\"add\">add</span><span class=\"add nd\">addnd</span><span>.</span></p>";
      Editor_Usfm2Html editor_usfm2html;
      editor_usfm2html.load (input_usfm);
      editor_usfm2html.stylesheet (styles_logic_standard_sheet ());
      editor_usfm2html.run ();
      string output = editor_usfm2html.get ();
      evaluate (__LINE__, __func__, html, output);
      
      Editor_Html2Usfm editor_html2usfm;
      editor_html2usfm.load (html);
      editor_html2usfm.stylesheet (styles_logic_standard_sheet ());
      editor_html2usfm.run ();
      output = editor_html2usfm.get ();
      evaluate (__LINE__, __func__, output_usfm, output);
    }
    {
      // Quill-based editor.
      string html =
      "<p class=\"b-p\"><span class=\"i-v\">2</span><span> </span><span class=\"i-add\">add</span><span class=\"i-add0nd\">addnd</span><span>.</span></p>";
      Editor_Usfm2Html editor_usfm2html;
      editor_usfm2html.load (input_usfm);
      editor_usfm2html.stylesheet (styles_logic_standard_sheet ());
      editor_usfm2html.quill ();
      editor_usfm2html.run ();
      string output = editor_usfm2html.get ();
      evaluate (__LINE__, __func__, html, output);
      
      Editor_Html2Usfm editor_html2usfm;
      editor_html2usfm.load (html);
      editor_html2usfm.stylesheet (styles_logic_standard_sheet ());
      editor_html2usfm.quill ();
      editor_html2usfm.run ();
      output = editor_html2usfm.get ();
      evaluate (__LINE__, __func__, output_usfm, output);
    }
  }
  // Nested text markup.
  {
    string input_usfm  = "\\p The \\add \\+nd Lord God\\+nd* is\\add* calling you";
    string output_usfm = "\\p The \\add \\+nd Lord God\\+nd*\\add*\\add  is\\add* calling you";
    {
      // DOM-based editor.
      string html =
      "<p class=\"p\"><span>The </span><span class=\"add nd\">Lord God</span><span class=\"add\"> is</span><span> calling you</span></p>";
      Editor_Usfm2Html editor_usfm2html;
      editor_usfm2html.load (input_usfm);
      editor_usfm2html.stylesheet (styles_logic_standard_sheet ());
      editor_usfm2html.run ();
      string output = editor_usfm2html.get ();
      evaluate (__LINE__, __func__, html, output);
      
      Editor_Html2Usfm editor_html2usfm;
      editor_html2usfm.load (html);
      editor_html2usfm.stylesheet (styles_logic_standard_sheet ());
      editor_html2usfm.run ();
      output = editor_html2usfm.get ();
      evaluate (__LINE__, __func__, output_usfm, output);
    }
    {
      // Quill-based editor.
      string html =
      "<p class=\"b-p\"><span>The </span><span class=\"i-add0nd\">Lord God</span><span class=\"i-add\"> is</span><span> calling you</span></p>";
      Editor_Usfm2Html editor_usfm2html;
      editor_usfm2html.load (input_usfm);
      editor_usfm2html.stylesheet (styles_logic_standard_sheet ());
      editor_usfm2html.quill ();
      editor_usfm2html.run ();
      string output = editor_usfm2html.get ();
      evaluate (__LINE__, __func__, html, output);
      
      Editor_Html2Usfm editor_html2usfm;
      editor_html2usfm.load (html);
      editor_html2usfm.stylesheet (styles_logic_standard_sheet ());
      editor_html2usfm.quill ();
      editor_html2usfm.run ();
      output = editor_html2usfm.get ();
      evaluate (__LINE__, __func__, output_usfm, output);
    }
  }
  // Nested note markup.
  {
    string input_usfm =
    "\\p\n"
    "\\v 2 text\\f + \\fk fk \\+fdc key-fdc\\+fdc*\\fk* normal\\f*.";
    string output_usfm =
    "\\p\n"
    "\\v 2 text\\f + \\fk fk \\fk \\+fdc key-fdc\\+fdc*\\fk* normal\\f*.";
    {
      // DOM-based editor.
      string html =
      "<p class=\"p\"><span class=\"v\">2</span><span> </span><span>text</span><a href=\"#note1\" id=\"citation1\" style=\"text-decoration:none; color: inherit;\" class=\"superscript\">1</a><span>.</span></p>"
      "<div id=\"notes\">"
      "<hr />"
      "<p class=\"f\"><a href=\"#citation1\" id=\"note1\" style=\"text-decoration:none; color: inherit;\">1</a><span> </span><span>+ </span><span class=\"fk\">fk </span><span class=\"fk fdc\">key-fdc</span><span> normal</span></p>"
      "</div>";
      Editor_Usfm2Html editor_usfm2html;
      editor_usfm2html.load (input_usfm);
      editor_usfm2html.stylesheet (styles_logic_standard_sheet ());
      editor_usfm2html.run ();
      string output = editor_usfm2html.get ();
      evaluate (__LINE__, __func__, html, output);
      
      Editor_Html2Usfm editor_html2usfm;
      editor_html2usfm.load (html);
      editor_html2usfm.stylesheet (styles_logic_standard_sheet ());
      editor_html2usfm.run ();
      output = editor_html2usfm.get ();
      evaluate (__LINE__, __func__, output_usfm, output);
    }
    {
      // Quill-based editor.
      string html =
      "<p class=\"b-p\"><span class=\"i-v\">2</span><span> </span><span>text</span><span class=\"i-notecall1\">1</span><span>.</span></p>"
      "<p class=\"b-notes\">"
      "<br />"
      "</p>"
      "<p class=\"b-f\"><span class=\"i-notebody1\">1</span><span> </span><span>+ </span><span class=\"i-fk\">fk </span><span class=\"i-fk0fdc\">key-fdc</span><span> normal</span></p>";
      Editor_Usfm2Html editor_usfm2html;
      editor_usfm2html.load (input_usfm);
      editor_usfm2html.stylesheet (styles_logic_standard_sheet ());
      editor_usfm2html.quill ();
      editor_usfm2html.run ();
      string output = editor_usfm2html.get ();
      evaluate (__LINE__, __func__, html, output);
      
      Editor_Html2Usfm editor_html2usfm;
      editor_html2usfm.load (html);
      editor_html2usfm.stylesheet (styles_logic_standard_sheet ());
      editor_html2usfm.quill ();
      editor_html2usfm.run ();
      output = editor_html2usfm.get ();
      evaluate (__LINE__, __func__, output_usfm, output);
    }
  }
  // Nested note markup.
  {
    string input_usfm =
    "\\p"
    "\\v 2 text\\f + \\fk fk \\+fdc key-fdc\\fk* normal\\f*.";
    string output_usfm =
    "\\p\n"
    "\\v 2 text\\f + \\fk fk \\fk \\+fdc key-fdc\\+fdc*\\fk* normal\\f*.";
    {
      // DOM-based editor.
      string html =
      "<p class=\"p\"><span class=\"v\">2</span><span> </span><span>text</span><a href=\"#note1\" id=\"citation1\" style=\"text-decoration:none; color: inherit;\" class=\"superscript\">1</a><span>.</span></p>"
      "<div id=\"notes\">"
      "<hr />"
      "<p class=\"f\"><a href=\"#citation1\" id=\"note1\" style=\"text-decoration:none; color: inherit;\">1</a><span> </span><span>+ </span><span class=\"fk\">fk </span><span class=\"fk fdc\">key-fdc</span><span> normal</span></p>"
      "</div>";
      Editor_Usfm2Html editor_usfm2html;
      editor_usfm2html.load (input_usfm);
      editor_usfm2html.stylesheet (styles_logic_standard_sheet ());
      editor_usfm2html.run ();
      string output = editor_usfm2html.get ();
      evaluate (__LINE__, __func__, html, output);
      
      Editor_Html2Usfm editor_html2usfm;
      editor_html2usfm.load (html);
      editor_html2usfm.stylesheet (styles_logic_standard_sheet ());
      editor_html2usfm.run ();
      output = editor_html2usfm.get ();
      evaluate (__LINE__, __func__, output_usfm, output);
    }
    {
      // Quill-based editor.
      string html =
      "<p class=\"b-p\"><span class=\"i-v\">2</span><span> </span><span>text</span><span class=\"i-notecall1\">1</span><span>.</span></p>"
      "<p class=\"b-notes\">"
      "<br />"
      "</p>"
      "<p class=\"b-f\"><span class=\"i-notebody1\">1</span><span> </span><span>+ </span><span class=\"i-fk\">fk </span><span class=\"i-fk0fdc\">key-fdc</span><span> normal</span></p>";
      Editor_Usfm2Html editor_usfm2html;
      editor_usfm2html.load (input_usfm);
      editor_usfm2html.stylesheet (styles_logic_standard_sheet ());
      editor_usfm2html.quill ();
      editor_usfm2html.run ();
      string output = editor_usfm2html.get ();
      evaluate (__LINE__, __func__, html, output);
      
      Editor_Html2Usfm editor_html2usfm;
      editor_html2usfm.load (html);
      editor_html2usfm.stylesheet (styles_logic_standard_sheet ());
      editor_html2usfm.quill ();
      editor_html2usfm.run ();
      output = editor_html2usfm.get ();
      evaluate (__LINE__, __func__, output_usfm, output);
    }
  }
  // Fix for change \ft to \fk
  {
    // A bug was discovered in the Bible editor where "... \fk ... \ft ..." was changed to "... \fk ... \fk ...".
    // The bug was fixed.
    // This test would catch any regression.
    string usfm =
    "\\c 1\n"
    "\\v 1 Canonical text\\f + \\fr 1:1 \\fk Footnote fk style \\ft Footnote ft style\\f* canonical text.";
    {
      // DOM-based editor.
      string html =
      "<p class=\"c\"><span>1</span><span> </span><span class=\"v\">1</span><span> </span><span>Canonical text</span><a href=\"#note1\" id=\"citation1\" style=\"text-decoration:none; color: inherit;\" class=\"superscript\">1</a><span> canonical text.</span></p>"
      "<div id=\"notes\">"
      "<hr />"
      "<p class=\"f\"><a href=\"#citation1\" id=\"note1\" style=\"text-decoration:none; color: inherit;\">1</a><span> </span><span>+ </span><span class=\"fr\">1:1 </span><span class=\"fk\">Footnote fk style </span><span class=\"ft\">Footnote ft style</span></p>"
      "</div>";
      Editor_Usfm2Html editor_usfm2html;
      editor_usfm2html.load (usfm);
      editor_usfm2html.stylesheet (styles_logic_standard_sheet ());
      editor_usfm2html.run ();
      string output = editor_usfm2html.get ();
      evaluate (__LINE__, __func__, html, output);
      
      Editor_Html2Usfm editor_html2usfm;
      editor_html2usfm.load (html);
      editor_html2usfm.stylesheet (styles_logic_standard_sheet ());
      editor_html2usfm.run ();
      output = editor_html2usfm.get ();
      evaluate (__LINE__, __func__, usfm, output);
    }
    {
      // Quill-based editor.
      string html =
      "<p class=\"b-c\"><span>1</span><span> </span><span class=\"i-v\">1</span><span> </span><span>Canonical text</span><span class=\"i-notecall1\">1</span><span> canonical text.</span></p>"
      "<p class=\"b-notes\">"
      "<br />"
      "</p>"
      "<p class=\"b-f\"><span class=\"i-notebody1\">1</span><span> </span><span>+ </span><span class=\"i-fr\">1:1 </span><span class=\"i-fk\">Footnote fk style </span><span class=\"i-ft\">Footnote ft style</span></p>";
      Editor_Usfm2Html editor_usfm2html;
      editor_usfm2html.load (usfm);
      editor_usfm2html.stylesheet (styles_logic_standard_sheet ());
      editor_usfm2html.quill ();
      editor_usfm2html.run ();
      string output = editor_usfm2html.get ();
      evaluate (__LINE__, __func__, html, output);
      
      Editor_Html2Usfm editor_html2usfm;
      editor_html2usfm.load (html);
      editor_html2usfm.stylesheet (styles_logic_standard_sheet ());
      editor_html2usfm.quill ();
      editor_html2usfm.run ();
      output = editor_html2usfm.get ();
      evaluate (__LINE__, __func__, usfm, output);
    }
  }
  // \b Blank line
  {
    string standard_usfm =
    "\\p paragraph\n"
    "\\b\n"
    "\\p paragraph";
    {
      // DOM-based editor.
      Editor_Usfm2Html editor_usfm2html;
      editor_usfm2html.load (standard_usfm);
      editor_usfm2html.stylesheet (styles_logic_standard_sheet ());
      editor_usfm2html.run ();
      string html = editor_usfm2html.get ();
      string standard_html = "<p class=\"p\"><span>paragraph</span></p><p class=\"b\"><br></p><p class=\"p\"><span>paragraph</span></p>";
      evaluate (__LINE__, __func__, standard_html, html);
      
      Editor_Html2Usfm editor_html2usfm;
      editor_html2usfm.load (html);
      editor_html2usfm.stylesheet (styles_logic_standard_sheet ());
      editor_html2usfm.run ();
      string usfm = editor_html2usfm.get ();
      evaluate (__LINE__, __func__, standard_usfm, usfm);
    }
    {
      // Quill-based editor.
      Editor_Usfm2Html editor_usfm2html;
      editor_usfm2html.load (standard_usfm);
      editor_usfm2html.stylesheet (styles_logic_standard_sheet ());
      editor_usfm2html.quill ();
      editor_usfm2html.run ();
      string html = editor_usfm2html.get ();
      string standard_html = "<p class=\"b-p\"><span>paragraph</span></p><p class=\"b-b\"><br></p><p class=\"b-p\"><span>paragraph</span></p>";
      evaluate (__LINE__, __func__, standard_html, html);
      
      Editor_Html2Usfm editor_html2usfm;
      editor_html2usfm.quill ();
      editor_html2usfm.load (html);
      editor_html2usfm.stylesheet (styles_logic_standard_sheet ());
      editor_html2usfm.run ();
      string usfm = editor_html2usfm.get ();
      evaluate (__LINE__, __func__, standard_usfm, usfm);
    }
  }
  
  // Test the \sd and \sd2 semantic divisions.
  {
    string standard_usfm =
    "\\p paragraph\n"
    "\\sd\n"
    "\\p paragraph\n"
    "\\sd2"
    ;
    {
      // DOM-based editor.
      Editor_Usfm2Html editor_usfm2html;
      editor_usfm2html.load (standard_usfm);
      editor_usfm2html.stylesheet (styles_logic_standard_sheet ());
      editor_usfm2html.run ();
      string html = editor_usfm2html.get ();
      string standard_html = "<p class=\"p\"><span>paragraph</span></p><p class=\"sd\"><br></p><p class=\"p\"><span>paragraph</span></p><p class=\"sd2\"><br></p>";
      evaluate (__LINE__, __func__, standard_html, html);
      
      Editor_Html2Usfm editor_html2usfm;
      editor_html2usfm.load (html);
      editor_html2usfm.stylesheet (styles_logic_standard_sheet ());
      editor_html2usfm.run ();
      string usfm = editor_html2usfm.get ();
      evaluate (__LINE__, __func__, standard_usfm, usfm);
    }
    {
      // Quill-based editor.
      Editor_Usfm2Html editor_usfm2html;
      editor_usfm2html.load (standard_usfm);
      editor_usfm2html.stylesheet (styles_logic_standard_sheet ());
      editor_usfm2html.quill ();
      editor_usfm2html.run ();
      string html = editor_usfm2html.get ();
      string standard_html = "<p class=\"b-p\"><span>paragraph</span></p><p class=\"b-sd\"><br></p><p class=\"b-p\"><span>paragraph</span></p><p class=\"b-sd2\"><br></p>";
      evaluate (__LINE__, __func__, standard_html, html);
      
      Editor_Html2Usfm editor_html2usfm;
      editor_html2usfm.quill ();
      editor_html2usfm.load (html);
      editor_html2usfm.stylesheet (styles_logic_standard_sheet ());
      editor_html2usfm.run ();
      string usfm = editor_html2usfm.get ();
      evaluate (__LINE__, __func__, standard_usfm, usfm);
    }
  }
  
  // Text \xo and \xt.
  {
    string standardusfm =
    "\\p\n\\v 1 The text\\x + \\xo 1 \\xt Passage\\x*.";
    {
      // DOM-based editor.
      string standardhtml =
      "<p class=\"p\"><span class=\"v\">1</span><span> </span><span>The text</span><a href=\"#note1\" id=\"citation1\" style=\"text-decoration:none; color: inherit;\" class=\"superscript\">1</a><span>.</span></p><div id=\"notes\"><hr /><p class=\"x\"><a href=\"#citation1\" id=\"note1\" style=\"text-decoration:none; color: inherit;\">1</a><span> </span><span>+ </span><span class=\"xo\">1 </span><span class=\"xt\">Passage</span></p></div>";
      Editor_Usfm2Html editor_usfm2html;
      editor_usfm2html.load (standardusfm);
      editor_usfm2html.stylesheet (styles_logic_standard_sheet ());
      editor_usfm2html.run ();
      string html = editor_usfm2html.get ();
      evaluate (__LINE__, __func__, standardhtml, html);
      
      Editor_Html2Usfm editor_html2usfm;
      editor_html2usfm.load (standardhtml);
      editor_html2usfm.stylesheet (styles_logic_standard_sheet ());
      editor_html2usfm.run ();
      string usfm = editor_html2usfm.get ();
      evaluate (__LINE__, __func__, standardusfm, usfm);
    }
    {
      // Quill-based editor.
      string standardhtml =
      "<p class=\"b-p\"><span class=\"i-v\">1</span><span> </span><span>The text</span><span class=\"i-notecall1\">1</span><span>.</span></p><p class=\"b-notes\"><br /></p><p class=\"b-x\"><span class=\"i-notebody1\">1</span><span> </span><span>+ </span><span class=\"i-xo\">1 </span><span class=\"i-xt\">Passage</span></p>";
      Editor_Usfm2Html editor_usfm2html;
      editor_usfm2html.load (standardusfm);
      editor_usfm2html.stylesheet (styles_logic_standard_sheet ());
      editor_usfm2html.quill ();
      editor_usfm2html.run ();
      string html = editor_usfm2html.get ();
      evaluate (__LINE__, __func__, standardhtml, html);
      
      Editor_Html2Usfm editor_html2usfm;
      editor_html2usfm.load (standardhtml);
      editor_html2usfm.stylesheet (styles_logic_standard_sheet ());
      editor_html2usfm.quill ();
      editor_html2usfm.run ();
      string usfm = editor_html2usfm.get ();
      evaluate (__LINE__, __func__, standardusfm, usfm);
    }
  }
  // Unmatched note opener and xref opener.
  {
    string standard_usfm =
    "\\c 117\n"
    "\\p\n"
    "\\v 1 Praise Yahweh\\f all you nations!\n"
    "\\v 2 For his loving kindness\\x is great toward us.\n";
    {
      // DOM-based editor.
      string standard_html =
      "<p class=\"c\"><span>117</span></p><p class=\"p\"><span class=\"v\">1</span><span> </span><span>Praise Yahweh</span><span>\\f </span><span>all you nations!</span><span> </span><span class=\"v\">2</span><span> </span><span>For his loving kindness</span><span>\\x </span><span>is great toward us.</span></p>";
      Editor_Usfm2Html editor_usfm2html;
      editor_usfm2html.load (standard_usfm);
      editor_usfm2html.stylesheet (styles_logic_standard_sheet ());
      editor_usfm2html.run ();
      string html = editor_usfm2html.get ();
      evaluate (__LINE__, __func__, standard_html, html);
      
      Editor_Html2Usfm editor_html2usfm;
      editor_html2usfm.load (html);
      editor_html2usfm.stylesheet (styles_logic_standard_sheet ());
      editor_html2usfm.run ();
      string usfm = editor_html2usfm.get ();
      evaluate (__LINE__, __func__, filter_string_trim (standard_usfm), filter_string_trim (usfm));
    }
    {
      // Quill-based editor.
      string standard_html =
      "<p class=\"b-c\"><span>117</span></p><p class=\"b-p\"><span class=\"i-v\">1</span><span> </span><span>Praise Yahweh</span><span>\\f </span><span>all you nations!</span><span> </span><span class=\"i-v\">2</span><span> </span><span>For his loving kindness</span><span>\\x </span><span>is great toward us.</span></p>";
      Editor_Usfm2Html editor_usfm2html;
      editor_usfm2html.load (standard_usfm);
      editor_usfm2html.stylesheet (styles_logic_standard_sheet ());
      editor_usfm2html.quill ();
      editor_usfm2html.run ();
      string html = editor_usfm2html.get ();
      evaluate (__LINE__, __func__, standard_html, html);
      
      Editor_Html2Usfm editor_html2usfm;
      editor_html2usfm.load (html);
      editor_html2usfm.stylesheet (styles_logic_standard_sheet ());
      editor_html2usfm.quill ();
      editor_html2usfm.run ();
      string usfm = editor_html2usfm.get ();
      evaluate (__LINE__, __func__, filter_string_trim (standard_usfm), filter_string_trim (usfm));
    }
  }
  // Inline opener without matching inline closer.
  {
    string standard_usfm =
    "\\p The \\add Lord God is calling you";
    {
      // DOM-based editor.
      string standard_html =
      "<p class=\"p\"><span>The </span><span>\\add </span><span>Lord God is calling you</span></p>";
      Editor_Usfm2Html editor_usfm2html;
      editor_usfm2html.load (standard_usfm);
      editor_usfm2html.stylesheet (styles_logic_standard_sheet ());
      editor_usfm2html.run ();
      string html = editor_usfm2html.get ();
      evaluate (__LINE__, __func__, standard_html, html);
      
      Editor_Html2Usfm editor_html2usfm;
      editor_html2usfm.load (html);
      editor_html2usfm.stylesheet (styles_logic_standard_sheet ());
      editor_html2usfm.run ();
      string usfm = editor_html2usfm.get ();
      evaluate (__LINE__, __func__, filter_string_trim (standard_usfm), filter_string_trim (usfm));
    }
    {
      // Quill-based editor.
      string standard_html =
      "<p class=\"b-p\"><span>The </span><span>\\add </span><span>Lord God is calling you</span></p>";
      Editor_Usfm2Html editor_usfm2html;
      editor_usfm2html.load (standard_usfm);
      editor_usfm2html.stylesheet (styles_logic_standard_sheet ());
      editor_usfm2html.quill ();
      editor_usfm2html.run ();
      string html = editor_usfm2html.get ();
      evaluate (__LINE__, __func__, standard_html, html);
      
      Editor_Html2Usfm editor_html2usfm;
      editor_html2usfm.load (html);
      editor_html2usfm.stylesheet (styles_logic_standard_sheet ());
      editor_html2usfm.quill ();
      editor_html2usfm.run ();
      string usfm = editor_html2usfm.get ();
      evaluate (__LINE__, __func__, filter_string_trim (standard_usfm), filter_string_trim (usfm));
    }
  }
  // Inline opener without matching inline closer but with other inline markup.
  {
    string standard_usfm =
    "\\p The \\add Lord \\nd God\\nd* is calling you\n"
    "\\v 2 Verse text";
    {
      // DOM-based editor.
      string standard_html =
      "<p class=\"p\"><span>The </span><span>\\add </span><span>Lord </span><span class=\"nd\">God</span><span> is calling you</span><span> </span><span class=\"v\">2</span><span> </span><span>Verse text</span></p>";
      Editor_Usfm2Html editor_usfm2html;
      editor_usfm2html.load (standard_usfm);
      editor_usfm2html.stylesheet (styles_logic_standard_sheet ());
      editor_usfm2html.run ();
      string html = editor_usfm2html.get ();
      evaluate (__LINE__, __func__, standard_html, html);
      
      Editor_Html2Usfm editor_html2usfm;
      editor_html2usfm.load (html);
      editor_html2usfm.stylesheet (styles_logic_standard_sheet ());
      editor_html2usfm.run ();
      string usfm = editor_html2usfm.get ();
      evaluate (__LINE__, __func__, filter_string_trim (standard_usfm), filter_string_trim (usfm));
    }
    {
      // Quill-based editor.
      string standard_html =
      "<p class=\"b-p\"><span>The </span><span>\\add </span><span>Lord </span><span class=\"i-nd\">God</span><span> is calling you</span><span> </span><span class=\"i-v\">2</span><span> </span><span>Verse text</span></p>";
      Editor_Usfm2Html editor_usfm2html;
      editor_usfm2html.load (standard_usfm);
      editor_usfm2html.stylesheet (styles_logic_standard_sheet ());
      editor_usfm2html.quill ();
      editor_usfm2html.run ();
      string html = editor_usfm2html.get ();
      evaluate (__LINE__, __func__, standard_html, html);
      
      Editor_Html2Usfm editor_html2usfm;
      editor_html2usfm.load (html);
      editor_html2usfm.stylesheet (styles_logic_standard_sheet ());
      editor_html2usfm.quill ();
      editor_html2usfm.run ();
      string usfm = editor_html2usfm.get ();
      evaluate (__LINE__, __func__, filter_string_trim (standard_usfm), filter_string_trim (usfm));
    }
  }
  // Inline opener without matching inline closer and with a paragraph after that.
  {
    string standard_usfm =
    "\\p The \\add Lord God is calling you\n"
    "\\p Paragraph";
    {
      // DOM-based editor.
      string standard_html =
      "<p class=\"p\"><span>The </span><span>\\add </span><span>Lord God is calling you</span></p><p class=\"p\"><span>Paragraph</span></p>";
      
      Editor_Usfm2Html editor_usfm2html;
      editor_usfm2html.load (standard_usfm);
      editor_usfm2html.stylesheet (styles_logic_standard_sheet ());
      editor_usfm2html.run ();
      string html = editor_usfm2html.get ();
      evaluate (__LINE__, __func__, standard_html, html);
      
      Editor_Html2Usfm editor_html2usfm;
      editor_html2usfm.load (html);
      editor_html2usfm.stylesheet (styles_logic_standard_sheet ());
      editor_html2usfm.run ();
      string usfm = editor_html2usfm.get ();
      evaluate (__LINE__, __func__, filter_string_trim (standard_usfm), filter_string_trim (usfm));
    }
    {
      // Quill-based editor.
      string standard_html =
      "<p class=\"b-p\"><span>The </span><span>\\add </span><span>Lord God is calling you</span></p><p class=\"b-p\"><span>Paragraph</span></p>";
      
      Editor_Usfm2Html editor_usfm2html;
      editor_usfm2html.load (standard_usfm);
      editor_usfm2html.stylesheet (styles_logic_standard_sheet ());
      editor_usfm2html.quill ();
      editor_usfm2html.run ();
      string html = editor_usfm2html.get ();
      evaluate (__LINE__, __func__, standard_html, html);
      
      Editor_Html2Usfm editor_html2usfm;
      editor_html2usfm.load (html);
      editor_html2usfm.stylesheet (styles_logic_standard_sheet ());
      editor_html2usfm.quill ();
      editor_html2usfm.run ();
      string usfm = editor_html2usfm.get ();
      evaluate (__LINE__, __func__, filter_string_trim (standard_usfm), filter_string_trim (usfm));
    }
  }
  // Testing editing one verse, which does not have a starting paragraph.
  {
    string usfm = "\\v 1 God created";
    {
      // DOM-based editor.
      string html = "<p><span class=\"v\">1</span><span> </span><span>God created</span></p>";
      Editor_Usfm2Html editor_usfm2html;
      editor_usfm2html.load (usfm);
      editor_usfm2html.stylesheet (styles_logic_standard_sheet ());
      editor_usfm2html.run ();
      string output = editor_usfm2html.get ();
      evaluate (__LINE__, __func__, html, output);
      output = editor_export_verse (styles_logic_standard_sheet (), html);
      evaluate (__LINE__, __func__, usfm, output);
    }
    {
      // Quill-based editor.
      string html = "<p><span class=\"i-v\">1</span><span> </span><span>God created</span></p>";
      Editor_Usfm2Html editor_usfm2html;
      editor_usfm2html.load (usfm);
      editor_usfm2html.stylesheet (styles_logic_standard_sheet ());
      editor_usfm2html.quill ();
      editor_usfm2html.run ();
      string output = editor_usfm2html.get ();
      evaluate (__LINE__, __func__, html, output);
      output = editor_export_verse_quill (styles_logic_standard_sheet (), html);
      evaluate (__LINE__, __func__, usfm, output);
    }
  }
  // Testing editing one verse: The chapter number, or verse 0.
  {
    string usfm = "\\c 1\n"
    "\\p";
    {
      // DOM-based editor.
      Editor_Usfm2Html editor_usfm2html;
      editor_usfm2html.load (usfm);
      editor_usfm2html.stylesheet (styles_logic_standard_sheet ());
      editor_usfm2html.run ();
      string output = editor_usfm2html.get ();
      
      string html = "<p class=\"c\"><span>1</span></p><p class=\"p\" />";
      evaluate (__LINE__, __func__, html, output);
      
      output = editor_export_verse (styles_logic_standard_sheet (), html);
      evaluate (__LINE__, __func__, usfm, output);
    }
    {
      // Quill-based editor.
      Editor_Usfm2Html editor_usfm2html;
      editor_usfm2html.load (usfm);
      editor_usfm2html.stylesheet (styles_logic_standard_sheet ());
      editor_usfm2html.quill ();
      editor_usfm2html.run ();
      string output = editor_usfm2html.get ();
      
      string html = "<p class=\"b-c\"><span>1</span></p><p class=\"b-p\" />";
      evaluate (__LINE__, __func__, html, output);
      
      output = editor_export_verse_quill (styles_logic_standard_sheet (), html);
      evaluate (__LINE__, __func__, usfm, output);
    }
  }
  // One-verse editor, testing chapter 0 verse 0.
  {
    string usfm =
    "\\id GEN Genesis\n"
    "\\h Genesis\n"
    "\\toc1 The First Book of Moses, called Genesis\n"
    "\\mt1 The First Book of Moses, called Genesis";
    {
      // DOM-based editor.
      Editor_Usfm2Html editor_usfm2html;
      editor_usfm2html.load (usfm);
      editor_usfm2html.stylesheet (styles_logic_standard_sheet ());
      editor_usfm2html.run ();
      string output = editor_usfm2html.get ();
      
      string html = "<p class=\"mono\"><span>\\id </span><span>GEN Genesis</span></p><p class=\"mono\"><span>\\h </span><span>Genesis</span></p><p class=\"mono\"><span>\\toc1 </span><span>The First Book of Moses, called Genesis</span></p><p class=\"mt1\"><span>The First Book of Moses, called Genesis</span></p>";
      evaluate (__LINE__, __func__, html, output);
      
      output = editor_export_verse (styles_logic_standard_sheet (), html);
      evaluate (__LINE__, __func__, usfm, output);
    }
    {
      // Quill-based editor.
      Editor_Usfm2Html editor_usfm2html;
      editor_usfm2html.load (usfm);
      editor_usfm2html.stylesheet (styles_logic_standard_sheet ());
      editor_usfm2html.quill ();
      editor_usfm2html.run ();
      string output = editor_usfm2html.get ();
      
      string html = "<p class=\"b-mono\"><span>\\id </span><span>GEN Genesis</span></p><p class=\"b-mono\"><span>\\h </span><span>Genesis</span></p><p class=\"b-mono\"><span>\\toc1 </span><span>The First Book of Moses, called Genesis</span></p><p class=\"b-mt1\"><span>The First Book of Moses, called Genesis</span></p>";
      evaluate (__LINE__, __func__, html, output);
      
      output = editor_export_verse_quill (styles_logic_standard_sheet (), html);
      evaluate (__LINE__, __func__, usfm, output);
    }
  }
  // Testing one verse: a paragraph with content.
  {
    string usfm = "\\p And God called the firmament Heaven";
    {
      // DOM-based editor.
      Editor_Usfm2Html editor_usfm2html;
      editor_usfm2html.load (usfm);
      editor_usfm2html.stylesheet (styles_logic_standard_sheet ());
      editor_usfm2html.run ();
      string output = editor_usfm2html.get ();
      
      string html = "<p class=\"p\"><span>And God called the firmament Heaven</span></p>";
      evaluate (__LINE__, __func__, html, output);
      
      output = editor_export_verse (styles_logic_standard_sheet (), html);
      evaluate (__LINE__, __func__, usfm, output);
    }
    {
      // Quill-based editor.
      Editor_Usfm2Html editor_usfm2html;
      editor_usfm2html.load (usfm);
      editor_usfm2html.stylesheet (styles_logic_standard_sheet ());
      editor_usfm2html.quill ();
      editor_usfm2html.run ();
      string output = editor_usfm2html.get ();
      
      string html = "<p class=\"b-p\"><span>And God called the firmament Heaven</span></p>";
      evaluate (__LINE__, __func__, html, output);
      
      output = editor_export_verse_quill (styles_logic_standard_sheet (), html);
      evaluate (__LINE__, __func__, usfm, output);
    }
  }
  // Testing \add ..\add* markup in a footnote.
  {
    string standard_usfm = "\\p Praise Yahweh\\f \\add I\\add* am\\f*, all you nations!";
    {
      // DOM-based editor.
      string standard_html = "<p class=\"p\"><span>Praise Yahweh</span><a href=\"#note1\" id=\"citation1\" style=\"text-decoration:none; color: inherit;\" class=\"superscript\">1</a><span>, all you nations!</span></p><div id=\"notes\"><hr /><p class=\"f\"><a href=\"#citation1\" id=\"note1\" style=\"text-decoration:none; color: inherit;\">1</a><span> </span><span class=\"add\">I</span><span> am</span></p></div>";
      Editor_Usfm2Html editor_usfm2html;
      editor_usfm2html.load (standard_usfm);
      editor_usfm2html.stylesheet (styles_logic_standard_sheet ());
      editor_usfm2html.run ();
      string output_html = editor_usfm2html.get ();
      evaluate (__LINE__, __func__, standard_html, output_html);
      
      Editor_Html2Usfm editor_html2usfm;
      editor_html2usfm.load (output_html);
      editor_html2usfm.stylesheet (styles_logic_standard_sheet ());
      editor_html2usfm.run ();
      string output_usfm = editor_html2usfm.get ();
      evaluate (__LINE__, __func__, standard_usfm, output_usfm);
    }
    {
      // Quill-based editor.
      string standard_html = "<p class=\"b-p\"><span>Praise Yahweh</span><span class=\"i-notecall1\">1</span><span>, all you nations!</span></p><p class=\"b-notes\"><br /></p><p class=\"b-f\"><span class=\"i-notebody1\">1</span><span> </span><span class=\"i-add\">I</span><span> am</span></p>";
      Editor_Usfm2Html editor_usfm2html;
      editor_usfm2html.load (standard_usfm);
      editor_usfm2html.stylesheet (styles_logic_standard_sheet ());
      editor_usfm2html.quill ();
      editor_usfm2html.run ();
      string output_html = editor_usfm2html.get ();
      evaluate (__LINE__, __func__, standard_html, output_html);
      
      Editor_Html2Usfm editor_html2usfm;
      editor_html2usfm.load (output_html);
      editor_html2usfm.stylesheet (styles_logic_standard_sheet ());
      editor_html2usfm.quill ();
      editor_html2usfm.run ();
      string output_usfm = editor_html2usfm.get ();
      evaluate (__LINE__, __func__, standard_usfm, output_usfm);
    }
  }
  // Testing \xt in a footnote.
  {
    string standard_usfm = "\\p Praise Yahweh\\f I am, see \\xt Exod.6.3.\\f*, all you nations!";
    {
      // DOM-based editor.
      string standard_html = "<p class=\"p\"><span>Praise Yahweh</span><a href=\"#note1\" id=\"citation1\" style=\"text-decoration:none; color: inherit;\" class=\"superscript\">1</a><span>, all you nations!</span></p><div id=\"notes\"><hr /><p class=\"f\"><a href=\"#citation1\" id=\"note1\" style=\"text-decoration:none; color: inherit;\">1</a><span> </span><span>I am, see </span><span class=\"xt\">Exod.6.3.</span></p></div>";
      Editor_Usfm2Html editor_usfm2html;
      editor_usfm2html.load (standard_usfm);
      editor_usfm2html.stylesheet (styles_logic_standard_sheet ());
      editor_usfm2html.run ();
      string output_html = editor_usfm2html.get ();
      evaluate (__LINE__, __func__, standard_html, output_html);
      
      Editor_Html2Usfm editor_html2usfm;
      editor_html2usfm.load (output_html);
      editor_html2usfm.stylesheet (styles_logic_standard_sheet ());
      editor_html2usfm.run ();
      string output_usfm = editor_html2usfm.get ();
      evaluate (__LINE__, __func__, standard_usfm, output_usfm);
    }
    {
      // Quill-based editor.
      string standard_html = "<p class=\"b-p\"><span>Praise Yahweh</span><span class=\"i-notecall1\">1</span><span>, all you nations!</span></p><p class=\"b-notes\"><br /></p><p class=\"b-f\"><span class=\"i-notebody1\">1</span><span> </span><span>I am, see </span><span class=\"i-xt\">Exod.6.3.</span></p>";
      Editor_Usfm2Html editor_usfm2html;
      editor_usfm2html.load (standard_usfm);
      editor_usfm2html.stylesheet (styles_logic_standard_sheet ());
      editor_usfm2html.quill ();
      editor_usfm2html.run ();
      string output_html = editor_usfm2html.get ();
      evaluate (__LINE__, __func__, standard_html, output_html);
      
      Editor_Html2Usfm editor_html2usfm;
      editor_html2usfm.load (output_html);
      editor_html2usfm.stylesheet (styles_logic_standard_sheet ());
      editor_html2usfm.quill ();
      editor_html2usfm.run ();
      string output_usfm = editor_html2usfm.get ();
      evaluate (__LINE__, __func__, standard_usfm, output_usfm);
    }
  }
  // Testing \xt and \add markup in a footnote, in Romans 2.15, received from a user.
  {
    string standard_usfm = "\\p \\f + \\fr 2:15 \\ft „tokie“ – t. „kurie“\\f*tokie parodo savo širdyse įrašytą įstatymo \\f + \\fr 2:15 \\ft „darbą“ – arba „poveikį“\\f*darbą, jų sąžinei kartu \\add tiems dalykams\\add* paliudijant, ir \\add jų\\add* mintims \\f + \\fr 2:15 \\ft „tuo tarpu \\add juos\\add* kaltinant arba net ginant“ – gr. „tarp savęs“; gal „tarpusavyje“, t. y. arba minčių tarpusavyje arba kitataučių tarpusavyje; gal „pakeičiant viena kitą \\add juos\\add* kaltindamos arba net gindamos“; žr. - \\xt Mt 18:15, kur kalbama ne apie laiko tarpsnį, bet apie žodžių keitimąsi tarp du žmones\\f*tuo tarpu \\add juos\\add* kaltinant arba net ginant) –";
    {
      // DOM-based editor.
      string standard_html = "<p class=\"p\"><a href=\"#note1\" id=\"citation1\" style=\"text-decoration:none; color: inherit;\" class=\"superscript\">1</a><span>tokie parodo savo širdyse įrašytą įstatymo </span><a href=\"#note2\" id=\"citation2\" style=\"text-decoration:none; color: inherit;\" class=\"superscript\">2</a><span>darbą, jų sąžinei kartu </span><span class=\"add\">tiems dalykams</span><span> paliudijant, ir </span><span class=\"add\">jų</span><span> mintims </span><a href=\"#note3\" id=\"citation3\" style=\"text-decoration:none; color: inherit;\" class=\"superscript\">3</a><span>tuo tarpu </span><span class=\"add\">juos</span><span> kaltinant arba net ginant) –</span></p><div id=\"notes\"><hr /><p class=\"f\"><a href=\"#citation1\" id=\"note1\" style=\"text-decoration:none; color: inherit;\">1</a><span> </span><span>+ </span><span class=\"fr\">2:15 </span><span class=\"ft\">„tokie“ – t. „kurie“</span></p><p class=\"f\"><a href=\"#citation2\" id=\"note2\" style=\"text-decoration:none; color: inherit;\">2</a><span> </span><span>+ </span><span class=\"fr\">2:15 </span><span class=\"ft\">„darbą“ – arba „poveikį“</span></p><p class=\"f\"><a href=\"#citation3\" id=\"note3\" style=\"text-decoration:none; color: inherit;\">3</a><span> </span><span>+ </span><span class=\"fr\">2:15 </span><span class=\"ft\">„tuo tarpu </span><span class=\"add\">juos</span><span> kaltinant arba net ginant“ – gr. „tarp savęs“; gal „tarpusavyje“, t. y. arba minčių tarpusavyje arba kitataučių tarpusavyje; gal „pakeičiant viena kitą </span><span class=\"add\">juos</span><span> kaltindamos arba net gindamos“; žr. - </span><span class=\"xt\">Mt 18:15, kur kalbama ne apie laiko tarpsnį, bet apie žodžių keitimąsi tarp du žmones</span></p></div>";
      Editor_Usfm2Html editor_usfm2html;
      editor_usfm2html.load (standard_usfm);
      editor_usfm2html.stylesheet (styles_logic_standard_sheet ());
      editor_usfm2html.run ();
      string output_html = editor_usfm2html.get ();
      evaluate (__LINE__, __func__, standard_html, output_html);
      
      Editor_Html2Usfm editor_html2usfm;
      editor_html2usfm.load (output_html);
      editor_html2usfm.stylesheet (styles_logic_standard_sheet ());
      editor_html2usfm.run ();
      string output_usfm = editor_html2usfm.get ();
      evaluate (__LINE__, __func__, standard_usfm, output_usfm);
    }
    {
      // Quill-based editor.
      string standard_html = "<p class=\"b-p\"><span class=\"i-notecall1\">1</span><span>tokie parodo savo širdyse įrašytą įstatymo </span><span class=\"i-notecall2\">2</span><span>darbą, jų sąžinei kartu </span><span class=\"i-add\">tiems dalykams</span><span> paliudijant, ir </span><span class=\"i-add\">jų</span><span> mintims </span><span class=\"i-notecall3\">3</span><span>tuo tarpu </span><span class=\"i-add\">juos</span><span> kaltinant arba net ginant) –</span></p><p class=\"b-notes\"><br /></p><p class=\"b-f\"><span class=\"i-notebody1\">1</span><span> </span><span>+ </span><span class=\"i-fr\">2:15 </span><span class=\"i-ft\">„tokie“ – t. „kurie“</span></p><p class=\"b-f\"><span class=\"i-notebody2\">2</span><span> </span><span>+ </span><span class=\"i-fr\">2:15 </span><span class=\"i-ft\">„darbą“ – arba „poveikį“</span></p><p class=\"b-f\"><span class=\"i-notebody3\">3</span><span> </span><span>+ </span><span class=\"i-fr\">2:15 </span><span class=\"i-ft\">„tuo tarpu </span><span class=\"i-add\">juos</span><span> kaltinant arba net ginant“ – gr. „tarp savęs“; gal „tarpusavyje“, t. y. arba minčių tarpusavyje arba kitataučių tarpusavyje; gal „pakeičiant viena kitą </span><span class=\"i-add\">juos</span><span> kaltindamos arba net gindamos“; žr. - </span><span class=\"i-xt\">Mt 18:15, kur kalbama ne apie laiko tarpsnį, bet apie žodžių keitimąsi tarp du žmones</span></p>";
      Editor_Usfm2Html editor_usfm2html;
      editor_usfm2html.load (standard_usfm);
      editor_usfm2html.stylesheet (styles_logic_standard_sheet ());
      editor_usfm2html.quill ();
      editor_usfm2html.run ();
      string output_html = editor_usfm2html.get ();
      evaluate (__LINE__, __func__, standard_html, output_html);
      
      Editor_Html2Usfm editor_html2usfm;
      editor_html2usfm.load (output_html);
      editor_html2usfm.stylesheet (styles_logic_standard_sheet ());
      editor_html2usfm.quill ();
      editor_html2usfm.run ();
      string output_usfm = editor_html2usfm.get ();
      evaluate (__LINE__, __func__, standard_usfm, output_usfm);
    }
  }
  refresh_sandbox (false);
}
