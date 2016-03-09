<?php
/**
 * @file
 */

$plugin = array(
  'zwolfs_pane' => array(
    'title' => t('Zwolfs pane'),
    'description' => t('Example description'),
    'render pane' => 'zwolfs_pane_render_pane',
    'render region' => 'zwolfs_pane_render_region',
    'pane settings form' => 'zwolfs_pane_settings_form',
    'settings form' => 'zwolfs_pane_settings_form',
    'hook theme' => array(
      'zwolfs_pane_theme_pane' => array(
        'template' => 'zwolfs-pane-pane',
        'path' => drupal_get_path(
            'module',
            'zwolfs_test'
          ) . '/plugins/styles/zwolfs_pane',
        'variables' => array(
          'content' => NULL,
          'settings' => NULL,
        ),
      ),
      'zwolfs_pane_theme_region' => array(
        'template' => 'zwolfs-pane-region',
        'path' => drupal_get_path(
            'module',
            'zwolfs_test'
          ) . '/plugins/styles/zwolfs_pane',
        'variables' => array(
          'content' => NULL,
        ),
      ),
    ),
  ),
);

/**
 * Render pane callback
 *
 * @param array $vars
 *   An associative array.
 *
 * @return string
 */
function theme_zwolfs_pane_render_pane($vars) {
  $settings = $vars['settings'];
  $content = $vars['content'];
  drupal_add_css(
    drupal_get_path(
      'module',
      'zwolfs_test'
    ) . '/plugins/styles/zwolfs_pane/pane.css',
    array('group' => CSS_DEFAULT)
  );
  return theme(
    'zwolfs_pane_theme_pane',
    array('content' => $content, 'settings' => $settings)
  );
}

/**
 * Render region callback.
 *
 * @param array $vars
 *   An associative array.
 *
 * @return string
 *   Rendered region.
 */
function theme_zwolfs_pane_render_region($vars) {
  $content = '';
  foreach ($vars['panes'] as $pane_id => $pane_output) {
    $content .= $pane_output;
  }
  if (empty($content)) {
    return;
  }
  $settings = !empty($vars['settings']) ? $vars['settings'] : array();

  drupal_add_css(
    drupal_get_path(
      'module',
      'zwolfs_test'
    ) . '/plugins/styles/zwolfs_pane/zwolfs-pane.css',
    array('group' => CSS_DEFAULT)
  );
  return theme('zwolfs_pane_theme_region', array('content' => $content, 'settings' => $settings));
}

/**
 * Settings form callback.
 */
function zwolfs_pane_settings_form($style_settings) {
  $form['css_border'] = array(
    '#type' => 'textfield',
    '#title' => t('Border styles (e.g.: "2px solid blue")'),
    '#default_value' => '',
  );

  return $form;
}
