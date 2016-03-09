<?php

/**
 * @file
 * Zwolfs ctools content type.
 */

/**
 * Plugins are described by a $plugin array.
 */
$plugin = array(
  'title' => t('Zwolfs test content type'),
  'content_types' => 'test_content_type',
  'single' => TRUE,
  'render callback' => 'test_content_type_render',
  'icon' => 'zw.png',
  'description' => t('Content type for test task of the Zwolfs team.'),
  'edit form' => 'test_content_type_edit_form',
  'admin title' => 'zwolfs_test_content_type',
  'category' => array(t('Zwolfs'), -9),
);


/**
 * 'Edit' callback for the content type.
 *
 * @param $form
 *   Form array.
 * @param $form_state
 *   Form state array.
 *
 * @return array
 *   Form array.
 */
function test_content_type_edit_form($form, &$form_state) {
  $conf = $form_state['conf'];
  $form['view_mode'] = array(
    '#type' => 'textfield',
    '#title' => t('View mode'),
    '#required' => TRUE,
    '#size' => 50,
    '#description' => t('Select a view mode.'),
    '#default_value' => !empty($conf['view_mode']) ? $conf['view_mode'] : 'teaser',
    '#prefix' => '<div class="clear-block no-float">',
    '#suffix' => '</div>',
  );

  $form['node_number'] = array(
    '#type' => 'select',
    '#title' => t('Number of nodes to display'),
    '#options' => array(1 => 1, 2, 3, 4, 5, 6, 7, 8, 9, 10),
    '#description' => t('Select number of nodes to show.'),
    '#default_value' => !empty($conf['node_number']) ? $conf['node_number'] : 3,
    '#prefix' => '<div class="clear-block no-float">',
    '#suffix' => '</div>',
  );

  return $form;
}

/**
 * Ctools edit form submit handler.
 *
 * @param $form
 *   Form array.
 * @param $form_state
 *   Form state array.
 */
function test_content_type_edit_form_submit($form, &$form_state) {
  foreach (element_children($form) as $key) {
    $form_state['conf'][$key] = $form_state['values'][$key];
  }
}

/**
 * Render callback.
 *
 * @param string $subtype
 *   Sub type.
 * @param array $conf
 *   Configuration.
 * @param array $args
 *
 * @return object
 *   An object with at least title and content members.
 */
function test_content_type_render($subtype, $conf, $args) {
  $mode = !empty($conf['view_mode']) ? $conf['view_mode'] : 'teaser';
  $view = array();
  $block = new stdClass();
  $query = db_select('node', 'n')
    ->fields('n', array('nid'))
    ->condition('n.status', NODE_PUBLISHED)
    ->orderBy('RAND()')
    ->range(0, $conf['node_number'] ? $conf['node_number'] : 3);
  $query = $query->execute();
  $results = $query->fetchCol();
  if (!empty($results)) {
    $nodes = node_load_multiple($results);
    $view = node_view_multiple($nodes, $mode);
  }
  $block->title = check_plain("Zwolfs test content type");
  $block->content = drupal_render($view);
  return $block;
}
