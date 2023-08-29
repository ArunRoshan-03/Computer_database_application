TC_06_click_on_cancel()
{
lr_start_transaction("TC_06_click_on_cancel");

	web_add_header("Accept-Language", 
		"en-US,en;q=0.5");

	web_url("computers_5", 
		"URL={scheme}://{baseurl}", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer={scheme}://{baseurl}/{P_computer_id}", 
		"Snapshot=t11.inf", 
		"Mode=HTML", 
		LAST);
lr_end_transaction("TC_06_click_on_cancel", LR_AUTO);

	lr_think_time(think_time);
	return 0;
}