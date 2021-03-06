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


#include <changes/logic.h>
#include <changes/changes.h>
#include <changes/statistics.h>
#include <changes/manage.h>
#include <tasks/logic.h>
#include <pugixml/pugixml.hpp>
#include <locale/translate.h>
#include <index/listing.h>
#include <database/logs.h>
#include <database/modifications.h>
#include <database/jobs.h>
#include <filter/string.h>
#include <webserver/request.h>


using namespace pugi;


void changes_logic_start ()
{
  tasks_logic_queue (GENERATECHANGES);
}


const char * changes_personal_category ()
{
  return "P";
}


const char * changes_bible_category ()
{
  return "B";
}


string changes_interlinks (void * webserver_request, string my_url)
{
  // The available links.
  vector <string> urls;
  vector <string> labels;
  if (changes_changes_acl (webserver_request)) {
    urls.push_back (changes_changes_url ());
    labels.push_back (translate ("View"));
  }
#ifndef HAVE_CLIENT
  if (changes_statistics_acl (webserver_request)) {
    urls.push_back (changes_statistics_url ());
    labels.push_back (translate ("Statistics"));
  }
  if (index_listing_acl (webserver_request, "revisions")) {
    urls.push_back (index_listing_url ("revisions"));
    labels.push_back (translate ("Download"));
  }
  if (changes_manage_acl (webserver_request)) {
    urls.push_back (changes_manage_url ());
    labels.push_back (translate ("Manage"));
  }
#endif

  // Generate the links in XML.
  xml_document document;
  bool first = true;
  for (unsigned int i = 0; i < urls.size (); i++) {
    if (urls[i] == my_url) continue;
    if (!first) {
      xml_node node = document.append_child ("span");
      node.text ().set (" | ");
    }
    first = false;
    xml_node a = document.append_child ("a");
    string href = "/" + urls[i];
    a.append_attribute ("href") = href.c_str();
    a.text ().set (labels[i].c_str());
  }
  
  // Convert the document to a string.
  stringstream output;
  document.print (output, "", format_raw);
  return output.str ();
}


void changes_clear_notifications_user (string jobid, string username)
{
  Database_Logs::log (translate ("Start clearing change notifications") + " " + username);
  
  Database_Modifications database_modifications;
  Database_Jobs database_jobs;

  // Get the total amount of change notifications to clear for the user.
  vector <int> identifiers = database_modifications.getNotificationIdentifiers (username);
  
  // Total notes cleared.
  int total_cleared = 0;
  
  // Feedback.
  database_jobs.setPercentage (convert_to_int (jobid), 0);
  database_jobs.setProgress (convert_to_int (jobid), translate ("Total:") + " " + convert_to_string (identifiers.size()));


  // The amount of notifications it clears in the next iteration.
  int cleared_count_in_one_go = 0;
  do {
    cleared_count_in_one_go = database_modifications.clearNotificationsUser (username);
    total_cleared += cleared_count_in_one_go;
    if (!identifiers.empty ()) {
      database_jobs.setPercentage (convert_to_int (jobid), 100 * total_cleared / identifiers.size());
    }
  } while (cleared_count_in_one_go);
  
  Webserver_Request request;
  request.database_config_user ()->setUserChangeNotificationsChecksum (username, "");
  
  database_jobs.setResult (convert_to_int (jobid), translate ("Ready clearing change notifications"));
  
  Database_Logs::log (translate ("Ready clearing change notifications") + " " + username);
}
