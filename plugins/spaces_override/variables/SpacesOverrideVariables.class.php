<?php

/**
 * @file
 * Spaces override for Drupal core variables (i.e. global $conf).
 */

class SpacesOverrideVariables extends SpacesOverrideBase {

  public function get($key, $default_value = NULL) {
    if (!empty($this->space->settings[$key])) {
      return $this->space->settings['variables'][$key];
    }

    return variable_get($key, $default_value);
  }

  public function set($key, $value) {
    $this->space->settings['variables'][$key] = $value;

  }

  public function override() {
    global $conf;
    $conf = drupal_array_merge_deep($conf, $this->space->settings['variables']);
  }

}
