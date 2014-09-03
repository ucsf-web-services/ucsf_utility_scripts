#ucsf_utility_scripts


##Iterator Script:
Iterator Script runs through drupal sites and runs drush based on file added to "deploy folder". Can also be run via command line.
###Example file command:
<pre>
quiet|ucsftemplate_tweaks
status|ucsf_pharmacy_images
</pre>

The first would run a mininmal update on all sites with the ucsftemplate tweaks module enabled.
The second would run status on all sites with the ucsf pharmacy image module.


##Module Madness

Module Madness is a reporting script


##Site Builder

This script uses the Acquia API and git to quickly build empty site document roots based on an orginal site called mysite.ucsf.edu

