<?php

/**
 * Diese Fuktion gibt die Map-Seite formatiert zurück
 */
function _dossiersearch_page($query='') {
  //include_once('functions.inc');
  //include_once('elements.inc');
  
  $dsPath = drupal_get_path('module', 'dossiersearch');
  //$prPath = drupal_get_path('module', 'previews'     );
  //if (variable_get('dossiersearch_filterlocation', false)) {
    drupal_set_html_head('<script src="'. check_url('http://maps.google.com/maps/api/js?sensor=false') .'" type="text/javascript"></script>');
  //}
  drupal_add_js ($dsPath.'/jquery.ui/js/jquery-ui-1.8.10.custom.min.js', 'core', 'footer');
  drupal_add_css($dsPath.'/jquery.ui/css/ui-lightness/jquery-ui-1.8.7.custom.css', 'core');
  drupal_add_js ($dsPath.'/map.js' , 'module', 'footer');
  drupal_add_css($dsPath.'/map.css', 'module');

  return
    '<div id="map_content">'.
      '<div id="map_map"></div>'.
      '<div id="map_utils"></div>'.
    '</div>';
}