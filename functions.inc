<?php

/**
 * UID -> Username conversion
 * @param integer $uid Eine Drupal User-ID
 * @return string Benutzername
 */
function _dossiersearch_uid2username($uid) {
  $sql = "SELECT {users}.name FROM ({users}, {node} n) WHERE {users}.uid = '%d'";
  $result = db_query(db_rewrite_sql($sql), $uid);
  return db_fetch_object($result)->name;
}

/**
 * Nimmt den aktuellen Tag und gibt den den UNIX-Timestamp
 * von 23:59:59 des Tages zurück.
 * @return UNIX-timestamp
 */
function _dossiersearch_midnight() {
  return mktime(0,0,0,date('n'),date('j')+1,date('Y'));
}

/**
 * Findet das Datum des ältesten Dossiers in der Ablage
 * @return integer timestamp des ältesten Dossiers
 */
function _dossiersearch_oldestDocument() {
  // Cache oldest Document
  static $oDate = false;
  if ($oDate) return $oDate;

  $sql = "SELECT created FROM {node} WHERE type LIKE 'dossier' ORDER BY created ASC LIMIT 0,1";
  $result = db_query($sql);
  $date1 = db_fetch_object($result)->created;
  $date1 = mktime(0,0,0,date('n',$date1),date('j',$date1),date('Y',$date1));

  $sql = "SELECT field_dokumentendatum_value FROM {content_type_dossier} ORDER BY field_dokumentendatum_value ASC LIMIT 0,1";
  $result = db_query($sql);
  $date2 = strtotime(db_fetch_object($result)->field_dokumentendatum_value);
  $date2 = mktime(0,0,0,date('n',$date2),date('j',$date2),date('Y',$date2));

  $oDate = ($date1<$date2)?$date1:$date2; // write to static cache
  return $oDate;
}

/**
 * Checks if data URI is supported
 * @return boolean returns true if data-URI is supported
 * false if not supported (IE<8)
 */
function _dossiersearch_dataUriSupport() {
  return !preg_match('/(?i)msie [1-7]/',$_SERVER['HTTP_USER_AGENT']);
}


/**
 * Gibt HTML-Code für die Gruppen-Anzeige zurück
 * @param array $groups Array mit Gruppen-Titel zB 'Gruner AG'
 * @return string Kommagetrennte Liste mit Gruppen-Icon und wenn
 * nicht vorhanden mit Gruppenname
 */
function _dossiersearch_getGroupIcons($groups) {
  static $imgs = array();
  $g = array();
  foreach ($groups as $group) {
    if (is_array($group)) { $group = $group['title']; }
    $imgpath = path_to_theme().'/custom/icons_og/'.preg_replace('/[^a-z]/msi','',strtolower($group)).'.png';
    if(file_exists($imgpath)){
      if (!isset($imgs[$imgpath])) {
        $imgs[$imgpath] = array('content' => file_get_contents($imgpath),
                                'info'    => getimagesize($imgpath));
      }
      $src = _dossiersearch_dataUriSupport()?'data:image/jpeg;base64,'.chunk_split(base64_encode($imgs[$imgpath]['content'])):($imgpath);
      $g[] = '<img src="'.$src.
             '" '.$imgs[$imgpath]['info'][3].' title="'.$group.'" />';
    }
    else { $g[] = $group; } // es existiert kein Bild
  }
  return implode(', ', $g);
}


