TC_03_enter_computer_details()
{
lr_start_transaction("TC_03_enter_computer_details");
	randomDay = rand() % 28 + 1; 
	randomMonth = rand() % 12 + 1; 
    randomYear = rand() % 10 + 2023; 
   
    lr_param_sprintf("p_introduced",  "%04d-%02d-%02d", randomYear-1, randomMonth-1,randomDay-1);
    lr_param_sprintf("p_discontinued",  "%04d-%02d-%02d", randomYear, randomMonth, randomDay);
	
	web_add_header("Accept-Language", 
		"en-US,en;q=0.5");

	web_reg_find("Fail=NotFound",
		"Search=Body",
		"Text=Done ! ",
		LAST);

	web_submit_data("381_4", 
		"Action={scheme}://{baseurl}/{P_computer_id}", 
		"Method=POST", 
		"RecContentType=text/html", 
		"Referer={scheme}://{baseurl}/{P_computer_id}", 
		"Snapshot=t8.inf", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name=name", "Value={C_computer_name}", ENDITEM, 
		"Name=introduced", "Value={p_introduced}", ENDITEM, 
		"Name=discontinued", "Value={p_discontinued}", ENDITEM, 
		"Name=company", "Value={P_company_name}", ENDITEM, 
		LAST);

lr_end_transaction("TC_03_enter_computer_details", LR_AUTO);

	lr_think_time(think_time);
	return 0;
}
