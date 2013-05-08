<?php

/**
 * @file
 * Spaces override for Drupal core variables (i.e. global $conf).
 */

class SpacesOverrideVariables extends SpacesOverrideBase {

  public function get($key, $default_value = NULL) {
    if ($value = parent::get($key, NULL)) {
      return $value;
    }

    return variable_get($key, $default_value);
  }

  public function override(&$data = NULL) {
    global $conf;
    $conf = drupal_array_merge_deep($conf, $this->space->settings['variables']);
  }

}
