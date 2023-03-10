/* 
**  mod_my_ipaddress_module.c -- Apache sample my_ipaddress_module module
**  [Autogenerated via ``apxs -n my_ipaddress_module -g'']
**
**  To play with this sample module first compile it into a
**  DSO file and install it into Apache's modules directory 
**  by running:
**
**    $ apxs -c -i mod_my_ipaddress_module.c
**
**  Then activate it in Apache's httpd.conf file for instance
**  for the URL /my_ipaddress_module in as follows:
**
**    #   httpd.conf
**    LoadModule my_ipaddress_module_module modules/mod_my_ipaddress_module.so
**    <Location /my_ipaddress_module>
**    SetHandler my_ipaddress_module
**    </Location>
**
**  Then after restarting Apache via
**
**    $ apachectl restart
**
**  you immediately can request the URL /my_ipaddress_module and watch for the
**  output of this module. This can be achieved for instance via:
**
**    $ lynx -mime_header http://localhost/my_ipaddress_module 
**
**  The output should be similar to the following one:
**
**    HTTP/1.1 200 OK
**    Date: Tue, 31 Mar 1998 14:42:22 GMT
**    Server: Apache/1.3.4 (Unix)
**    Connection: close
**    Content-Type: text/html
**  
**    The sample page from mod_my_ipaddress_module.c
*/ 

#include "httpd.h"
#include "http_config.h"
#include "http_protocol.h"
#include "ap_config.h"

/* The sample content handler */
static int my_ipaddress_module_handler(request_rec *r)
{
    if (strcmp(r->handler, "my_ipaddress_module")) {
        return DECLINED;
    }
    r->content_type = "text/plain";      

    if (!r->header_only) {
        /* Conseguir la IP remota del cliente */
	ap_rprintf(r, "%s", r->useragent_ip);
    }
    return OK;
}

static void my_ipaddress_module_register_hooks(apr_pool_t *p)
{
    ap_hook_handler(my_ipaddress_module_handler, NULL, NULL, APR_HOOK_MIDDLE);
}

/* Dispatch list for API hooks */
module AP_MODULE_DECLARE_DATA my_ipaddress_module_module = {
    STANDARD20_MODULE_STUFF, 
    NULL,                  /* create per-dir    config structures */
    NULL,                  /* merge  per-dir    config structures */
    NULL,                  /* create per-server config structures */
    NULL,                  /* merge  per-server config structures */
    NULL,                  /* table of config file commands       */
    my_ipaddress_module_register_hooks  /* register hooks                      */
};

