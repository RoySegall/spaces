<?php

/**
 * @file
 * The file holds the spaces app entity class.
 */

class Space extends Entity {

  var $id = 0;
  var $title = '';
  var $type = 'space';
  var $global = FALSE;
  var $parent_space = 0;
  var $entity_id = 0;
  var $entity_type = 'node';
  var $settings = array();

  /**
   * Get the settings for a specific app.
   */
  function getParentSettings($id = NULL) {
    if ($id) {
      // Load the parent space settings and merge them with the current one.
      $parent_space = spaces_load($id);
      $this->settings = drupal_array_merge_deep($this->settings, $parent_space->settings);

      if ($parent_space->parent_space) {
        // Getting the parent space settings.
        $this->getParentSettings($parent_space->parent_space);
      }
    }

    // First time we entered this function, load the parent settings recursively.
    if (!$id && $this->parent_space) {
      $this->getParentSettings($this->parent_space);
    }

    return $this->settings;
  }
}
