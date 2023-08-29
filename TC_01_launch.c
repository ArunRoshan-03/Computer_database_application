TC_01_launch()
{
lr_start_transaction("TC_01_launch");

	web_set_sockets_option("SSL_VERSION", "AUTO");

	web_add_header("Accept-Language", 
		"en-US,en;q=0.5");

	web_reg_save_param_regexp(
		"ParamName=C_computer_id",
		"RegExp=<a href=\"/computers/(.*?)\">",
		"Ordinal=All",
		SEARCH_FILTERS,
		"Scope=BODY",
		LAST);
	
	web_reg_find("Fail=NotFound",
		"Search=Body",
		"Text=Computers database",
		LAST);

	web_url("computer-database.gatling.io", 
		"URL={scheme}://computer-database.gatling.io/", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=", 
		"Snapshot=t6.inf", 
		"Mode=HTML", 
		LAST);
		random_computer_id=lr_paramarr_random("C_computer_id");
		lr_param_sprintf("P_computer_id","%s",random_computer_id);
		
lr_end_transaction("TC_01_launch", LR_AUTO);

lr_think_time(think_time);
	return 0;
}
