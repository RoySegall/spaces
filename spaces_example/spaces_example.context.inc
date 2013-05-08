<?php
/**
 * @file
 * spaces_example.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function spaces_example_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'spaces_example';
  $context->description = '';
  $context->tag = '';
  $context->conditions = array(
    'node' => array(
      'values' => array(
        'article' => 'article',
      ),
      'options' => array(
        'node_form' => '1',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'comment-recent' => array(
          'module' => 'comment',
          'delta' => 'recent',
          'region' => 'content',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;
  $export['spaces_example'] = $context;

  return $export;
}
