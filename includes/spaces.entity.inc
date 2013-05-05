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
   * Determine if this is a global app.
   */
  var $global = FALSE;

  /**
   * @var int
   * The parent space app ID for extending the app settings.
   */
  var $parent_space = 0;

  /**
   * @var int
   * The entity ID the app space is referenced to.
   */
  var $entity_id = 0;

  /**
   * @var string
   * The entity type (e.g. node, comment, etc') the app space is referenced to.
   */
  var $entity_type = 'node';

  /**
   * @var array
   * Holds the space settings.
   */
  var $settings = array();

  /**
   * @var
   * Determine if the space app is private.
   */
  var $private;

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
