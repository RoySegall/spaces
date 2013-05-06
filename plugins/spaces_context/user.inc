<?php

/**
 * @file
 * Spaces user context determine.
 */
$plugin = array(
  'title' => t('User'),
  'description' => t('Determine the context by the user path.'),
  'path' => array('user/%', 'user'),
  'determine_function' => 'spaces_context_determine_user',
);

/**
 * Determine the context by the node menu item.
 *
 * @param $path
 *  The path to determine the context.
 *
 * @return
 *  Array holds the entity type and the entity id.
 */
function spaces_context_determine_user($item) {
  return array($item['map']);
}
