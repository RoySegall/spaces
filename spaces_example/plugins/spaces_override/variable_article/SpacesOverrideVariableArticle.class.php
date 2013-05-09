<?php

/**
 * @file
 * Example for Spaces override for Drupal core variables (i.e. global $conf) of
 * "Article" node type.
 */

class SpacesOverrideVariableArticle extends SpacesOverrideVariable {

  public function form($form, &$form_state) {
    $settings_key = $this->plugin['options']['settings_key'];
    $settings = !empty($this->space->settings[$settings_key]) ? $this->space->settings[$settings_key] : array();

    // Add default values.
    $settings += array(
      'site_name' => '',
    );

    $form['site_name'] = array(
      '#title' => t('Site name'),
      '#description' => t('Override the site name.'),
      '#type' => 'textfield',
      '#default_value' => $settings['site_name'],
    );
    return $form;
  }

  public function formValidate($form, &$form_state) {}


  public function formSubmit($form, &$form_state) {
    $settings_key = $this->plugin['options']['settings_key'];

    // @todo: Iterate over options_defintions().
    $this->space->settings[$settings_key]['site_name'] = $form_state['values']['site_name'];
  }

}
