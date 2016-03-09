<?php
/**
 * @file
 * zwolfs_test_task_feature.pages_default.inc
 */

/**
 * Implements hook_default_page_manager_pages().
 */
function zwolfs_test_task_feature_default_page_manager_pages() {
  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'zwolfs_test_page';
  $page->task = 'page';
  $page->admin_title = 'Zwolfs test page';
  $page->admin_description = 'Zwolfs test page';
  $page->path = 'test2';
  $page->access = array();
  $page->menu = array();
  $page->arguments = array();
  $page->conf = array(
    'admin_paths' => FALSE,
  );
  $page->default_handlers = array();
  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_zwolfs_test_page__panel';
  $handler->task = 'page';
  $handler->subtask = 'zwolfs_test_page';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'Zwolfs panel',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
    'name' => 'panel',
  );
  $display = new panels_display();
  $display->layout = 'onecol';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'middle' => array(
        'css_border' => '10px solid green',
      ),
    ),
    'middle' => array(
      'style' => 'zwolfs_pane',
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = '8da9850a-674b-4b52-9d58-6e25f4d2a297';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-d7cb1bc0-427e-409c-8057-6daddd944d4e';
    $pane->panel = 'middle';
    $pane->type = 'test_content_type';
    $pane->subtype = 'test_content_type';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'buttons' => NULL,
      'aligner_start' => NULL,
      'override_title' => 0,
      'override_title_text' => '',
      'override_title_heading' => 'h2',
      'aligner_stop' => NULL,
      'override_title_markup' => NULL,
      'view_mode' => 'teaser',
      'node_number' => '2',
      'form_build_id' => 'form-MIwwrUOtcvtcUlfG_9Z4QGa5JdDFIQBkYjBjoQI6k8s',
      'form_token' => 'cOuAGG81bjoAk6zIlTeAOAmZljnV8hUwrEMBNKEGZgs',
      'form_id' => 'test_content_type_edit_form',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => array(
        'css_border' => '2px solid blue',
      ),
      'style' => 'zwolfs_pane',
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = 'd7cb1bc0-427e-409c-8057-6daddd944d4e';
    $display->content['new-d7cb1bc0-427e-409c-8057-6daddd944d4e'] = $pane;
    $display->panels['middle'][0] = 'new-d7cb1bc0-427e-409c-8057-6daddd944d4e';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['zwolfs_test_page'] = $page;

  return $pages;

}
