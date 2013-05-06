<?php

/**
 * @file
 * Spaces node context determine.
 */
$plugin = array(
  'title' => t('Node'),
  'description' => t('Determine the path by of the node.'),
  'path' => array('node/%'),
  'determine_function' => 'spaces_context_determine_node',
);

/**
 * Determine the context by the node menu item.
 *
 * @param $item
 *  The path to determine the context.
 *
 * @return
 *  Array holds the entity type and the entity id.
 */
function spaces_context_determine_node($item) {
  return array($item['map']);
}
