<?php
/**
 * @file ucsf.drush.inc
 *
 * Drush custom commands for managing UCSF's Drupal environments.
 */

/**
 * Implements COMMANDFILE_drush_command().
 */
function ucsf_drush_command() {
  $items = array();
    $items['quiet'] = array(
      'description' => 'This does not do anything.',
    $items['modulemadness'] = array(
      'description' => 'Identifies module and theme usage across all sites in the current multi-site environment.',
      'arguments' => array(
        'output-dir' =>
          'The directory in which "modulemadness" will generate its output. Must be writable to the user invoking drush.',
      ),
      'required-arguments' => TRUE,
    ),
  );
  return $items;
}

/**
 * Implements drush_COMMANDFILE_COMMANDNAME().
 *
 * Does nothing but itself, but may be useful if run via the <code>iterator</code> script.
 */
function drush_ucsf_quiet() {}

/**
 * Implements drush_COMMANDFILE_COMMANDNAME().
 *
 * Retrieves a list of all enabled themes and modules in the current site and
 * outputs the retrieved information to the file system into the given directory.
 *
 * @param $output_dir The directory to generate the output in.
 */
function drush_ucsf_modulemadness($output_dir) {

  $output_dir = rtrim($output_dir, DIRECTORY_SEPARATOR);

  if (! is_dir($output_dir)) {
    return drush_set_error(dt('Specified output directory does not exist.'));
  }
  if (! is_writable($output_dir)) {
    return drush_set_error(dt('Specified output directory is not writable.'));
  }

  // get all enabled modules and themes in the current site context
  $extensions_info = drush_get_extensions(FALSE);

  foreach ($extensions_info as $extension) {
    // ignore uninstalled/disabled extensions
    if (drush_get_extension_status($extension) == 'enabled') {

      // output file name is the extension's name.
      $file_name = $extension->name;

      // capture the current site's URI
      $out = drush_get_option('uri');

      // Check installation location for non-core extensions.
      // If it's not in a "standard" location, e.g in a site-specific directory, then output it into
      // an <extension>.amok file and provide the extension's version information if available.
      if ($extension->info['package'] !== 'Core'
        && strpos($extension->filename, 'sites/all') !== 0
        && strpos($extension->filename, 'profiles') !== 0) {
        $file_name .= '.amok';
        if (! empty($extension->info['version'])) {
          $out .= '|' . $extension->info['version'];
        }
      }

      $out .= PHP_EOL;

      // write the site info to the extension file.
      $fp = @fopen($output_dir . '/' . $file_name, 'a');
      if (FALSE === $fp) {
        return drush_set_error('Unable to open output to file.');
      }
      if (FALSE === @fwrite($fp, $out)) {
        return drush_set_error('Unable to write output to file.');
      }
      fclose($fp);
    }
  }
}
