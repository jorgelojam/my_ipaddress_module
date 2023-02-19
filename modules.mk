mod_my_ipaddress_module.la: mod_my_ipaddress_module.slo
	$(SH_LINK) -rpath $(libexecdir) -module -avoid-version  mod_my_ipaddress_module.lo
DISTCLEAN_TARGETS = modules.mk
shared =  mod_my_ipaddress_module.la
