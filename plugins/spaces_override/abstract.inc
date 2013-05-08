<?php

/**
 * Spaces override interface
 *
 */
interface SpacesOverrideInterface {

  /**
   * Constructor for the space  override.
   *
   * @param $plugin
   *   The plugin object.
   * @param Space $space
   *   The Space entity.
   */
  public function __construct($plugin, Space $space);


  /**
   * Get a value.
   *
   * @param $key
   *   The value to get.
   * $param $default_value
   *   Optional; The default value to assign if none found.
   */
  public function get($key, $default_value = NULL);

  /**
   * Set a value.
   *
   * @param $key
   *   The value to get.
   * $param $default_value
   *   Optional; The value to set.
   */
  public function set($key, $value);

  /**
   * Perform the overriding.
   */
  public function override();
}

/**
 * An abstract implementation of MessageNotifierInterface.
 */
abstract class SpacesOverrideBase implements SpacesOverrideInterface {

  /**
   * The plugin definition.
   */
  protected $plugin;

  /**
   * The Space entity.
   */
  protected $space;

  public function __construct($plugin, Space $space) {
    $this->plugin = $plugin;
    $this->space = $space;
  }

  public function get($key, $default_value = NULL) {}
  public function set($key, $value) {}
  public function override() {}
}
