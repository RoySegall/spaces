<?php

/**
 * @file
 * Spaces user context determine.
 */
$plugin = array(
  'title' => t('User'),
  'description' => t('Determine the context by the user path.'),
  'determine_function' => 'spaces_context_determine_user',
);

/**
 * Determine the context by the user.
 *
 * @return
 *  Array holds the entity type and the entity id.
 */
function spaces_context_determine_user() {
  if (!$account = menu_get_object('user')) {
    return;
  }
  return array('user' => array($account->uid));
}
