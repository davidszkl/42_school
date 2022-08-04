<?php
/**
 * The base configuration for WordPress
 *
 * The wp-config.php creation script uses this file during the installation.
 * You don't have to use the web site, you can copy this file to "wp-config.php"
 * and fill in the values.
 *
 * This file contains the following configurations:
 *
 * * Database settings
 * * Secret keys
 * * Database table prefix
 * * ABSPATH
 *
 * @link https://wordpress.org/support/article/editing-wp-config-php/
 *
 * @package WordPress
 */

// ** Database settings - You can get this info from your web host ** //
/** The name of the database for WordPress */
define( 'DB_NAME', 'wordpress_db' );

/** Database username */
define( 'DB_USER', 'wpuser' );

/** Database password */
define( 'DB_PASSWORD', 'mariadbwpuserpwd' );

/** Database hostname */
define( 'DB_HOST', 'mariadb_cont' );

/** Database charset to use in creating database tables. */
define( 'DB_CHARSET', 'utf8' );

/** The database collate type. Don't change this if in doubt. */
define( 'DB_COLLATE', '' );

/**#@+
 * Authentication unique keys and salts.
 *
 * Change these to different unique phrases! You can generate these using
 * the {@link https://api.wordpress.org/secret-key/1.1/salt/ WordPress.org secret-key service}.
 *
 * You can change these at any point in time to invalidate all existing cookies.
 * This will force all users to have to log in again.
 *
 * @since 2.6.0
 */

define('AUTH_KEY',         '_v+qHEX_x^n:T(!u%h,DuoaLA5|dnrq1abS%Ef-E(|8z0>fCvzF}^vog &i?s|GK');
define('SECURE_AUTH_KEY',  '!>!O&-{|+s)>[7OLFZ9_rTZFc#n+Y5A8QE~3 ?wZJJOk(,~}&.Fm|9-kXX4Jjde+');
define('LOGGED_IN_KEY',    '1+Wi|]kAn+hk@ot%}X56VbZDpZQcU;l+RCU*MC`NjQn$McAHf*a;Njkj*PDx_(=e');
define('NONCE_KEY',        'u|y*~m9>IM7@Gx#qL:y-#L:.XMC1E_ho-o/s**v>=@;UPGa9]b4BO>?_X|ng+2cA');
define('AUTH_SALT',        'D)Cp<Vr0&(?(,1Ofx,6z,)p*5;62Bf0a@x(z2P5pB-iq 9VlB+MH+V1j3JZrdCn+');
define('SECURE_AUTH_SALT', 'T-CL|KuXc/1q&FQ]+I|]GwFU`&zQ`-tef(l{^]6tOU{$*yoN}X1QU?55?1#|Th|J');
define('LOGGED_IN_SALT',   'vwq<xFU[EWxV$.h(J-|tj|VIORytBzp/B,ta`|FLB=nqb,}9--NW7}P(9V>-?+bh');
define('NONCE_SALT',       ',o0901[I)]qUlmM3TY_Fby4qNrt+@^}H#frw6gZm1*5LJFh@f`ffeh]l|%pp6[^%');


/**#@-*/

/**
 * WordPress database table prefix.
 *
 * You can have multiple installations in one database if you give each
 * a unique prefix. Only numbers, letters, and underscores please!
 */
$table_prefix = 'wp_';

/**
 * For developers: WordPress debugging mode.
 *
 * Change this to true to enable the display of notices during development.
 * It is strongly recommended that plugin and theme developers use WP_DEBUG
 * in their development environments.
 *
 * For information on other constants that can be used for debugging,
 * visit the documentation.
 *
 * @link https://wordpress.org/support/article/debugging-in-wordpress/
 */
define( 'WP_DEBUG', false );

/* Add any custom values between this line and the "stop editing" line. */



/* That's all, stop editing! Happy publishing. */

/** Absolute path to the WordPress directory. */
if ( ! defined( 'ABSPATH' ) ) {
	define( 'ABSPATH', __DIR__ . '/' );
}

/** Sets up WordPress vars and included files. */
require_once ABSPATH . 'wp-settings.php';
