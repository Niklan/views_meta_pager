<?php
/**
 * @file
 * Contains plugin class.
 */

/**
 * The plugin.
 *
 * @ingroup views_display_plugins
 */
class views_meta_pager_plugin extends views_plugin_display_extender {

  /**
   * Provide a form to edit options for this plugin.
   */
  function option_definition() {
    $options = parent::option_definition();
    $options['views_meta_pager_enabled'] = array('default' => 1);
    return $options;
  }

  /**
   * Provide the default summary for options in the views UI.
   * This output is returned as an array.
   */
  function options_summary(&$categories, &$options) {
    $enabled = $this->display->get_option('views_meta_pager_enabled');
    $options['views_meta_pager'] = array(
      'category' => 'pager',
      'title' => 'Metatag pager',
      'value' => $enabled ? 'Enable' : 'Disable',
    );
  }

  /**
   * Defines the form.
   */
  function options_form(&$form, &$form_state) {
    if ($form_state['section'] == 'views_meta_pager') {
      $form['#title'] .= 'Settings for metatag pager';

      $form['enable'] = array(
        '#type' => 'checkbox',
        '#title' => 'Enable',
        '#description' => 'Adds rel="next" and rel="prev" to head according to the pager.',
        '#default_value' => $this->display->get_option('views_meta_pager_enabled'),
      );
    }
  }

  /**
   * Saves the form values.
   */
  function options_submit(&$form, &$form_state) {
    if ($form_state['section'] == 'views_meta_pager') {
      $values = $form_state['values'];

      $this->display->set_option('views_meta_pager_enabled', $values['enable']);
    }
  }

}
