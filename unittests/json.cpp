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


#include <unittests/json.h>
#include <unittests/utilities.h>
#include <jsonxx/jsonxx.h>
#include <filter/url.h>


using namespace jsonxx;


// Test included JSON libraries.
void test_json ()
{
  trace_unit_tests (__func__);
  {
    // Convert JSON to xml.
    string json ("{"
                 "  \"foo\" : 1,"
                 "  \"bar\" : false,"
                 "  \"person\" : {\"name\" : \"GWB\", \"age\" : 60,},"
                 "  \"data\": [\"abcd\", 42],"
                 "}");
    Object object;
    object.parse (json);
    string path = filter_url_create_root_path ("unittests", "tests", "jsonxx.txt");
    string xml = filter_url_file_get_contents (path);
    evaluate (__LINE__, __func__, xml, object.xml (JSONx));
  }
  {
    // Test malformed JSON.
    string json ("{"
                 "  \"foo\" 1,"
                 "  \"bar : false,"
                 "  \"person\" : me\" : \"GWB\", \"age\" : 60,},"
                 "  \"data\": \"abcd\", 42],"
                 );
    Object object;
    object.parse (json);
    evaluate (__LINE__, __func__, "{\n} \n", object.json ());
  }
}
