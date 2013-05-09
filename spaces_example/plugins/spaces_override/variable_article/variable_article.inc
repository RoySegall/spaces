<?php

$plugin = array(
  'title' => t('Variables'),
  'description' => t('Spaces override for Drupal core variables (i.e. global $conf).'),
  'class' => 'SpacesOverrideVariableArticle',
  'options' => array(
    'settings_key' => 'variable',
  ),
  'type' => 'variable',
);