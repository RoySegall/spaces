<?php

/**
 * @file
 * Spaces og context determine.
 */
$plugin = array(
  'title' => t('OG context'),
  'description' => t('Determine the path by OG context.'),
  'path' => array(),
  'determine_function' => 'spaces_context_determine_og_context',
);

function spaces_context_determine_og_context($item) {
  $og_context = og_context();
  if (empty($og_context)) {
    return array();
  }
  return array($og_context['group_type'], $og_context['gid']);
}
