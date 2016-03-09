<?php
/**
 * @file
 *
 * - $settings
 * - $content
 */
?>
<div class="test-region padding" <?php if (!empty($settings['css_border'])): ?>style="border:<?php print $settings['css_border']; ?>"<?php endif; ?> >
    <?php print render($content); ?>
</div>
