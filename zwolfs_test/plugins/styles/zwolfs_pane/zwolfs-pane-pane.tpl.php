<?php
/**
 * @file
 *
 * - $settings
 * - $content
 */
?>
<div class="test-pane padding"
     <?php if (!empty($settings['css_border'])): ?>style="border:<?php print $settings['css_border']; ?>"<?php endif; ?> >
  <?php if (isset($content->title)): ?>
    <h2
      class="pane-title"><?php print $content->title; ?></h2>
  <?php endif; ?>
  <div class="pane-content">
    <?php print render($content->content); ?>
  </div>
</div>
