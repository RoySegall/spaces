<?php

/**
 * @file
 * Spaces og context determine.
 */
if (module_exists('og_context')) {
  $plugin = array(
    'title' => t('OG context'),
    'description' => t('Determine the path by OG context.'),
    'path' => array(),
    'determine_function' => 'spaces_context_determine_og_context',
  );
}

function spaces_context_determine_og_context() {
  if ($og_context = og_context()) {
    return array($og_context['group_type'], array($og_context['gid']));
  }
}
