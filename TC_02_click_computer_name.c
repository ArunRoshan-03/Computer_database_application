TC_02_click_computer_name()
{
lr_start_transaction("TC_02_click_computer_name");

	web_add_header("Accept-Language", 
		"en-US,en;q=0.5");

	web_reg_save_param_regexp(
		"ParamName=C_computer_name",
		"RegExp=<input type=\"text\" id=\"name\" name=\"name\" value=\"(.*?)\" />",
		SEARCH_FILTERS,
		LAST);

	web_reg_save_param_regexp(
		"ParamName=C_company_name",
		"RegExp=<option value=\"(.*?)\">",
		"Ordinal=All",
		SEARCH_FILTERS,
		LAST);

	web_url("381_3", 
		"URL={scheme}://{baseurl}/{P_computer_id}", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer={scheme}://{baseurl}", 
		"Snapshot=t7.inf", 
		"Mode=HTML", 
		LAST);
		
		random_company_name=lr_paramarr_random("C_company_name");
		lr_param_sprintf("P_company_name","%s",random_company_name);

lr_end_transaction("TC_02_click_computer_name", LR_AUTO);

lr_think_time(think_time);
	return 0;
}
