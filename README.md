#ucsf_utility_scripts

The Utitlity Scripts are primaryly useful if you are on Acquia Cloud hosting. Posting on Github so that other Acquia clients can use and collaborate on the scripts. These are provided as is with no support. That being said, we are happy to collaborate with other groups, particularly other Higher Ed and Non-profits.

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

Module Madness is a reporting script. It let's you know which site is running which module. Useful when managing 500+ sites!


##Site Builder

This script uses the Acquia API and git to quickly build empty site document roots based on an orginal site called mysite.ucsf.edu

##Sync files 

This script allow for more fine grained file updates between sites than the current Acquia workflow tool. Very useful when migrating a new site from Dev to Test and then Produciton.
