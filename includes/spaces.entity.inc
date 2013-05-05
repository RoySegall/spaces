<?php

/**
 * @file
 * The file holds the spaces app entity class.
 */

class Space extends Entity {

  /**
   * @var int
   * The space ID.
   */
  var $id = 0;

  /**
   * @var string
   * The title of the space
   */
  var $title = '';

  /**
   * @var string
   * The type of the space.
   */
  var $type = 'space';

  /**
   * @var bool
   * Determine if this is a global.
   */
  var $global = FALSE;

  /**
   * @var int
   * The parent space ID for extending the settings.
   */
  var $parent_space = 0;

  /**
   * @var array
   * Holds the space settings.
   */
  var $settings = array();

  /**
   * @var bool
   * Determine if the space is disabled(0), enabled(1) or private(2).
   */
  var $status = FALSE;

  /**
   * @var int
   * The entity ID the space is referenced to.
   */
  var $entity_id = 0;

  /**
   * @var string
   * The entity type (e.g. node, comment, etc') the space is referenced to.
   */
  var $entity_type = 'node';

  /**
   * Get the settings for a specific app.
   *
   * @param $id
   *  The parent space ID.
   * @return
   *  The nested value of the settings.
   */
  function getSettings($id = NULL) {
    if ($id) {
      // Load the parent space settings and merge them with the current one.
      $parent_space = spaces_load($id);
      $this->settings = drupal_array_merge_deep($this->settings, $parent_space->settings);

      if ($parent_space->parent_space) {
        // Getting the parent space settings.
        $this->getSettings($parent_space->parent_space);
      }
    }

    // First time we entered this function, load the parent settings
    // recursively.
    if (!$id && $this->parent_space) {
      $this->getSettings($this->parent_space);
    }

    return $this->settings;
  }
}
