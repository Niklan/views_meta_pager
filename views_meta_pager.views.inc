<?php

/**
 * @file
 * Views hooks.
 */

/**
 * Implements hook_views_plugins().
 */
function views_meta_pager_views_plugins() {
  $plugins['display_extender']['meta_pager'] = array(
    'title' => 'Meta pager',
    'help' => 'Add metatags with rel next\page according to the views pager.',
    'path' => drupal_get_path('module', 'views_meta_pager'),
    'handler' => 'views_meta_pager_plugin',
    'enabled' => TRUE,
  );

  return $plugins;
}
