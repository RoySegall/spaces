<?php

/**
 * @file
 * Spaces override for Context module.
 */

class SpacesOverrideContext extends SpacesOverrideBase {

  public function override(&$data = NULL) {
    foreach (array_keys(context_reactions()) as $plugin) {
      if ($override = $this->get("{$data->name}:reaction:{$plugin}")) {
        $data->reactions[$plugin] = $override;
      }
    }
  }
}
