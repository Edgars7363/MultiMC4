/*
    Copyright 2012 <copyright holder> <email>

    Licensed under the Apache License, Version 2.0 (the "License");
    you may not use this file except in compliance with the License.
    You may obtain a copy of the License at

        http://www.apache.org/licenses/LICENSE-2.0

    Unless required by applicable law or agreed to in writing, software
    distributed under the License is distributed on an "AS IS" BASIS,
    WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
    See the License for the specific language governing permissions and
    limitations under the License.
*/

#pragma once

#include "task.h"
#include <logindialog.h>

#include <wx/wx.h>

struct LoginInfo
{
	LoginInfo(wxString loginResponse = wxEmptyString);
	
	wxString username;
	wxString sessionID;
	wxString downloadTicket;
	wxString latestVersion;
};

class LoginTask : public Task
{
public:
	LoginTask(UserInfo& uInfo);
	
	boost::signal<void (Task*, LoginInfo)> OnLoginComplete;
	
protected:
	virtual void TaskStart();
	
	UserInfo m_userInfo;
};
