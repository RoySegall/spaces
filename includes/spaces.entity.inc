<?php

/**
 * @file
 * The file holds the spaces app entity class.
 */

class SpaceApp extends Entity {

  var $global = FALSE;
  var $parent_space = 0;
  var $entity_id = 0;
  var $entity_type = 'node';

  /**
   * Overriding save().
   */
  public function save() {
    parent::save();
  }
}
