<?php
// $Id:

/**
 * Declares administrative settings for the module.
 */
function dossiersearch_admin_settings() {
  $form['gmap'] = array(
    '#type' => 'fieldset',
    '#title' => t('Google Maps'),
    '#collapsible' => TRUE,
    '#collapsed' => FALSE,
    '#description' => t('Google Maps Einstellungen')
  );
  $form['gmap']['dossiersearch_filterlocation'] = array(
    '#type'          => 'checkbox',
    '#title'         => t('Möglichkeit geben, nach Location zu Filtern'),
    '#default_value' => variable_get('dossiersearch_filterlocation', false),
    '#description'   => t('Das Locations Modul muss dazu installiert sein'),
  );
  $form['gmap']['dossiersearch_center_title'] = array(
    '#type'          => 'textfield',
    '#title'         => t('Google Maps Zentrum Title'),
    '#default_value' => variable_get('dossiersearch_center_title', 'Basel'),
    '#size'          => 20,
    '#description'   => t(''),
  );
  $form['gmap']['dossiersearch_center_latitude'] = array(
    '#type'          => 'textfield',
    '#title'         => t('Google Maps Zentrum Latitude'),
    '#default_value' => variable_get('dossiersearch_center_latitude', '47.54443828985943'),
    '#size'          => 20,
    '#description'   => t(''),
  );
  $form['gmap']['dossiersearch_center_longitude'] = array(
    '#type'          => 'textfield',
    '#title'         => t('Google Maps Zentrum Longitude'),
    '#default_value' => variable_get('dossiersearch_center_longitude', '7.596015930175781'),
    '#size'          => 20,
    '#description'   => t(''),
  );
  $form['gmap']['dossiersearch_project'] = array(
    '#type'          => 'textarea',
    '#title'         => t('Projektgebiet'),
    '#default_value' => variable_get('dossiersearch_project', 0),
    '#cols'          => 60,
    '#rows'          => 5,
    '#description'   => t('Pro Zeile eine Koordinate (Lat/Lng), Kommagetrennt'),
  );
  $form['gmap']['dossiersearch_showmap'] = array(
    '#type'          => 'checkbox',
    '#title'         => t('Google Maps anzeigen'),
    '#default_value' => variable_get('dossiersearch_showmap', false),
    '#description'   => t('In Dossiersuche Google Maps per default einblenden'),
  );
  return system_settings_form($form);
}