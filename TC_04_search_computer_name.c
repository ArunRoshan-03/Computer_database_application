TC_04_search_computer_name()
{
lr_start_transaction("TC_04_search_computer_name");

	web_add_header("Accept-Language", 
		"en-US,en;q=0.5");

	web_url("computers_4", 
		"URL={scheme}://{baseurl}?f={C_computer_name}", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer={scheme}://{baseurl}", 
		"Snapshot=t9.inf", 
		"Mode=HTML", 
		LAST);
lr_end_transaction("TC_04_search_computer_name", LR_AUTO);

	lr_think_time(think_time);
	return 0;
}