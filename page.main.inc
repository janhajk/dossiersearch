<?php

/**
 * Diese Fuktion gibt die Dossier-Seite formatiert zurück
 */
function _dossiersearch_page($query='') {
  include_once('functions.inc');
  include_once('elements.inc');
  
  $dsPath = drupal_get_path('module', 'dossiersearch');
  $prPath = drupal_get_path('module', 'previews'     );
  //if (variable_get('dossiersearch_filterlocation', false)) {
    drupal_set_html_head('<script src="'. check_url('http://maps.google.com/maps/api/js?sensor=false') .'" type="text/javascript"></script>');
  //}
  drupal_add_js ($dsPath.'/jquery.ui/js/jquery-ui-1.8.10.custom.min.js', 'core', 'footer');
  drupal_add_css($dsPath.'/jquery.ui/css/ui-lightness/jquery-ui-1.8.7.custom.css', 'core');
  drupal_add_js ($dsPath.'/dossiersearch.js' , 'module', 'footer');
  drupal_add_css($dsPath.'/dossiersearch.css', 'module');
  drupal_add_js ($prPath.'/docviewer.js'     , 'module', 'footer');
  drupal_add_css($prPath.'/docviewer.css'    , 'module');
  drupal_add_js (_dossiersearch_getJsSettings(), 'setting');

  return
    '<div id="dossiersearch_export"><a href="javascript:"><img src="/'.$dsPath. '/images/csv.gif'.'" width="40" height="16" /></a></div>'.
    '<div id="dossiersearch_filters">'._dossiersearch_getFilters($query).'</div>'.
    '<div id="dossiersearch_results">'.
      '<div id="dossiersearch_view"><img src="/'.$dsPath. '/images/view_Normal.png'.'" width="42" height="18" dossiersearch_view="Normal" /></div>'.
      '<div id="dossiersearch_results_count"></div>'.
      '<table id="dossiersearch_results_table">'.
        '<thead id="dossiersearch_results_head"></thead>'.
        '<tbody id="dossiersearch_results_body"></tbody>'.
      '</table>'.
    '</div>';
}