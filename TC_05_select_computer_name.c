TC_05_select_computer_name()
{
lr_start_transaction("TC_05_select_computer_name");

	web_add_header("Accept-Language", 
		"en-US,en;q=0.5");
		
	web_reg_find("Fail=NotFound",
		"Search=Body",
		"Text=Edit computer",
		LAST);

	web_url("381_5", 
		"URL={scheme}://{baseurl}/{P_computer_id}", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer={scheme}://{baseurl}?f={C_computer_name}", 
		"Snapshot=t10.inf", 
		"Mode=HTML", 
		LAST);

lr_end_transaction("TC_05_select_computer_name", LR_AUTO);

	lr_think_time(think_time);
	return 0;
}
